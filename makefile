FQBN=arduino:avr:nano
PORT=/dev/ttyUSB0
OPTS=-b $(FQBN) -p $(PORT)
con: c_comp c_up

c_comp:
	arduino-cli compile controller/controller.ino $(OPTS)

c_up:
	arduino-cli upload controller/controller.ino $(OPTS)

app:
	python application/app.py $(PORT)
