#!/bin/sh -xe

set -e

arduino-cli compile --fqbn aceduino:avr:m168xt4m AceBMS

arduino-cli upload -p /dev/ttyUSB0 --fqbn aceduino:avr:m168xt4m AceBMS
