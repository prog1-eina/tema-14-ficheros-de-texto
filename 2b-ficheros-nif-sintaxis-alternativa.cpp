/******************************************************************************\
 * Curso de Programación 1. Tema 14 (Ficheros de texto)
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Última revisión: 27 de noviembre de 2019
 * Resumen: Funciones que trabajan con ficheros de NIF.
 * Nota: Versión con la sintaxis alternativa según la regla 
 *       <fichero-nif-alternativo> presentada en los apuntes del profesor
 *       Javier Martínez.
 * Nota: El código de este programa está repartido en varios módulos.
 *       Para compilarlo, hay que ejecutar el comando
 *           make fichero-nifs-alt
 *       o, en Windows,
 *           mingw32-make fichero-nifs-alt
 *       o ejecutar la tarea "Compilar «fichero-nifs-alt»" de VSC.
 * 
 *       Para ejecutarlo, una vez compilado, hay que ejecutar el comando
 *           bin/fichero-nifs-alt
 *       o, en Windows,
 *           bin\fichero-nifs-alt.exe
 *       o ejecutar la tarea "Ejecutar «fichero-nifs-alt»" de VSC.
\******************************************************************************/

#include <iostream>
#include <fstream>
#include "nif.hpp"
using namespace std;

/*
 * Pre:  El contenido del fichero de nombre «nombreFichero» sigue la sintaxis de
 *       la regla <fichero-nif-alternativo> y el número de NIF almacenados en el
 *       fichero «nombreFichero» es menor o igual a la dimensión del vector «T».
 * Post: Ha asignado a «nDatos» el número de NIF válidos del fichero y ha
 *       almacenado en las primeras «nDatos» componentes del vector «T» la
 *       información de los NIF válidos almacenados en el fichero. A «nErroneos»
 *       le ha asignado el número total de NIF del fichero no válidos. Si el
 *       fichero no se ha podido abrir, ha asignado -1 tanto a «nDatos» como
 *       «nErroneos» y ha escrito un mensaje de error.
 */
void leerFicheroNif(const string nombreFichero, Nif T[],
                   int& nDatos, int& nErroneos) {
    ifstream f;
    f.open(nombreFichero);
    if (f.is_open()) {
        unsigned int totalDatos;
        f >> totalDatos;

        nDatos = 0;
        nErroneos = 0;

        for (unsigned int i = 0; i < totalDatos; i++) {
            f >> T[nDatos].dni >> T[nDatos].letra;
            if (esValido(T[nDatos])) {
                nDatos++;
            }
            else {
                nErroneos++;
            }
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
 * Pre:  ---
 * Post: Crea un fichero de texto de nombre «nombreFichero» en el que almacena
 *       los NIF de las primeras «n» componentes de «T», siguiendo la sintaxis
 *       de la regla <fichero-nif-alternativo>. Si el fichero no se ha podido
 *       escribir, ha escrito un mensaje de error en «cerr».
 */
void escribirFicheroNif(const string nombreFichero, const Nif T[],
                        const unsigned int n) {
    ofstream f;
    f.open(nombreFichero);
    if (f.is_open()) {
        f << n << endl;
        for (unsigned int i = 0; i < n; i++) {
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
    const string NOMBRE_FICHERO_ORIGEN = "datos/nifs-ejemplo-alternativo.txt";
    const string NOMBRE_FICHERO_DESTINO = "datos/nifs-ejemplo-alternativo-corregido.txt";
    const int MAX_NIFS = 1000;
    Nif vectorNifs[MAX_NIFS];
    int nDatos, nErroneos;
    
    leerFicheroNif(NOMBRE_FICHERO_ORIGEN, vectorNifs, nDatos, nErroneos);
    cout << "Leído el fichero. " << endl;
    cout << nDatos << " NIF correctos y " << nErroneos << " incorrectos" << endl;
         
    escribirFicheroNif(NOMBRE_FICHERO_DESTINO, vectorNifs, nDatos);
    return 0;
}