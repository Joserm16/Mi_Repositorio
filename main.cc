#include <iostream>
#include "funciones.h"


void mostrarMenu() {
    std::cout << "\n===== MENÚ DEL SISTEMA DE CONVALIDACIONES =====\n";
    std::cout << "1. Mostrar planes de convalidación disponibles\n";
    std::cout << "2. Inscribirse en un plan de convalidación\n";
    std::cout << "3. Crear un nuevo plan de convalidación\n";
    std::cout << "4. Anular solicitud de intercambio\n";
    std::cout << "5. Exportar planes a un fichero\n";
    std::cout << "6. Salir\n";
    std::cout << "Seleccione una opción: ";
}

int main() {

    SistemaConvalidacion sistema;
    std::vector<PlanConvalidacion> planesDisponibles;

    int opcion;
    do {
        mostrarMenu();
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                if (planesDisponibles.empty()) {
                    std::cout << "No hay planes de convalidación disponibles.\n";
                } else {
                    sistema.mostrarPlanesDisponibles(planesDisponibles);
                }
                break;

            case 2: {
                if (planesDisponibles.empty()) {
                    std::cout << "No hay planes disponibles para inscribirse.\n";
                } else {
                    int planSeleccionado;
                    std::cout << "Seleccione el número del plan para inscribirse: ";
                    std::cin >> planSeleccionado;
                    if (planSeleccionado >= 1 && planSeleccionado <= planesDisponibles.size()) {
                        std::vector<std::string> asignaturasCursadas;
                        std::cout << "Ingrese las asignaturas que ya ha cursado (separadas por ENTER, escriba 'fin' para terminar):\n";
                        std::string asignatura;
                        while (true) {
                            std::cin >> asignatura;
                            if (asignatura == "fin") break;
                            asignaturasCursadas.push_back(asignatura);
                        }
                        sistema.inscribirseEnPlan(planesDisponibles[planSeleccionado - 1], asignaturasCursadas);
                    } else {
                        std::cout << "Opción no válida.\n";
                    }
                }
                break;
            }

            case 3: {
                std::string nombre, universidadDestino;
                std::vector<std::string> asignaturas, requisitosPrevios;
                std::vector<int> creditos;

                std::cout << "Ingrese el nombre del plan: ";
                std::cin.ignore(); // Para evitar problemas con getline
                std::getline(std::cin, nombre);

                std::cout << "Ingrese la universidad de destino: ";
                std::getline(std::cin, universidadDestino);

                std::cout << "Ingrese las asignaturas del plan (escriba 'fin' para terminar):\n";
                std::string asignatura;
                while (true) {
                    std::getline(std::cin, asignatura);
                    if (asignatura == "fin") break;
                    asignaturas.push_back(asignatura);
                }

                std::cout << "Ingrese los créditos de las asignaturas (en el mismo orden, separados por ENTER):\n";
                for (size_t i = 0; i < asignaturas.size(); ++i) {
                    int credito;
                    std::cout << "Créditos para " << asignaturas[i] << ": ";
                    std::cin >> credito;
                    creditos.push_back(credito);
                }

                std::cin.ignore(); // Limpiar el buffer
                std::cout << "Ingrese los requisitos previos del plan (escriba 'fin' para terminar):\n";
                std::string requisito;
                while (true) {
                    std::getline(std::cin, requisito);
                    if (requisito == "fin") break;
                    requisitosPrevios.push_back(requisito);
                }

                sistema.crearPlanConvalidacion(nombre, universidadDestino, asignaturas, creditos, requisitosPrevios);
                planesDisponibles.push_back({nombre, universidadDestino, asignaturas, creditos, requisitosPrevios});
                break;
            }

            case 4: {
                int idSolicitud;
                std::cout << "Ingrese el ID de la solicitud a anular: ";
                std::cin >> idSolicitud;
                sistema.anularSolicitudIntercambio(idSolicitud);
                break;
            }

            case 5: {
                if (planesDisponibles.empty()) {
                    std::cout << "No hay planes disponibles para exportar.\n";
                } else {
                    std::string nombreArchivo;
                    std::cout << "Ingrese el nombre del archivo para exportar los planes (e.g., planes.txt): ";
                    std::cin >> nombreArchivo;
                    sistema.exportarPlanesAFichero(planesDisponibles, nombreArchivo);
                }
                break;
            }

            case 6:
                std::cout << "Saliendo del sistema...\n";
                break;

            default:
                std::cout << "Opción no válida. Por favor, intente de nuevo.\n";
        }
    } while (opcion != 6);

    return 0;
}
