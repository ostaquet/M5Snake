define USAGE
Build system for the M5Snake ⚙️

Commands:
	init      Install Arduino dependencies with arduino-cli
	deploy    Compile and upload the application on the device defined in sketch.json
endef

export USAGE
help:
	@echo "$$USAGE"

init:
	arduino-cli core install esp32:esp32 && arduino-cli lib install M5Stack

deploy:
	arduino-cli compile && arduino-cli upload
