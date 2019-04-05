

# 2401 t11
#
DIR_src = myLib/src/
DIR_lib = myLib/lib/
DIR_include = myLib/include/

All: clean permit lib city
 
permit: getPermit.c
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

uselib:
	gcc -c useStudentList.c -I myLib/include
	gcc -o useStudentList useStudentList.o -L./myLib/lib -lstudentList
	ls
	./useStudentList <in.txt

city: 
	gcc -o city drawBuilding.c -lm -I/opt/X11/include  -L/opt/X11/lib -lX11

clean: 
	find . -name "city" | xargs rm -v
	find . -name "getPermit" | xargs rm -v
	find . -name "*.o" | xargs rm -v
	find . -name "*.a" | xargs rm -v



