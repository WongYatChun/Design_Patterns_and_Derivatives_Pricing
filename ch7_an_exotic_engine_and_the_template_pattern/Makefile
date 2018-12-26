CC = g++
TARGET = main_rand1
.PHONY: clean

# $@ = Target
# $? : check if dependencies are up-to-date
# $< : the first prerequisite (usually the source file)
# $%: The filename element of an archive member specification.
# $? : The names of all prerequisites that are newer than the target,

objs_rand1 = EquityFXMain.o \
			 AntiThetic.o Arrays.o \
			 ConvergenceTable.o \
			 ExoticBSEngine.o ExoticEngine.o \
			 MCStatistics.o \
			 Normals.o \
			 Parameters.o ParkMiller.o PathDependent.o PathDependentAsian.o PayOff3.o PayOffBridge.o \
			 Random2.o 



main_rand1: $(objs_rand1)
	$(CC) -o $@ $?

%.o : %.c
	$(CC) -c $< -o $@

## clean
clean: 
	rm -f *.o *.out $(TARGET)

