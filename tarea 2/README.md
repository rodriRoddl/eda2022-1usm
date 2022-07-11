# Tesoro perdido

======================================================================================

**Descripción del programa**

El programa consiste en la implementacion de distintos algoritmos de ordenamiento, desde el menos eficiente hasta el de mejor rendimiento.

======================================================================================

**condiciones de compilacion y ejecución**

Para poder usar el programa de manera adecuada es recomendado usar distribuciones de Linux como : Ubuntu(recomendada), Devian, Mint, etc.  

Para poder hacer la compilación del programa, usaremos la funcion gcc, si es que no tiene la funcion, desde terminal debe ejecutar:

    sudo apt-get install build-essential

Luego de la instalación de la función, usaremos el siguiente comando el consola para la compilación:

    make

Este comando lo utilizaremos para la compilacion completa del programa, el archivo ejecutable será un ./TEST, el cual podrá ejecutar con:

    make exe

Para finalizar, si quiere limpiar los archivos restantes de la compilación, puede ejecutar:
    
    make clean

**caso por terminal**

En caso de no poder usar Makefile, puede utilizar el siguiente paso de comandos para compilación, ejecución y limpiar archivos:

    gcc tda.c main.c -o TEST -Wall
    ./TEST "tweets.csv"

======================================================================================

**informacion del programador**

Rodrigo Lobos, estuidante de Ingeniería Civil Telemática, Universidad Técnica Féderico Santa María.

