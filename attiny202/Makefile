# 動作デバイス ( リスト: avr-as -mlist-devices )
DEVICE := attiny202

# 動作クロック
CLOCK := 20000000
# CLOCK := 3333333

# プログラマ
PROGRAMMER := -c serialupdi -P /dev/cu.usbserial-12440
SERIAL_PORT := /dev/cu.usbserial-12430

# ------------------------------------

HDRS    := $(shell find . -type f -name '*.h')
SRCC    := $(shell find . -type f -name '*.c')
SRCA    := $(shell find . -type f -name '*.S')
OBJS    := $(SRCC:%.c=%.o) $(SRCA:%.S=%.o)
DEPS    := $(OBJS:%.o=%.d)
AVRDUDE := avrdude $(PROGRAMMER) -p $(DEVICE) 

COMPILE := avr-gcc -x c -funsigned-char -funsigned-bitfields -DDEBUG \
	-mmcu=$(DEVICE) -B $(AVR_DFP)/gcc/dev/$(DEVICE) -I $(AVR_DFP)/include -DF_CPU=$(CLOCK) \
	-Wall -std=gnu99 -I . -MD -MP \
	-O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall

ELF := avr-gcc \
	-mmcu=$(DEVICE) -B $(AVR_DFP)/gcc/dev/$(DEVICE) -I $(AVR_DFP)/include -DF_CPU=$(CLOCK) \
	-Wall -Wl,-Map="main.map" -Wl,--start-group -Wl,-lm -Wl,--end-group -Wl,--gc-sections


all:	main.hex

serial:
	screen $(SERIAL_PORT) 115200

-include $(DEPS)

%.o: %.c
	$(COMPILE) -c -MMD -MP $<

.c.o:
	$(COMPILE) -c $< -o $@

.S.o:
	$(COMPILE) -x assembler-with-cpp -c $< -o $@

.c.s:
	$(COMPILE) -S $< -o $@

flash:	all
	$(AVRDUDE) -U flash:w:main.hex:i

install: flash

load: all
	bootloadHID main.hex

clean:
	rm -f main.map main.hex main.elf $(OBJS) $(OBJS:.o=.d)

main.elf: $(OBJS) $(HDRS)
	$(ELF) -o main.elf $(OBJS)

main.hex: main.elf
	rm -f main.hex
	avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures -O ihex main.elf main.hex
	avr-size --format=SysV --mcu=$(DEVICE) main.elf

disasm:	main.elf
	avr-objdump -d main.elf
cpp:
	$(COMPILE) -E main.c

