Peliculas:Peliculas.o Modelo.o Vista.o Controlador.o
	gcc -o Peliculas Peliculas.o Modelo.o Vista.o Controlador.o

Peliculas.o:Peliculas.c
	gcc -c Peliculas.c

Modelo.o:Modelo.c
	gcc -c Modelo.c

Vista.o:Vista.c
	gcc -c Vista.c

Controlador.o:Controlador.c
	gcc -c Controlador.c

clean:
	rm *.o
