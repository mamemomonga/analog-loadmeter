#!/bin/bash
set -xe

while true; do
	./sender /dev/cu.usbserial-1 1 0
	sleep 5
	./sender /dev/cu.usbserial-1 1 10
	sleep 1
	./sender /dev/cu.usbserial-1 1 50
	sleep 1
	./sender /dev/cu.usbserial-1 1 100
	sleep 1
	./sender /dev/cu.usbserial-1 1 150
	sleep 1
	./sender /dev/cu.usbserial-1 1 200
	sleep 1
	./sender /dev/cu.usbserial-1 1 254
	sleep 3
done


