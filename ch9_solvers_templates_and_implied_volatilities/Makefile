CC = g++
TARGET = main_Solve1 main_Solve2
.PHONY: clean

# $@ = Target
# $? : check if dependencies are up-to-date
# $< : the first prerequisite (usually the source file)
# $%: The filename element of an archive member specification.
# $? : The names of all prerequisites that are newer than the target,

objs_Solve1 = SolveMain1.o \
			 BlackScholesFormulas.o BSCallClass.o\
			 Normals.o \

objs_Solve2 = SolveMain2.o \
			 BlackScholesFormulas.o BSCallTwo.o\
			 Normals.o \

main_Solve1: $(objs_Solve1)
	$(CC) -o $@ $?

main_Solve2: $(objs_Solve2)
	$(CC) -o $@ $?

%.o : %.c
	$(CC) -c $< -o $@
	
## clean
clean: 
	rm -f *.o *.out $(TARGET)

