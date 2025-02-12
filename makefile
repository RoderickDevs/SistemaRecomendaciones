Peliculas:Peliculas.o Modelo.o Vista.o Controlador.o DataShell.o controlador_Proceso.o modelo_Archivos.o modelo_sincomas.o modelo_Valida_Nombre.o vista_Errores.o modelo_Tokenizer.o modelo_Columnas.o modelo_Correcion_Nombre.o modelo_optcontent.o controlador_transpuesta.o controlador_errores.o
	gcc -o Peliculas Peliculas.o Modelo.o Vista.o Controlador.o DataShell.o controlador_Proceso.o modelo_Archivos.o modelo_sincomas.o modelo_Valida_Nombre.o vista_Errores.o modelo_Tokenizer.o modelo_Columnas.o modelo_Correcion_Nombre.o modelo_optcontent.o controlador_transpuesta.o controlador_errores.o -lm

Peliculas.o:Peliculas.c
	gcc -c Peliculas.c

Modelo.o:Modelo.c
	gcc -c Modelo.c

Vista.o:Vista.c
	gcc -c Vista.c

Controlador.o:Controlador.c
	gcc -c Controlador.c

DataShell.o:DataShell.c
	gcc -c DataShell.c

controlador_Proceso.o:controlador_Proceso.c
	gcc -c controlador_Proceso.c

modelo_Archivos.o:modelo_Archivos.c
	gcc -c modelo_Archivos.c

modelo_sincomas.o:modelo_sincomas.c
	gcc -c modelo_sincomas.c

modelo_Valida_Nombre.o:modelo_Valida_Nombre.c
	gcc -c modelo_Valida_Nombre.c

vista_Errores.o:vista_Errores.c
	gcc -c vista_Errores.c

modelo_Tokenizer.o:modelo_Tokenizer.c
	gcc -c modelo_Tokenizer.c

modelo_Columnas.o:modelo_Columnas.c
	gcc -c modelo_Columnas.c

modelo_Correcion_Nombre.o:modelo_Correcion_Nombre.c
	gcc -c modelo_Correcion_Nombre.c

modelo_optcontent.o:modelo_optcontent.c
	gcc -c modelo_optcontent.c

controlador_transpuesta.o:controlador_transpuesta.c
	gcc -c controlador_transpuesta.c

controlador_errores.o:controlador_errores.c
	gcc -c controlador_errores.c

clean:
	rm *.o
