# 조이패드 값을 AutoCar에게 알맞는 값으로 선형변환 하는 메서드들

# 속도 값 변환
def cal_speed(value, joypad_min_value=-1.0, joypad_max_value=1.0, Autocar_min_speed=0, Autocar_max_speed=99):
    value = round(value, 1)
    return ((value - joypad_min_value) / (joypad_max_value - joypad_min_value)) * (Autocar_max_speed - Autocar_min_speed) + Autocar_min_speed

# 조향 값 변환
def cal_steer(value):
    return round(value, 1)

# 카메라 좌우각도 변환
def cal_pan(value, joypad_min_value=-1.0, joypad_max_value=1.0, Autocar_min_pan=0, Autocar_max_pan=180):
    value = round(value, 1)
    return ((value - joypad_min_value) / (joypad_max_value - joypad_min_value)) * (Autocar_max_pan - Autocar_min_pan) + Autocar_min_pan

# 카메라 상하각도 변환
def cal_tilt(value, joypad_min_value=-1.0, joypad_max_value=1.0, Autocar_min_tilt=-30, Autocar_max_tilt=90):
    value = round(value, 1)
    return ((value - joypad_min_value) / (joypad_max_value - joypad_min_value)) * (Autocar_max_tilt - Autocar_min_tilt) + Autocar_min_tilt