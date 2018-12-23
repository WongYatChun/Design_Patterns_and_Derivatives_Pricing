CC = g++
TARGET = main_stat1 main_stat2
.PHONY: clean

# $@ = Target
# $? : check if dependencies are up-to-date
# $< : the first prerequisite (usually the source file)
# $%: The filename element of an archive member specification.
# $? : The names of all prerequisites that are newer than the target,

objs_stat1 = StatsMain1.o MCStatistics.o Parameters.o PayOff3.o PayOffBridge.o Random1.o SimpleMC7.o Vanilla3.o
objs_stat2 = StatsMain2.o MCStatistics.o Parameters.o PayOff3.o PayOffBridge.o Random1.o SimpleMC7.o Vanilla3.o ConvergenceTable.o

main_stat1: $(objs_stat1)
	$(CC) -o $@ $?

main_stat2: $(objs_stat2)
	$(CC) -o $@ $?


%.o : %.c
	$(CC) -c $< -o $@

## clean
clean:
	rm -f *.o *.out $(TARGET)

