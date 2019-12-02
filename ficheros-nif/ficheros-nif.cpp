/********************************************************************************\
 * Curso de Programación 1. Tema 14 (Ficheros de texto)
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Última revisión: 2 de diciembre de 2019
 * Resumen: Funciones que trabajan con ficheros de NIF.
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
\********************************************************************************/

#include <iostream>
#include <fstream>
#include "nif.h"
using namespace std;

/*
 * Pre:  El contenido del fichero de nombre «nombreFichero» sigue la sintaxis de
 *       la regla <fichero-nif> y el número de NIF almacenados en el fichero
 *       «nombreFichero» es menor  o igual a la dimensión del vector «T».
 * Post: Ha asignado a «nDatos» el número de NIF válidos del fichero y ha
 *       almacenado en las primeras «nDatos» componentes del vector «T» la
 *       información de los NIF válidos almacenados en el fichero. A «nErroneos»
 *       le ha asignado el número total de NIF del fichero no válidos. Si el
 *       fichero no se ha podido abrir, ha asignado -1 tanto a «nDatos» como
 *       «nErroneos» y ha escrito un mensaje de error.
 */
void leerFicheroNif(const char nombreFichero[], Nif T[],
                   int& nDatos, int& nErroneos) {
    ifstream f;
    f.open(nombreFichero);
    if (f.is_open()) {
        nDatos = 0;
        nErroneos = 0;

        // Se intenta leer el primer NIF en la componente T[0]:
        f >> T[nDatos].dni >> T[nDatos].letra;
        while (!f.eof()) {
            // La última lectura fue correcta, no se había acabado el fichero
            if (esValido(T[nDatos])) {
                nDatos++;
            }
            else {
                nErroneos++;
            }
            // Se intenta leer el primer NIF en la componente T[nDatos]:
            f >> T[nDatos].dni >> T[nDatos].letra;
        }
        f.close();                    // Libera el fichero
    }
    else {
        cerr << "No se ha podido leer del fichero \"" << nombreFichero << "\""
             << endl;
        nDatos = -1;
        nErroneos = -1;
    }
}


/*
 * Pre:  n>=0
 * Post: Crea un fichero de texto de nombre «nombreFichero» en el que almacena los
 *       NIF de las primeras «n» componentes de «T», a razón de un NIF por línea,
 *       separando el número de DNI de la letra mediante un espacio en blanco. Si
 *       el fichero no se ha podido escribir, ha escrito un mensaje de error en
 *       «cerr».
 */
void escribirFicheroNif(const char nombreFichero[], const Nif T[],
                const int n) {
    ofstream f;
    f.open(nombreFichero);
    if (f.is_open()) {
        for (int i = 0; i < n; i++) {
            f << T[i].dni << " " << T[i].letra << endl;
        }
        f.close();
    }
    else {
        cerr << "No se ha podido escribir en el fichero \""
             << nombreFichero << "\"." << endl;
    }
}


/*
 * Programa de ejemplo de uso de las funciones anteriores.
 */ 
int main() {
    const char NOMBRE_FICHERO_ORIGEN[] = "../nifs-ejemplo.txt";
    const char NOMBRE_FICHERO_DESTINO[] = "../nifs-ejemplo-corregido.txt";
    const int MAX_NIFS = 1000;
    Nif vectorNifs[MAX_NIFS];
    int nDatos, nErroneos;
    
    leerFicheroNif(NOMBRE_FICHERO_ORIGEN, vectorNifs, nDatos, nErroneos);
    cout << "Leído el fichero. " << endl;
    cout << nDatos << " NIF correctos y " << nErroneos << " incorrectos" << endl;
         
    escribirFicheroNif(NOMBRE_FICHERO_DESTINO, vectorNifs, nDatos);
    return 0;
}