//LanchasObjetos.cpp
#include <iostream>
#include "Enemigo.h"

using namespace std;

int main() {
    // Crear objetos Enemigo 
    Enemigo enemigo1("Carlos", 0, 1); 
    Enemigo enemigo2("Luis", 0, 1);

    // Realizar cinco turnos
    for (int turno = 1; turno <= 5; turno++) {
        cout << "Turno " << turno << endl;

        // Turno de enemigo1
        cout << "Turno de " << enemigo1.getNombreCorredor() << endl;
        int puntos = enemigo1.lanzarDado(); // Lanzar el dado
        cout << "Obtuviste " << puntos << " puntos." << endl;

        // Añadir los puntos obtenidos a la velocidad de la lancha
        enemigo1.setVelocidad(enemigo1.getVelocidad() + puntos);
        char opcion;
        cout << "Usar nitro (S/N): ";
        cin >> opcion;
        if (opcion == 'S' || opcion == 's') {
            // Usar la nitro y obtener el número aleatorio generado
            int numAleatorio = enemigo1.usarNitro();
            if (numAleatorio != -1) {
                cout << "Puntos con el dado: " << numAleatorio << endl;
            }
            else {
                // Si devuelve -1, significa que la nitro ya ha sido utilizada este turno
                cout << "No se puede usar la nitro este turno. Nitro acabado" << endl;
            }

            enemigo1.avanzar(); 
            enemigo1.getParameters(); 
        }

        // Turno de enemigo2
        cout << "Turno de " << enemigo2.getNombreCorredor() << endl;
        puntos = enemigo2.lanzarDado(); 
        cout << "Obtuviste " << puntos << " puntos." << endl;

        // Añadir los puntos obtenidos a la velocidad de la lancha
        enemigo2.setVelocidad(enemigo2.getVelocidad() + puntos);
        cout << "Usar nitro (S/N): ";
        cin >> opcion;
        if (opcion == 'S' || opcion == 's') {
            int numAleatorio = enemigo2.usarNitro(); 
            if (numAleatorio != -1) {
                cout << "Puntos con el dado: " << numAleatorio << endl;
            }
            else {
                cout << "No se puede usar la nitro este turno. Nitro acabado" << endl;
            }
        }
        enemigo2.avanzar(); 
        enemigo2.getParameters(); 

        cout << endl; 
    } 

    // Comprobar qué jugador ha ganado o si hay un empate
    if (enemigo1.getDistanciaRecorrida() > enemigo2.getDistanciaRecorrida()) {
        cout << "El jugador " << enemigo1.getNombreCorredor() << " ha ganado" << endl;
    }
    else if (enemigo2.getDistanciaRecorrida() > enemigo1.getDistanciaRecorrida()) {
        cout << "El jugador " << enemigo2.getNombreCorredor() << " ha ganado" << endl;
    }
    else {
        cout << "Empate" << endl;
    }

    return 0;
}
