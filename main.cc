#include "SolicitudIntercambio.h"
#include "SistemaGestionIntercambio.h"
#include <iostream>

int main() {
    SistemaGestionIntercambio sistema;

    // Se agregan algunas solicitudes para pruebas
    sistema.agregarSolicitud(SolicitudIntercambio(1, "Juan Pérez", "Universidad de Barcelona"));
    sistema.agregarSolicitud(SolicitudIntercambio(2, "Ana Gómez", "Universidad de Madrid"));
    sistema.agregarSolicitud(SolicitudIntercambio(3, "Luis García", "Universidad de Valencia"));

    int opcion = 0;

    while (opcion != 3) {
        std::cout << "\nMenu SICUE\n";
        std::cout << "1. Ver solicitudes activas\n";
        std::cout << "2. Anular solicitud\n";
        std::cout << "3. Salir\n";
        std::cout << "Selecciona una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                // Mostrar solicitudes activas
                sistema.mostrarSolicitudesActivas();
                break;

            case 2:
                // Solicitar el ID de la solicitud a anular
                int idSolicitud;
                std::cout << "Introduce el ID de la solicitud a anular: ";
                std::cin >> idSolicitud;
                sistema.anularSolicitud(idSolicitud);
                break;

            case 3:
                std::cout << "Saliendo del sistema.\n";
                break;

            default:
                std::cout << "Opción no válida. Inténtalo de nuevo.\n";
        }
    }

    return 0;
}
