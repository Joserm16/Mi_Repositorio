#include "SistemaGestionIntercambio.h"
#include <iostream>


void SistemaGestionIntercambio::mostrarSolicitudesActivas() {
    bool encontrado = false;
    std::cout << "\nSolicitudes activas:\n";
    for (auto solicitud : solicitudes) { // Copia cada solicitud
        if (solicitud.activa) {
            solicitud.mostrar();
            encontrado = true;
        }
    }
    if (!encontrado) {
        std::cout << "No hay solicitudes activas.\n";
    }
}

void SistemaGestionIntercambio::anularSolicitud(int id) {
    for (auto solicitud : solicitudes) { // Copia cada solicitud
        if (solicitud.id == id && solicitud.activa) {
            solicitud.anular();
            std::cout << "\nSolicitud de intercambio con ID " << id << " anulada exitosamente.\n";
            return;
        }
    }
    std::cout << "Solicitud no encontrada o ya anulada.\n";
}