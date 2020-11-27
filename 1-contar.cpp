/******************************************************************************\
 * Curso de Programación 1. Tema 14 (Ficheros de texto)
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Última revisión: 26 de noviembre de 2018
 * Resumen: Algunas funciones que trabajan con ficheros de texto.
\******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
 * Pre:  «nombreFichero» es el nombre de un fichero de texto existente y
 *       accesible para su lectura.
 * Post: Ha asignado a «nLineas» el número de líneas del fichero y a
 *       «nCaracteres», el número de caracteres del mismo.
 * Nota: Solución que lee línea a línea.
 */
void contabilizar(const string nombreFichero, int& nLineas,
                  int& nCaracteres) {
    ifstream f;                      // Declara un flujo de entrada.
    f.open (nombreFichero);          // Asocia a «f» el fichero «nombreFichero».
    if (f.is_open()) {
        nLineas = 0;
        nCaracteres = 0;                  // Solución inicial provisional
        string linea;                     // Para almacenar las líneas leídas
        getline(f, linea);                // Intenta leer una primera línea.
        while (!f.eof()) {
            // Mientras el último intento de lectura fue correcto
            nLineas++;                    // Actualiza el número de líneas...
            nCaracteres += linea.length() + 1;           // ... y caracteres.
            getline(f, linea);            // Intenta leer una nueva línea.
        }
        f.close();                        // Libera el fichero asociado a «f».
    }
    else {
        cerr << "No se ha podido abrir el fichero \"" << nombreFichero << "\"."
             << endl;
        nLineas = -1;
        nCaracteres = -1;
    }
}

/*
 * Pre:  «nombreFichero» es el nombre de un fichero de texto válido
 *       listo para su inspección.
 * Post: Asigna a «nLineas» el número de líneas del fichero y
 *       a «nCaracteres» el número de caracteres del mismo.
 * Nota: Solución que lee carácter a carácter.
 */
void contabilizar2(const string nombreFichero,
                   int& nLineas, int& nCaracteres) {
    ifstream f;                         // Declara un flujo de entrada.
    f.open(nombreFichero);   // Asocia a «f» el fichero de nombre «nombreFichero».
    if (f.is_open()) {
        nLineas = 0;
        nCaracteres = 0;                // Solución inicial provisional
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
        nLineas = -1;
        nCaracteres = -1;
    }
}


/*
 * Pre:  En el directorio «datos» del proyecto, existe un fichero de texto 
 *       denominado «lope-de-vega.txt».
 * Post: Ha realizado pruebas de las funciones anteriores, invocándolas con el
 *       fichero «lope-de-vega.txt» y mostrando los resultados obtenidos.
 */
int main() {
    const string NOMBRE_FICHERO = "datos/lope-de-vega.txt";

    int lineas, caracteres;
    contabilizar(NOMBRE_FICHERO, lineas, caracteres);
    cout << '\"' << NOMBRE_FICHERO << "\" tiene " << lineas << " líneas y " 
         << caracteres << " caracteres." << endl;
    return 0;
}
