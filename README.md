# INFORME DE LABORATORIO 
## Integrantes 
- Kelly Julieth Arango Henao
  kjulieth.arangoh@udea.edu.co
  1036657098
- Brayan Stiven Jaraba Alvarez
  
**#Aplicación 1: wcat**

La aplicación wcat es una versión sencilla del comando cat de Unix. Su objetivo es permitir ver el contenido de uno o varios archivos de texto directamente desde la terminal.

Para usar el programa, simplemente se deben pasar como argumentos los nombres de los archivos que se desean visualizar:

./wcat [files...]

Si el usuario no proporciona ningún archivo, el programa finaliza sin mostrar nada, ya que no tiene información que procesar.


## Funciones implementadas en el wcat

main(int argc, char *argv[])

Es la función principal del programa y se encarga de coordinar todo el flujo de ejecución: recibe los archivos desde la línea de comandos, los abre, lee su contenido y lo muestra en pantalla.

**fopen()**

Se utiliza para abrir los archivos en modo lectura ("r").
Devuelve un puntero al archivo (FILE *). Si ocurre un error al abrirlo, retorna NULL, por lo que es importante validar este caso.

**fgets()**

Permite leer el archivo línea por línea, lo que hace que el programa sea más eficiente en el uso de memoria.
Retorna NULL cuando se llega al final del archivo.

**printf()**

Se utiliza para mostrar en consola cada línea leída del archivo. También sirve para imprimir mensajes de error si algo falla.

**fclose()**

Cierra el archivo una vez que se termina de leer. Esto es importante para liberar recursos y evitar problemas en la ejecución.

**exit()**

Finaliza el programa inmediatamente.

exit(0) indica finalización normal.
exit(1) indica que ocurrió un error.

## Problemas presentados con la implementacion e implementacion de IA

No teníamos claro cómo leer correctamente los archivos, por lo que, con ayuda de inteligencia artificial, se comprendió que la mejor forma es hacerlo línea por línea utilizando fgets(), lo que hace el programa más eficiente. También surgieron dudas al momento de manejar errores, especialmente al abrir archivos. Se aprendió que fopen() puede fallar y retornar NULL, por lo que es importante validar este caso para evitar que el programa falle de forma inesperada.

Además, fue necesario entender mejor el uso del buffer y de los punteros (FILE *), ya que son fundamentales para trabajar con archivos en C.

## Pruebas de funcionamiento

Para comprobar que el programa funciona correctamente, se crearon tres archivos de prueba: primero.txt, segundo.txt y tercero.txt.

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

 # Aplicacióon 3: wzip y wunzip

En esta aplicación se desarrollaron dos programas: wzip y wunzip, los cuales permiten comprimir y descomprimir archivos de texto. Ambos utilizan el algoritmo Run-Length Encoding (RLE), que consiste en agrupar caracteres repetidos consecutivamente. 

wzip reduce el tamaño del archivo almacenando cuántas veces se repite un carácter.

wunzip reconstruye el archivo original a partir de esos datos.

## Funciones implementadas en el wzip


Función principal encargada de la compresión.

```
int main(int argc, char *argv[])
```

Verifica que existan archivos de entrada
Abre cada archivo
Lee carácter por carácter
Cuenta repeticiones
Escribe en formato binario:
número de repeticiones
carácter
Finalmente escribe el último grupo


## Funciones implementadas en el wunzip

Función principal encargada de la descompresión.

```
int main(int argc, char *argv[])

```
Verifica los archivos de entrada
Abre cada archivo
Lee pares (cantidad, carácter)
Repite el carácter según la cantidad
Imprime el resultado en pantalla

**fopen()**
Abre un archivo en modo lectura ("r").
Retorna NULL si no se puede abrir.

**fclose()**
Cierra un archivo abierto y libera recursos.

**fgetc()**
Lee un carácter desde un archivo.
Se utiliza en wzip.

**fputc()**
Escribe un carácter en la salida estándar (stdout).
Se utiliza en wunzip.

**fread()**
Lee datos binarios desde un archivo.
Se utiliza en wunzip para leer el número y el carácter.

**fwrite()**
Escribe datos binarios en la salida estándar.
Se utiliza en wzip.

**fprintf()**
Permite imprimir mensajes de error en stderr.

**exit()**
Finaliza la ejecución del programa en caso de error.

# Problemas presentados con la implementación y uso de IA

Durante el desarrollo no fue tan fácil entender cómo aplicar bien el algoritmo RLE, lo más complicado fue manejar correctamente el conteo de los caracteres y saber en qué momento guardar la información.

También tuvimos dificultades al trabajar con datos en binario usando fread() y fwrite(), ya que no es lo mismo que leer texto normal. Nos dimos cuenta de que era muy importante mantener el mismo orden al escribir y leer los datos (primero la cantidad y luego el carácter), porque si no, el programa no funcionaba bien al descomprimir. Con ayuda de inteligencia artificial pudimos entender mejor estos detalles y organizar mejor la lógica del programa. Aun así, fue necesario hacer varias pruebas hasta que todo funcionara correctamente.
 
# Pruebas de funcionamiento

Para comprobar que los programas wzip y wunzip funcionan correctamente, se realizaron varias pruebas con archivos de texto sencillos.

Primero, se creó un archivo de prueba con contenido repetitivo:

```
--- archivo.txt
aaaaabbbbcc
1234
Facultad de Ingeniería
```

Prueba 1: Compresión

Se ejecutó el programa wzip para comprimir el archivo:
```
./wzip archivo.txt > archivo.z
```
En este paso, el programa generó un archivo comprimido en formato binario, donde cada grupo de caracteres se guarda como la cantidad de repeticiones y el carácter.


Prueba 2: Descompresión

Luego, se utilizó wunzip para descomprimir el archivo generado:
```
./wunzip archivo.z
```
Resultado obtenido

```
aaaaabbbbcc
1234
Facultad de Ingeniería
```


