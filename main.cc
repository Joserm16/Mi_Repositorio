#include "Alumno.h"
#include <iostream>

int main() {
    const std::string FICHERO_SOLICITUDES = "solicitudes.txt";
    const std::string FICHERO_ANULACIONES = "anulaciones.txt";

    Alumno alumno("Miguel Pizarro");

    // Cargar solicitudes desde fichero
    alumno.cargarSolicitudesDesdeFichero(FICHERO_SOLICITUDES);

    int opcion;
    do {
        std::cout << "\n--- Menu de Anulacion de Solicitudes ---\n";
        std::cout << "1. Mostrar solicitudes activas\n";
        std::cout << "2. Anular una solicitud\n";
        std::cout << "3. Salir\n";
        std::cout << "Elige una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            alumno.mostrarSolicitudesActivas();
            break;
        case 2: {
            std::string id;
            std::cout << "Introduce el ID de la solicitud a anular: ";
            std::cin >> id;
            alumno.anularSolicitud(id, FICHERO_ANULACIONES);
            alumno.guardarSolicitudesEnFichero(FICHERO_SOLICITUDES);
            break;
        }
        case 3:
            std::cout << "Saliendo del sistema...\n";
            break;
        default:
            std::cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != 3);

    return 0;
}
