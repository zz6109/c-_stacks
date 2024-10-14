from pop import Pilot

cam = Pilot.Camera(width=300, height=300)

CA=Pilot.Collision_Avoid(cam)
CA.load_datasets()

CA.train(times=10)

CA.show()

bot=Pilot.serBot()

bot.setSpeed(50)

def drive(value):
    if value <= 0.5:
        bot.steering=0
        bot.forward()
    else:
        bot.steering=1
        bot.backward()

while True:
    CA.run(callback=drive)