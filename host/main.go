package main

import (
	"flag"
	"log"
	"os"
	"time"
	"fmt"
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
	var showVersion bool

	flag.StringVar(&port, "p", "", "serial port")
	flag.IntVar(&update, "u", 250, "update time")
	flag.BoolVar(&setZero, "z", false, "set zero")
	flag.BoolVar(&setFull, "f", false, "set fullscale")
	flag.BoolVar(&showVersion, "v", false, "version")
	flag.StringVar(&segChar, "7", "", "7seg char")
	flag.Parse()

	if showVersion {
		fmt.Printf("cpuload-analogmater version %s\n",Version);
		os.Exit(1);
	}

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
		for i:=0; i<3;i++ {
			an.SendValue(CmdCPULoad, 0x00)
			time.Sleep(time.Millisecond * 100)
		}
		return;
	}

	if setFull {
		for i:=0; i<3;i++ {
			an.SendValue(CmdCPULoad, 0xFF)
			time.Sleep(time.Millisecond * 100)
		}
		return;
	}

	if segChar != "" {
		an.SendValue(CmdSegChar, segChar[0])
		return
	}

	for {
		an.SendCPULoad()
	}

}
