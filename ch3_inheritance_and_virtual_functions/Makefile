CC = g++
TARGET = main main_DoubleDigital
.PHONY: clean

# $@ = Target
# $? : check if dependencies are up-to-date
# $< : the first prerequisite (usually the source file)
# $%: The filename element of an archive member specification.
# $? : The names of all prerequisites that are newer than the target,

objs_vanilla := SimpleMCMain3.o PayOff2.o Random1.o SimpleMC2.o 
objs_DoubleDigital := SimpleMCMain5.o DoubleDigital.o SimpleMC2.o PayOff2.o Random1.o 

main: $(objs_vanilla)
	$(CC) -o $@ $?

main_DoubleDigital: $(objs_DoubleDigital)
	$(CC) -o $@ $?

%.o : %.c
	$(CC) -c $< -o $@

## clean
clean:
	rm -f *.o *.out $(TARGET)

