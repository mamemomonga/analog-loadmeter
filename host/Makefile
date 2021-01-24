
APPS    := sender reciever
HDRS    := $(shell find . -type f -name '*.h')
SRCC    := $(shell find . -type f -name '*.c')
OBJS    := sender.o

COMPILE := gcc -std=gnu99

all: $(APPS)

sender: $(OBJS)
	$(COMPILE) -o $(OBJS) -o $@ sender.c

reciever: $(OBJS)
	$(COMPILE) -o $(OBJS) -o $@ reciever.c

%.o: %.c
	$(COMPILE) -c -MMD -MP $<

clean:
	rm -rf *.o *.d $(APPS)
