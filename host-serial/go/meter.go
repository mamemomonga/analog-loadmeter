package main

import (
	"context"
	"log"
	"math"
	"time"

	"github.com/shirou/gopsutil/cpu"
	"github.com/tarm/serial"
)

type AnalogMeter struct {
	SerialPort *serial.Port
	updateMs   int
}

func NewAnalogMeter(serialDev string, updateMs int) (t *AnalogMeter, err error) {
	t = new(AnalogMeter)
	c := &serial.Config{Name: "/dev/cu.usbserial-1002", Baud: 115200}
	s, err := serial.OpenPort(c)
	if err != nil {
		return nil, err
	}
	t.SerialPort = s
	t.updateMs = updateMs
	return t, nil
}

func (t *AnalogMeter) SendValue(n byte) {
	_, err := t.SerialPort.Write([]byte{1, n})
	if err != nil {
		log.Fatal(err)
	}
}

func (t *AnalogMeter) SendCPU() {
	ctx := context.Background()
	cpuPercent, err := cpu.PercentWithContext(ctx, time.Millisecond*time.Duration(t.updateMs), false)
	if err != nil {
		log.Fatal(err)
	}
	t.SendValue(byte(math.Floor(255 * (cpuPercent[0] / 100))))
}
