/******************************************************************************\
 * Curso de Programación 1. Tema 14 (Ficheros de texto)
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Última revisión: 29 de noviembre de 2021
 * Resumen: Algunas funciones que trabajan con ficheros de texto.
\******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
 * Pre:  «nombreFichero» es el nombre de un fichero de texto existente y
 *       accesible para su lectura.
 * Post: Si el fichero de nombre «nombreFichero» se ha podido leer, ha asignado
 *       a «nLineas» el número de líneas del fichero y a «nCaracteres» el número
 *       de caracteres del mismo y ha devuelto «true». En caso contrario, ha
 *       devuelto «false».
 * Nota: Solución que lee línea a línea.
 */
bool contabilizar(const string nombreFichero, unsigned& nLineas,
                  unsigned& nCaracteres) {
    ifstream f;                      // Declara un flujo de entrada.
    f.open (nombreFichero);          // Asocia a «f» el fichero «nombreFichero».
    if (f.is_open()) {
        nLineas = 0;
        nCaracteres = 0;                  // Solución inicial provisional
        string linea;                     // Para almacenar las líneas leídas
        while (getline(f, linea)) {
            // Mientras el último intento de lectura fue correcto
            nLineas++;                    // Actualiza el número de líneas...
            nCaracteres += linea.length() + 1;           // ... y caracteres.
        }
        f.close();                        // Libera el fichero asociado a «f».
        return true;
    }
    else {
        cerr << "No se ha podido abrir el fichero \"" << nombreFichero << "\"."
             << endl;
        return false;
    }
}

/*
 * Pre:  «nombreFichero» es el nombre de un fichero de texto válido
 *       listo para su inspección.
 * Post: Si el fichero de nombre «nombreFichero» se ha podido leer, ha asignado
 *       a «nLineas» el número de líneas del fichero y a «nCaracteres» el número
 *       de caracteres del mismo y ha devuelto «true». En caso contrario, ha
 *       devuelto «false».
 * Nota: Solución que lee carácter a carácter.
 */
bool contabilizar2(const string nombreFichero,
                   unsigned& nLineas, unsigned& nCaracteres) {
    ifstream f;                         // Declara un flujo de entrada.
    f.open(nombreFichero);   // Asocia a «f» el fichero de nombre «nombreFichero».
    if (f.is_open()) {
        nLineas = 0;
        nCaracteres = 0;                // Solución inicial provisional
        char c;
        while(f.get(c)) {
            // Mientras el último intento de lectura fue correcto
            nCaracteres++;              // Cuenta el último caracter leído.
            if ('\n' == c) {
                // Si el último caracter leído es un cambio de línea...
                nLineas++;              // ... cuenta una línea más.
            }
        }
        f.close();   // Libera el fichero asociado a «f».
        return true;
    }
    else {
        cerr << "No se ha podido abrir el fichero \"" << nombreFichero << "\"."
             << endl;
        return false;
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

    unsigned lineas, caracteres;
    if (contabilizar(NOMBRE_FICHERO, lineas, caracteres)) {
        cout << '\"' << NOMBRE_FICHERO << "\" tiene " << lineas << " líneas y " 
            << caracteres << " caracteres." << endl;
        return 0;
    }
    else {
        return 1;
    }
}
