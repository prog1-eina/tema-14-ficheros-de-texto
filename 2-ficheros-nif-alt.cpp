/******************************************************************************
 * Curso de Programación 1. Tema 14 (Ficheros de texto)
 * Autores: Javier Martínez, Miguel Ángel Latre y Ricardo J. Rodríguez
 * Resumen: Funciones que trabajan con ficheros de NIF.
 *          Versión alternativa que utiliza funciones específicas para leer y
 *          escribir NIF completos.
 * Nota: El código de este programa está repartido en varios módulos.
 *       Para compilarlo, hay que ejecutar el comando
 *           make fichero-nifs
  *       o ejecutar la tarea "Compilar «fichero-nifs»" de VSC.
 * 
 *       Para ejecutarlo, una vez compilado, hay que ejecutar el comando
 *           bin/fichero-nifs
 *       o, en Windows,
 *           bin\fichero-nifs.exe
 *       o ejecutar la tarea "Ejecutar «fichero-nifs»" de VSC.
 *****************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "nif.hpp"
using namespace std;

/*
 * Pre:  El flujo «f» está asociado con un fichero de texto que cumple con la
 *       sintaxis de la regla <fichero-nif> establecida en las transparencias
 *       de la asignatura y está listo para leer desde el inicio de una línea.
 * Post: Intenta leer la línea mencionada en la precondición y, si no se
 *       terminan los datos del fichero, almacena en los campos del parámetro
 *       «nifLeido» el dni y la letra del NIF leído. Devuelve «true» si se han
 *       podido leer los datos; devuelve «false» en caso contrario.
 */
bool leerNif(istream &f, Nif &nifLeido) {
    char ignorarGuion;
    f >> nifLeido.dni >> ignorarGuion >> nifLeido.letra;
    return !f.eof();
}

/*
 * Pre:  El contenido del fichero de nombre «nombreFichero» sigue la sintaxis
 *       de la regla <fichero-nif> y el número de NIF válidos almacenados en el
 *       fichero «nombreFichero» es menor o igual a la dimensión del
 *       vector «T».
 * Post: Asigna a «nDatos» el número de NIF válidos del fichero y almacena en
 *       las primeras «nDatos» componentes del vector «T» la información de los
 *       NIF válidos almacenados en el fichero. A «nErroneos» le asigna el
 *       número total de NIF del fichero no válidos. Si el fichero se puede
 *       abrir, asigna «true» a «lecturaOk». En caso contrario, asigna «false»
 *       y escribe un mensaje de error por «cerr».
 */
void leerFicheroNif(const string nombreFichero, Nif T[],
                    unsigned &nDatos, unsigned &nErroneos, bool &lecturaOk) {
    ifstream f;
    f.open(nombreFichero);
    if (f.is_open()) {
        nDatos = 0;
        nErroneos = 0;
        while (leerNif(f, T[nDatos])) {
        // Mientras el último intento de lectura fue correcto
            // Se procesan los últimos datos leídos:
            if (esValido(T[nDatos])) {
                nDatos++;
            } else {
                nErroneos++;
            }
        }
        f.close();
        lecturaOk = true;
    } else {
        cerr << "No se ha podido leer del fichero \"" << nombreFichero << "\""
             << endl;
        lecturaOk = false;
    }
}

/*
 * Pre:  El flujo «f» está abierto.
 * Post: Escribe una línea en el flujo «f» con los campos del parámetro
 *       «nif»: número del DNI y letra, separándolos mediante un guion.
 */
void escribirNif(ostream &f, const Nif nif) {
    f << nif.dni << "-" << nif.letra << endl;
}

/*
 * Pre:  ---
 * Post: Crea un fichero de texto de nombre «nombreFichero» en el que almacena
 *       los NIF de las primeras «n» componentes de «T», a razón de un NIF por
 *       línea, separando el número de DNI de la letra mediante un guion.
 *       Si el fichero se puede crear, asigna «true» a «escrituraOk». En caso
 *       contrario, asigna «false» y escribe un mensaje de error por «cerr».
 */
void escribirFicheroNif(const string nombreFichero, const Nif T[],
                        const unsigned n, bool &escrituraOk) {    
    ofstream f;
    f.open(nombreFichero);
    if (f.is_open()) {
        for (unsigned i = 0; i < n; i++) {
            escribirNif(f, T[i]);
        }
        f.close();
        escrituraOk = true;
    } else {
        cerr << "No se ha podido escribir en el fichero \""
             << nombreFichero << "\"." << endl;
        escrituraOk = false;
    }
}


/*
 * Programa de ejemplo de uso de las funciones anteriores.
 */ 
int main() {
    const string NOMBRE_FICHERO_ORIGEN = "datos/nifs-ejemplo.txt";
    const string NOMBRE_FICHERO_DESTINO = "datos/nifs-ejemplo-corregido.txt";
    const unsigned MAX_NIFS = 1000;
    Nif vectorNifs[MAX_NIFS];
    unsigned nDatos, nErroneos;
    
    bool lecturaCorrecta, escrituraCorrecta;
    leerFicheroNif(NOMBRE_FICHERO_ORIGEN, vectorNifs, nDatos, nErroneos,
                   lecturaCorrecta);
    if (lecturaCorrecta) {
        cout << "Leído el fichero. " << endl;
        cout << nDatos << " NIF correctos y " << nErroneos
             << " incorrectos" << endl;
        escribirFicheroNif(NOMBRE_FICHERO_DESTINO, vectorNifs, nDatos,
                           escrituraCorrecta);
    }
    
    if (lecturaCorrecta && escrituraCorrecta) {
        return 0;
    } else {
        return 1;
    }
}
