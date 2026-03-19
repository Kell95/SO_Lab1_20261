# INFORME DE LABORATORIO 
## Integrantes 
- [tu nombre aqui kelly]
- Brayan Stiven Jaraba Alvarez

# Applicación 2: wgrep

La aplicacion wgrep es una implementación del comando unix `grep` al que se le pasa como primer parametro un `patern` que sera buscado en linea por linea en los path de archivos que sean ingresados duespués de dicho patrón. De esta forma la forma en como se llamará el programa `wgrep` sera asi

> `./wgrep pattern [files...]`

Ahora en caso de que no sea enviado un archivo, este sera capas de leer el `stdin`. Lo cual solo se cumplirá en caso de que se llamado de esta forma

> `./wgrep pattern`

## Funciones implementadas en el wgrep


### `search_pattern()`

la función que tiene como signaturá `void search_pattern(char *file_path, char *pattern)` toma un archivo e intenta abrirlo, en caso de que no se abra este enviará el mensaje `wgrep: can not open file [file_path]`, en el caso contrario usará la función `get_line()` con ciclo while que permitirá leer linea por linea para comprobar que esta contenga el patron usando la función `strstr()`, para luego imprimirlo.

### `read_files()`
la función que tiene como signatura `void read_files(int argc, char *argv[])` toma el contador y el array de argumentos para iterar por cada uno de las direcciones de archivos por la función `search_pattern()`


### `void read_stdio(char *pattern)`
la función que tiene como signatura `void read_stdio(char *pattern)` toma el sdin y la lee línea por línea usando la función `getlines()` para luego comprobar si contiene el patrón usando la función `strstr()` y luego imprimirla.

## Problemas presentados con la implementacion e implementacion de IA

El principal problema que presentamos con la implementación de esta applicación fue el desconocimiento del funcionamiento de la función `getlines()`

Para solucionar el problema hicimos uso de la ingeligencia artificial que nos explico quer para el buffer no necesitabamos darle un tamaño fijo, y que no era necesario decirle la dirección o byte del archivo donde se encontraba cada línea pues este tiene un puntero interno donde guarda donde esta la siguiente línea


## Pruebas de funcionamiento


para las pruebas de funcionamiento creamos dos archvos llamados `file.txt` y `file2.txt` 

```
--- file.txt
este es un arcivo
con varias
lineas con
texto
```

```
--- file2.txt 
este es un segundo archivo
con otras lineas diferentes
y otras palabras
muy diferentes al otro archivo
```

cuando llamamos el comando `./wgrep con file.txt` obtenemos el siguiente output 

```
con varias
lineas con
```

cuando intentamos llamar varios archivos con el comando `./wgrep con file.txt file2.txt` obtenemos el siguiente output

```
con varias
lineas con
con otras lineas diferentes
```

finalmente para probar el `stdin` ejecutamos el sigiente comando `cat ./file2.txt | ./wgrep archivo` y obtenemos el siguiente output


```
este es un segundo archivo
muy diferentes al otro
```
