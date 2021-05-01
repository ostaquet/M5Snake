# M5Snake
Simple snake game for M5Stack Core with Gameboy face

The goal is to eat the cherries (red dot) with the snake while avoiding eating himself and running into a wall.

![Demo](extras/img/m5snake_demo.gif)

## Requirements
Software requirements:
* **arduino-cli** : For package management, compile and upload ([URL](https://github.com/arduino/arduino-cli))
* **GNU Make** : For build management

Hardware compatibility:
* M5Stack Core (version 1)
* M5Stack Faces kit (Gameboy face)

To ensure compatibility, `sketch.json` should be adapted with the link to your serial.

## Project organization
All sources are available in `src/`.

* `src/M5Stack` is a C++ program for M5Stack Core equipped with the Gameboy face.

Nothing else specific to notify.

## To build and upload
* Go into `src/M5Snake`
* Execute `make deploy`

## Troubleshooting

### Missing libraries during the build
Just do `make init` to install required libraries and boards.

### Upload doesn't work

Typical error:
```
No new serial port detected.
No device found on cu.usbserial-01CDDC5A
```
The ports connected can be listed by the command `arduino-cli board list`.

The file `src/M5Snake/sketch.json` defines how **arduino-cli** behave. The `port` should be adjusted based on your configuration.
