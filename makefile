BINARIES=prog2.out

all: prog2.out

prog2.out: heap.cpp prog2.cpp
	clang++ heap.cpp prog2.cpp -o prog2.out

clean:
	/bin/rm -f ${BINARIES} *.o
