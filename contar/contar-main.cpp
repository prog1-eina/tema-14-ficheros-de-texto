/********************************************************************************\
 * Curso de Programación 1. Tema 14 (Ficheros de texto)
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Última revisión: 26 de noviembre de 2018
 * Resumen: Algunas funciones que trabajan con ficheros de texto.
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
\********************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

/*
 * Pre:  «nombreFichero» es el nombre de un fichero de texto existente y accesible
 *       para su lectura.
 * Post: Ha asignado a «nLineas» el número de líneas del fichero y a
 *       «nCaracteres», el número de caracteres del mismo.
 * Nota: Solución que lee línea a línea.
 */
void contabilizar(const char nombreFichero[], int& nLineas,
                  int& nCaracteres) {
    const int MAX = 128;                  // Máxima longitud estimada de una línea
    char linea[MAX];                      // Para almacenar las líneas leídas
    ifstream f;                           // Declara un flujo de entrada.
    nLineas = 0;
    nCaracteres = 0;                      // Solución inicial provisional
    f.open (nombreFichero);  // Asocia a «f» el fichero de nombre «nombreFichero».
    if (f.is_open()) {
        f.getline(linea, MAX);            // Intenta leer una primera línea.
        while (!f.eof()) {
            // Mientras el último intento de lectura fue correcto
            nLineas = nLineas + 1;        // Actualiza el número de líneas...
            nCaracteres = nCaracteres + f.gcount();           // ... y caracteres.
            f.getline(linea, MAX);        // Intenta leer una nueva línea.
        }
        f.close();                        // Libera el fichero asociado a «f».
    }
    else {
        cerr << "No se ha podido abrir el fichero \"" << nombreFichero << "\"."
             << endl;
    }
}

/*
 * Pre:  «nombreFichero» es el nombre de un fichero de texto válido
 *       listo para su inspección.
 * Post: Asigna a «nLineas» el número de líneas del fichero y
 *       a «nCaracteres» el número de caracteres del mismo.
 * Nota: Solución que lee carácter a carácter.
 */
void contabilizar2(const char nombreFichero[], int& nLineas,
                  int& nCaracteres) {
    nLineas = 0;
    nCaracteres = 0;                    // Solución inicial provisional
    ifstream f;                         // Declara un flujo de entrada.
    f.open(nombreFichero);   // Asocia a «f» el fichero de nombre «nombreFichero».
    if (f.is_open()) {
        char c;
        f.get(c);                       // Intenta leer un primer carácter de «f».
        while(!f.eof()) {
            nCaracteres++;              // Cuenta el último caracter leído.
            if ('\n' == c) {
                // Si el último caracter leído es un cambio de línea...
                nLineas++;              // ... cuenta una línea más.
            }
            f.get(c);                   // Intenta leer el siguiente carácter.
        }
        f.close();   // Libera el fichero asociado a «f».
    }
    else {
        cerr << "No se ha podido abrir el fichero \"" << nombreFichero << "\"."
             << endl;
    }
}


/*
 * Pre:  En el directorio del proyecto, existe un fichero de texto denominado
 *       «lope-de-vega.txt».
 * Post: Ha realizado pruebas de las funciones anteriores, invocándolas con el
 *       fichero «lope-de-vega.txt» y mostrando los resultados obtenidos.
 */
int main() {
    const char NOMBRE_FICHERO[] = "../lope-de-vega.txt";

    int lineas, caracteres;
    contabilizar(NOMBRE_FICHERO, lineas, caracteres);
    cout << '\"' << NOMBRE_FICHERO << "\" tiene " << lineas << " líneas y " 
         << caracteres << " caracteres." << endl;
    return 0;
}
