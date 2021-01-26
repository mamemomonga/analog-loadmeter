#include "sender.h"
#include "serial.c"
#include <stdlib.h>

int usage(char app[]) {
	printf("USAGE: %s [PORT] [CMD] [VAL]\n",app);
	return -1;
}

int main(int argc, char *argv[]) {
	if(argc <= 3) {
		if(usage(argv[0]) != 0) return 1;
	}
	int fd = open(argv[1],O_RDWR | O_NOCTTY | O_SYNC);
	if(fd < 0) {
    	printf("Open failed: %s\n",argv[1]);
		return 1;
	}
  	// set speed to 115,200 bps, 8n1 (no parity)
	set_interface_attribs (fd, BAUD_RATE, 0);
	set_blocking (fd, 0);

	uint8_t data[2];
	data[0]=atoi(argv[2]);
	data[1]=atoi(argv[3]);
	write (fd, data, 2);
}
