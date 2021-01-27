package main

import (
	"context"
	"io"
	"log"
	"math"
	"time"

	"github.com/jacobsa/go-serial/serial"
	"github.com/shirou/gopsutil/cpu"
)

type AnalogMeter struct {
	SerialPort io.ReadWriteCloser
	updateMs   int
}

func NewAnalogMeter(portName string, updateMs int) (t *AnalogMeter, err error) {
	t = new(AnalogMeter)

	c := serial.OpenOptions{
		PortName:        portName,
		BaudRate:        115200,
		DataBits:        8,
		StopBits:        1,
		MinimumReadSize: 4,
	}
	p, err := serial.Open(c)
	if err != nil {
		return nil, err
	}
	t.SerialPort = p
	t.updateMs = updateMs
	return t, nil
}

func (t *AnalogMeter) Close() {
	t.SerialPort.Close()
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
