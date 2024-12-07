#ifndef SOLICITUDINTERCAMBIO_H
#define SOLICITUDINTERCAMBIO_H

#include <iostream>
#include <vector>
#include <string>

// Clase que representa una solicitud de intercambio
class SolicitudIntercambio {
    private:
        std::string alumno;
        std::string universidadDestino;
    public:
        int id;
        bool activa; // Indica si la solicitud está activa
        // Constructor de la clase solicitud de intercambio
        SolicitudIntercambio(int id, std::string alumno, std::string universidadDestino) : id(id), alumno(alumno), universidadDestino(universidadDestino), activa(true) {}

        // Método o función para mostrar la solicitud
        void mostrar();

        // Método o función para anular la solicitud
        void anular() {
            activa = false;
        }
};

#endif