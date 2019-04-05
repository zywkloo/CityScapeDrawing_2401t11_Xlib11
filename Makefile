

# I/O tutotrial makefile
#
DIR_src = myLib/src/
DIR_lib = myLib/lib/
DIR_include = myLib/include/

All: Permit lib
 
Permit: getPermit.c
	gcc -o getPermit getPermit.c
lib: 
	gcc -c  $(DIR_src)studentList.c -I $(DIR_include)
	mv  studentList.o $(DIR_src)
	ls $(DIR_src)
	ar rs $(DIR_src)libstudentList.a $(DIR_src)studentList.o
	ls $(DIR_src)
	mv $(DIR_src)libstudentList.a $(DIR_lib)
	rm $(DIR_src)*.o
	ls $(DIR_src)
	cd $(DIR_lib);ls 

clean: 
	rm getPermit
	find .-name "*.o" | xargs rm
	find .-name "*.a" | xargs rm



