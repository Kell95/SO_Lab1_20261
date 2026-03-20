# INFORME DE LABORATORIO 
## Integrantes 
- Kelly Julieth Arango Henao
  kjulieth.arangoh@udea.edu.co
  1036657098
- Brayan Stiven Jaraba Alvarez
  
**#Aplicación 1: wcat**

La aplicación wcat es una implementación del comando Unix cat, la cual permite visualizar el contenido de uno o varios archivos de texto directamente desde la terminal. A este programa se le pasan como parámetros los nombres de los archivos que se desean leer.

La forma de ejecutar el programa es:

./wcat [files...]

En caso de que no se envíen archivos como argumento, el programa simplemente finaliza sin realizar ninguna acción.

## Funciones implementadas en el wcat

main(int argc, char *argv[])

Es la función principal del programa y se encarga de coordinar todo el flujo de ejecución: recibe los archivos desde la línea de comandos, los abre, lee su contenido y lo muestra en pantalla.

**fopen()**

Función de la librería estándar que se utiliza para abrir un archivo en el modo especificado. En este programa se usa en modo lectura ("r"). Retorna un puntero de tipo FILE. Si no puede abrir el archivo, retorna NULL.

**fgets()**

Función que permite leer el contenido de un archivo línea por línea. Recibe un buffer donde almacena la línea leída y evita consumir demasiada memoria. Retorna NULL cuando llega al final del archivo.

**printf()**

Función utilizada para mostrar información en la consola. En este programa imprime cada línea del archivo y también se usa para mostrar mensajes de error.

**fclose()**

Función que se utiliza para cerrar un archivo una vez que ha sido procesado. Libera los recursos asociados al archivo y es importante para evitar fugas de memoria.

**exit() **

Función que permite finalizar el programa inmediatamente.

exit(0) indica finalización normal.

exit(1) indica que ocurrió un error.

## Problemas presentados con la implementacion e implementacion de IA

No teníamos claro cómo leer correctamente los archivos, por lo que, con ayuda de inteligencia artificial, se comprendió que la mejor forma es hacerlo línea por línea utilizando fgets(), lo que hace el programa más eficiente. También surgieron dudas al momento de manejar errores, especialmente al abrir archivos. Se aprendió que fopen() puede fallar y retornar NULL, por lo que es importante validar este caso para evitar que el programa falle de forma inesperada.

Además, fue necesario entender mejor el uso del buffer y de los punteros (FILE *), ya que son fundamentales para trabajar con archivos en C.

## Pruebas de funcionamiento

Para validar el correcto funcionamiento del programa, se crearon tres archivos de prueba llamados primero.txt, segundo.txt y tercero.txt.
```
--- primero.txt
Hola, este es el primer archivo.
Estoy probando el programa wcat.
Este programa lee archivos linea por linea.
Fin del archivo 1.
```
```
--- segundo.txt
Este es el segundo archivo.
El programa debe mostrar este texto despues del primero.
Si aparece en pantalla, significa que wcat funciona correctamente.
Fin del archivo 2.

```
```
--- tercero.txt

Laboratorio de Sistemas Operativos.
Programa wcat en lenguaje C.
Lectura de archivos usando fopen y fgets.
```

Prueba 1: Lectura de un archivo
```
./wcat primero.txt
```
Prueba 2: Lectura de múltiples archivos
```
./wcat primero.txt segundo.txt tercero.txt
```

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


### `read_stdio()`
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
