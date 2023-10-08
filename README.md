# Ficheros de texto

Código de las transparencias del tema 14 (ficheros de texto) de la asignatura [Programación 1](https://github.com/prog1-eina) ([Grado en Ingeniería Informática](https://webdiis.unizar.es/~silarri/coordinadorGrado/), [Escuela de Ingeniería y Arquitectura](https://eina.unizar.es/), [Universidad de Zaragoza](https://www.unizar.es/)).

## Compilación y ejecución

### ``1-contar.cpp``

El fichero ``1-contar.cpp`` contiene un programa completo, por lo que puede compilarse y ejecutarse con la extensión Code Runner de Visual Studio Code.

También puede compilarse desde la terminal través de la orden

    g++ -Wall -Wextra 1-contar.cpp -o 1-contar

o desde Visual Studio Code, ejecutando la tarea ``Compilar «contar»``

Puede ejecutarse en Windows, después de ser compilado, a través de la orden

    .\1-contar.exe

y en Linux o macOS, a través de la orden

    ./1-contar

y en ambos casos, desde Visual Studio Code, ejecutando la tarea ``Ejecutar «contar»``.

### `2-ficheros-nif.cpp`

El programa del fichero `2-ficheros-nif.cpp` necesita del módulo «nif» del [repositorio del tema 11 (registros)](https://github.com/prog1-eina/tema-11-registros). El fichero `Makefile` ha sido configurado suponiendo que el directorio del código del tema 11 se encuentra en un directorio denominado `tema-11-registros` ubicado en la misma carpeta que el directorio del código de este repositorio.

Para compilarlo, hay que ejecutar el comando

    make fichero-nifs

o ejecutar la tarea ``Compilar «fichero-nifs»`` de VSC.

Para ejecutarlo, una vez compilado, hay que ejecutar el comando

    bin/fichero-nifs

o, en Windows,

    bin\fichero-nifs.exe

o ejecutar la tarea ``Ejecutar «fichero-nifs»`` de VSC.

Los NIF del fichero `nifs-ejemplo.txt` han sido generados aleatoriamente y tienen nueve cifras a propósito para que no se trate de datos personales.
