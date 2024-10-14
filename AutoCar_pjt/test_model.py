from pop import Pilot

cam = Pilot.Camera(width=300, height=300)

CA=Pilot.Collision_Avoid(cam)

CA.load_model(path="Project/python/notebook/models/collision_avoid_model.pth")

bot=Pilot.AutoCar()

# bot.setSpeed(50)


def drive(value):
    if value <= 0.5:
        bot.steering=0
        bot.forward(50)
    else:
        bot.stop()

while True:
    CA.run(callback=drive)