/*
 * GNU GPL v3
 *
 * This file is part of the code entitled, "cryptosuite" available at
 * https://code.google.com/p/cryptosuite/. The file was copied from that
 * repository and renamed for use in Connector/Arduino to preserve
 * compatibility and protect against namespace collisions for users who
 * want to use the full cryptosuite functionality. For Connector/Arduino
 * all that is needed is this one sha256 class.
 *
 * Note: #defines renamed to prevent collisions
 */
#include <string.h>
#include "MySQL_Encrypt_Sha256.h"

#define MYSQL_SHA256_K { \
  0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, \
  0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5, \
  0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, \
  0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174, \
  0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, \
  0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da, \
  0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, \
  0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967, \
  0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, \
  0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, \
  0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, \
  0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070, \
  0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, \
  0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3, \
  0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, \
  0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2 \
}

const uint32_t sha256InitState[] PROGMEM = {
  0x6a09e667, // H0
  0xbb67ae85, // H1
  0x3c6ef372, // H2
  0xa54ff53a, // H3
  0x510e527f, // H4
  0x9b05688c, // H5
  0x1f83d9ab, // H6
  0x5be0cd19  // H7
};

void Encrypt_SHA256::init(void) {
  memcpy_P(state.w, sha256InitState, HASH_LENGTH);
  byteCount = 0;
  bufferOffset = 0;
}

uint32_t Encrypt_SHA256::rol32(uint32_t number, uint8_t bits) {
  return ((number << bits) | (number >> (32 - bits)));
}

uint32_t Encrypt_SHA256::ror32(uint32_t number, uint8_t bits) {
  return ((number >> bits) | (number << (32 - bits)));
}

void Encrypt_SHA256::hashBlock() {
  uint32_t a, b, c, d, e, f, g, h, t1, t2;
  uint32_t K[] = MYSQL_SHA256_K;
  uint32_t w[64];

  for (uint8_t i = 0; i < 16; i++) {
    w[i] = buffer.w[i];
  }
  for (uint8_t i = 16; i < 64; i++) {
    w[i] = w[i - 16] + (ror32(w[i - 15], 7) ^ ror32(w[i - 15], 18) ^ (w[i - 15] >> 3))
           + w[i - 7] + (ror32(w[i - 2], 17) ^ ror32(w[i - 2], 19) ^ (w[i - 2] >> 10));
  }

  a = state.w[0];
  b = state.w[1];
  c = state.w[2];
  d = state.w[3];
  e = state.w[4];
  f = state.w[5];
  g = state.w[6];
  h = state.w[7];

  for (uint8_t i = 0; i < 64; i++) {
    t1 = h + (ror32(e, 6) ^ ror32(e, 11) ^ ror32(e, 25)) + ((e & f) ^ (~e & g)) + K[i] + w[i];
    t2 = (ror32(a, 2) ^ ror32(a, 13) ^ ror32(a, 22)) + ((a & b) ^ (a & c) ^ (b & c));
    h = g;
    g = f;
    f = e;
    e = d + t1;
    d = c;
    c = b;
    b = a;
    a = t1 + t2;
  }

  state.w[0] += a;
  state.w[1] += b;
  state.w[2] += c;
  state.w[3] += d;
  state.w[4] += e;
  state.w[5] += f;
  state.w[6] += g;
  state.w[7] += h;
}

void Encrypt_SHA256::addUncounted(uint8_t data) {
  buffer.b[bufferOffset ^ 3] = data;
  bufferOffset++;
  if (bufferOffset == BLOCK_LENGTH) {
    hashBlock();
    bufferOffset = 0;
  }
}

size_t Encrypt_SHA256::write(uint8_t data) {
  ++byteCount;
  addUncounted(data);
  return 1;
}

size_t Encrypt_SHA256::write(uint8_t* data, int length) {
  for (int i = 0; i < length; i++) {
    write(data[i]);
  }
  return length;
}

void Encrypt_SHA256::pad() {
  addUncounted(0x80);
  while (bufferOffset != 56) addUncounted(0x00);

  addUncounted(byteCount >> 53);
  addUncounted(byteCount >> 45);
  addUncounted(byteCount >> 37);
  addUncounted(byteCount >> 29);
  addUncounted(byteCount >> 21);
  addUncounted(byteCount >> 13);
  addUncounted(byteCount >> 5);
  addUncounted(byteCount << 3);
}

uint8_t* Encrypt_SHA256::result(void) {
  pad();
  for (int i = 0; i < 8; i++) {
    uint32_t a, b;
    a = state.w[i];
    b = a << 24;
    b |= (a << 8) & 0x00ff0000;
    b |= (a >> 8) & 0x0000ff00;
    b |= a >> 24;
    state.w[i] = b;
  }
  return state.b;
}

#define HMAC_IPAD 0x36
#define HMAC_OPAD 0x5c

Encrypt_SHA256 Sha256;
