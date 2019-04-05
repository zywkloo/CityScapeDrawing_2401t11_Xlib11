

# I/O tutotrial makefile
#
DIR_src = myLib/src/
DIR_lib = myLib/lib/
DIR_lib = myLib/include/

All: Permit lib
 
Permit: getPermit.c
	gcc -o getPermit getPermit.c
lib: 
	gcc -c  $(DIR_src)studentList.o $(DIR_src)studentList.c -I $(DIR_lib)
	ls $(DIR_src)
	ar rs $(DIR_src)libstudentList.a $(DIR_src)studentList.o
	ls $(DIR_src)
	mv -WALL $(DIR_src)libstudentList.a $(DIR_lib)
	rm $(DIR_src)libstudentList.o
	ls $(DIR_src)
	cd $(DIR_lib);ls 

delete: 
	rm *.o getPermit


