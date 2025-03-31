all: main.o
	gcc main.o -o main.exe
main.o: main.c CatalogoProdutos.h
	gcc -c main.c -o main.o
clean:
	rm *.exe *.o