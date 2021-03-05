TARGET=digits_of_a_number.a
TARGET1=random_number_with_range.a
TARGET2=strrev.a 
TARGET3=swap_macro.a 
CFILE=digits_of_a_number.c
CFILE1=random_number_with_range.c 
CFILE2=strrev.c
CFILE3=swap_macro.c 
LIBTOOL=libtool
LFLAGS= --mode=compile gcc -g -O -c 


all:
	$(LIBTOOL) $(LFLAGS) $(CFILE) 
	$(LIBTOOL) $(LFLAGS) $(CFILE1) 
	$(LIBTOOL) $(LFLAGS) $(CFILE2) 
	$(LIBTOOL) $(LFLAGS) $(CFILE3)  

clean:
	rm -f *.o *.a *.gch