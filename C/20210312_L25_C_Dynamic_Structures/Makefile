CC=gcc
COMPILE=$(CC) -g
CFILES=$(find *.c*)#ll.c llmain.c
OBJECT=$(CFILES:.c=.o)
TARGET=list
$(TARGET):$(OBJECT)
	$(COMPILE) -o $@ $(OBJECT)
.c:.o
	$(COMPILE) -c $< -o $@
clean:
	del $(TARGET).exe $(OBJECT)