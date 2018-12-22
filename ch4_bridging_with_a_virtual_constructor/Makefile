CC = g++
TARGET = main_vanilla1 main_vanilla2 main_vanilla4
.PHONY: clean

# $@ = Target
# $? : check if dependencies are up-to-date
# $< : the first prerequisite (usually the source file)
# $%: The filename element of an archive member specification.
# $? : The names of all prerequisites that are newer than the target,

objs_vanilla1 = VanillaMain1.o DoubleDigital.o PayOff2.o Random1.o SimpleMC3.o Vanilla1.o
objs_vanilla2 = VanillaMain2.o PayOff3.o Random1.o SimpleMC4.o Vanilla2.o
objs_vanilla4 = VanillaMain4.o PayOff3.o Random1.o SimpleMC6.o Vanilla3.o Parameters.o PayOffBridge.o

main_vanilla1: $(objs_vanilla1)
	$(CC) -o $@ $?

main_vanilla2: $(objs_vanilla2)
	$(CC) -o $@ $?

main_vanilla4: $(objs_vanilla4)
	$(CC) -o $@ $?


%.o : %.c
	$(CC) -c $< -o $@

## clean
clean:
	rm -f *.o *.out $(TARGET)

