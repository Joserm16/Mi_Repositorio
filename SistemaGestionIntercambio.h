#ifndef SISTEMAGESTIONINTERCAMBIO_H
#define SISTEMAGESTIONINTERCAMBIO_H

#include "SolicitudIntercambio.h"
#include <vector>

class SistemaGestionIntercambio {
    private:
        std::vector<SolicitudIntercambio> solicitudes;
    public:
        // Método para agregar solicitudes de intercambio al sistema
        void agregarSolicitud(SolicitudIntercambio solicitud){solicitudes.push_back(solicitud);}

        // Método para mostrar las solicitudes activas
        void mostrarSolicitudesActivas();

        // Método para anular una solicitud por su ID
        void anularSolicitud(int id);
};

#endif