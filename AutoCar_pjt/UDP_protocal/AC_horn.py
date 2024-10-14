import numpy as np
import sounddevice as sd
import time

# 기본 파라미터
sample_rate = 44100  # 샘플링 주파수 (44.1kHz)
duration = 0.3  # 소리 지속 시간 (1초)

def generate_tone(frequency, duration, amplitude=0.5, sample_rate=44100):
    t = np.linspace(0, duration, int(sample_rate * duration), False)
    tone = amplitude * np.sin(2 * np.pi * frequency * t)
    return tone


# 진폭을 더 키운 소리 생성 (음량을 키움)
# 0.5보다 큰 값으로 음량을 키움

# F4 음을 키운 소리로 재생
chime_loud_tone = generate_tone(508.57, duration, amplitude=100)

warning_horn_tone = generate_tone(640.58, duration, amplitude=0.5)
# test_loud_tone = generate_tone(508.57, 0.3, amplitude=100)

def chime_horn():
    sd.play(chime_loud_tone, sample_rate)
    sd.wait()

def warning_horn():
    for i in range(3):
        sd.play(warning_horn_tone, sample_rate)
        sd.wait()
        time.sleep(0.5)