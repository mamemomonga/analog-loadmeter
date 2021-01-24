#ifndef _SERIAL_H_
#define _SERIAL_H_

#define BAUD_RATE B115200

int set_interface_attribs (int fd, int speed, int parity);
void set_blocking (int fd, int should_block);

#endif
