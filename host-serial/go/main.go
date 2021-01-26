package main

import (
	"flag"
	"log"
	"os"
)

func usage() {
	os.Exit(1)
}

func main() {

	var port string
	var update int
	var setZero bool
	var setFull bool
	flag.StringVar(&port, "p", "", "serial port")
	flag.IntVar(&update, "u", 250, "update time")
	flag.BoolVar(&setZero, "z", false, "set zero")
	flag.BoolVar(&setFull, "f", false, "set fullscale")
	flag.Parse()

	if port == "" {
		flag.PrintDefaults()
		os.Exit(1)
	}

	an, err := NewAnalogMeter(port, update)
	if err != nil {
		log.Fatal(err)
	}

	if setZero {
		an.SendValue(0x00)
		return
	}

	if setFull {
		an.SendValue(0xFF)
		return
	}

	for {
		an.SendCPU()
	}

}
