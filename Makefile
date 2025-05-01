main.o: main.cpp
	g++ -Wall -Werror -c main.cpp -o main.o

methods.o: methods.cpp
	g++ -Wall -Werror -c methods.cpp -o methods.o

homework: main.o methods.o
	g++ -Wall -Werror main.o methods.o -o homework

clean:
	rm -f *.o homework