import os
import subprocess

# ping을 할 IP 주소의 범위 설정
network_prefix = "192.168.13."
start_ip = 40
end_ip = 253

# 연결된 IP 주소를 저장할 리스트
connected_ips = []

# IP 주소 범위 내에서 ping을 수행
for i in range(start_ip, end_ip + 1):
    ip_address = f"{network_prefix}{i}"
    try:
        # Windows의 경우 'ping -n 1', Linux의 경우 'ping -c 1'
        response = subprocess.run(['ping', '-c', '1', '-W', '1', ip_address],
                                  stdout=subprocess.DEVNULL)
        if response.returncode == 0:
            print(f"Ping 성공: {ip_address}")
            connected_ips.append(ip_address)
    except Exception as e:
        print(f"Error pinging {ip_address}: {e}")

# 결과 출력
print("\n연결된 IP 주소 목록:")
for ip in connected_ips:
    print(ip)
