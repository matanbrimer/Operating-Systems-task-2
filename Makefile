FLAGS = -Wall -g
CC = gcc


all: stshell cmp copy codecB.so codecA.so encode decode 



stshell.o: stshell.c 
	$(CC) $(FLAGS) -c stshell.c 

stshell: stshell.o
	$(CC) $(FLAGS) -o stshell stshell.o

cmp.o: cmp.c 
	$(CC) $(FLAGS) -c cmp.c 

copy.o: copy.c 
	$(CC) $(FLAGS) -c copy.c 

cmp: cmp.o
	$(CC) $(FLAGS) -o cmp cmp.o

copy: copy.o
	$(CC) $(FLAGS) -o copy copy.o

codecB.o: codecB.c mylibrary.h
	${CC} -fPIC ${FLAGS} -c codecB.c 

codecA.o: codecA.c mylibrary.h
	${CC} -fPIC ${FLAGS} -c codecA.c 


codecA.so: codecA.o 
	$(CC) $(FLAGS) -shared codecA.o -o codecA.so

codecB.so: codecB.o
	$(CC) $(FLAGS) -shared codecB.o -o codecB.so	

encode.o: encode.c 
	$(CC) $(FLAGS) -c encode.c 

encode: encode.o
	$(CC) $(FLAGS) -o encode encode.o

decode.o: decode.c 
	$(CC) $(FLAGS) -c decode.c 

decode: decode.o
	$(CC) $(FLAGS) -o decode decode.o

.PHONEY: clean
clean:
	rm -f *.o *.a *.so stshell shell cmp copy decode encode