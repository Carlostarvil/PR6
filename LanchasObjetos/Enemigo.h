//enemigo.h

#pragma once

#include <iostream>
#include <string>

using namespace std;

class Enemigo {
private:
    string NombreCorredor;
    int Velocidad;
    int DistanciaRecorrida;
    int Nitro;
    bool NitroUsado; 
public:
    

    // Constructor con parámetros
    Enemigo(string pNombreCorredor, int pVelocidad, int pNitro);

    // Métodos para obtener y establecer valores
    string getNombreCorredor();
    void setNombreCorredor(string pNombreCorredor);
    int getVelocidad();
    void setVelocidad(int pVelocidad);
    int getDistanciaRecorrida();
    void setDistanciaRecorrida(int pDistanciaRecorrida);
    int getNitro();
    void setNitro(int pNitro);
    void getParameters();
    void avanzar();
    int lanzarDado(); 
    int usarNitro(); 
    bool getNitroUsado();
    void setNitroUsado(bool estado);
    void restablecerNitro();
};