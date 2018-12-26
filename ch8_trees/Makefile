CC = g++
TARGET = main_Tree1
.PHONY: clean

# $@ = Target
# $? : check if dependencies are up-to-date
# $< : the first prerequisite (usually the source file)
# $%: The filename element of an archive member specification.
# $? : The names of all prerequisites that are newer than the target,

objs_Tree1 = TreeMain.o \
			 Arrays.o \
			 BinomialTree.o BlackScholesFormulas.o \
			 Normals.o \
			 Parameters.o PayOff3.o PayOffBridge.o PayOffForward.o\
    		 TreeAmerican.o TreeEuropean.o TreeProducts.o\
			 

main_Tree1: $(objs_Tree1)
	$(CC) -o $@ $?

%.o : %.c
	$(CC) -c $< -o $@
	
## clean
clean: 
	rm -f *.o *.out $(TARGET)

