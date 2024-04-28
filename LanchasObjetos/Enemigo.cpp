//enemigo.cpp

#include "Enemigo.h"
#include <cstdlib> // Para la función rand()




// Constructor con parámetros
Enemigo::Enemigo(string pNombreCorredor, int pVelocidad, int pNitro) {
    NombreCorredor = pNombreCorredor;
    Velocidad = pVelocidad;
    DistanciaRecorrida = 0;
    Nitro = pNitro;
    NitroUsado = false; 
}

// Lanzar el dado
int Enemigo::lanzarDado() {
    return rand() % 6 + 1; // Generar un número aleatorio entre 1 y 6
}

// Usar la nitro
int Enemigo::usarNitro() {
    if (Nitro > 0 && !NitroUsado) { // Verificar si hay nitro disponible y no se ha usado
        int numAleatorio = rand() % 2; // Generar un número aleatorio entre 0 y 1
        if (numAleatorio == 0) {
            Velocidad /= 2; // Dividir la velocidad por dos
        }
        else {
            Velocidad *= 2; // Duplicar la velocidad
        }
        Nitro--; // Decrementar el número de nitros disponibles
        NitroUsado = true; // Marcar el nitro como utilizado
        return numAleatorio; // Devolver el número aleatorio generado
    }
    else {
        return -1; // Indicar que no se puede usar la nitro
    }
}


// Avanzar la lancha
void Enemigo::avanzar() {
    DistanciaRecorrida += Velocidad;
}

// Método para obtener los parámetros del enemigo
void Enemigo::getParameters() {
    cout << "Nombre: " << NombreCorredor << ", Velocidad: " << Velocidad << ", Distancia Recorrida: " << DistanciaRecorrida << endl;
}

// Getters
string Enemigo::getNombreCorredor() {
    return NombreCorredor;
}

int Enemigo::getVelocidad() {
    return Velocidad;
}

int Enemigo::getDistanciaRecorrida() {
    return DistanciaRecorrida;
}

bool Enemigo::getNitroUsado() {
    return NitroUsado;
}

// Setters
void Enemigo::setNombreCorredor(string pNombreCorredor) {
    NombreCorredor = pNombreCorredor;
}

void Enemigo::setVelocidad(int pVelocidad) {
    Velocidad = pVelocidad;
}

void Enemigo::setDistanciaRecorrida(int pDistanciaRecorrida) {
    DistanciaRecorrida = pDistanciaRecorrida;
}

void Enemigo::setNitroUsado(bool pNitroUsado) {
    NitroUsado = pNitroUsado;
}