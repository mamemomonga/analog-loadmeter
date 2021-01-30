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
	var segChar string

	flag.StringVar(&port, "p", "", "serial port")
	flag.IntVar(&update, "u", 250, "update time")
	flag.BoolVar(&setZero, "z", false, "set zero")
	flag.BoolVar(&setFull, "f", false, "set fullscale")
	flag.StringVar(&segChar, "7", "", "7seg char")
	flag.Parse()

	if port == "" {
		flag.PrintDefaults()
		os.Exit(1)
	}

	an, err := NewAnalogMeter(port, update)
	defer an.Close()
	if err != nil {
		log.Fatal(err)
	}

	if setZero {
		an.SendValue(CmdCPULoad, 0x00)
		return
	}

	if setFull {
		an.SendValue(CmdCPULoad, 0xFF)
		return
	}

	if segChar != "" {
		an.SendValue(CmdSegChar, segChar[0])
		return
	}

	for {
		an.SendCPULoad()
	}

}
