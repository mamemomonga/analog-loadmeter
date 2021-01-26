#include "reciever.h"
#include "serial.c"
#include <stdlib.h>
#include <unistd.h>

int usage(char app[]) {
	printf("USAGE: %s [PORT]\n",app);
	return -1;
}

int main(int argc, char *argv[]) {
	if(argc <= 1) {
		if(usage(argv[0]) != 0) return 1;
	}
	int fd = open(argv[1],O_RDWR | O_NOCTTY | O_SYNC);
	if(fd < 0) {
    	printf("Open failed: %s\n",argv[1]);
		return 1;
	}
	set_interface_attribs (fd, BAUD_RATE, 0);
	// set_blocking (fd, 0);

	while(1) {
		char buf[3];
		int n = read (fd, buf, sizeof buf);
		if(n > 0) {
			printf("RECV(%d): 0x%02x 0x%02x\r\n",n, buf[0],buf[1]);
		}
		usleep(500*1000);
	}

}
