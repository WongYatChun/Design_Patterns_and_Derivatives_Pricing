CC = g++
TARGET = main_Factory1
.PHONY: clean

# $@ = Target
# $? : check if dependencies are up-to-date
# $< : the first prerequisite (usually the source file)
# $%: The filename element of an archive member specification.
# $? : The names of all prerequisites that are newer than the target,

objs_Factory1 = PayFactoryMain.o \
			 	PayOff3.o PayOffBridge.o PayOffFactory.o PayOffRegistration.o
			 	

main_Factory1: $(objs_Factory1)
	$(CC) -o $@ $?

%.o : %.c
	$(CC) -c $< -o $@
	
## clean
clean: 
	rm -f *.o *.out $(TARGET)

