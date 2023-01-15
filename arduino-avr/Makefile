
SKETCH=meter
FQBN=arduino:megaavr:nona4809
PORT=/dev/cu.usbmodem124301

all: compile upload

compile:
	arduino-cli compile -b $(FQBN) $(SKETCH)

upload:
	arduino-cli upload -p $(PORT) -b $(FQBN) $(SKETCH)


