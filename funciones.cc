#include "funciones.h"
#include <iostream>
#include <fstream>
#include <algorithm>

void SistemaConvalidacion::mostrarPlanesDisponibles(const std::vector<PlanConvalidacion>& planes) {
    std::cout << "Planes de Convalidación Disponibles:\n";
    for (size_t i = 0; i < planes.size(); ++i) {
        std::cout << "Plan " << i + 1 << ": " << planes[i].nombre << ", Universidad: " << planes[i].universidadDestino << "\n";
        std::cout << "Asignaturas: ";
        for (const auto& asignatura : planes[i].asignaturas) {
            std::cout << asignatura << " ";
        }
        std::cout << "\n";
    }
}

bool SistemaConvalidacion::inscribirseEnPlan(const PlanConvalidacion& plan, const std::vector<std::string>& asignaturasCursadas) {
    for (const auto& requisito : plan.requisitosPrevios) {
        if (std::find(asignaturasCursadas.begin(), asignaturasCursadas.end(), requisito) != asignaturasCursadas.end()) {
            std::cout << "Error: Ya has cursado una asignatura que es requisito de este plan.\n";
            return false;
        }
    }
    std::cout << "Inscripción exitosa en el plan de convalidación " << plan.nombre << "\n";
    return true;
}

void SistemaConvalidacion::crearPlanConvalidacion(const std::string& nombre, const std::string& universidadDestino, 
                                                   const std::vector<std::string>& asignaturas, const std::vector<int>& creditos,
                                                   const std::vector<std::string>& requisitosPrevios) {
    std::cout << "Plan de convalidación creado: " << nombre << " para " << universidadDestino << "\n";
}

bool SistemaConvalidacion::anularSolicitudIntercambio(int idSolicitud) {
    std::cout << "Solicitud de intercambio con ID " << idSolicitud << " ha sido anulada exitosamente.\n";
    return true;
}

void SistemaConvalidacion::exportarPlanesAFichero(const std::vector<PlanConvalidacion>& planes, const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo " << nombreArchivo << "\n";
        return;
    }

    for (const auto& plan : planes) {
        archivo << "Nombre del plan: " << plan.nombre << "\n";
        archivo << "Universidad de destino: " << plan.universidadDestino << "\n";
        archivo << "Asignaturas: ";
        for (const auto& asignatura : plan.asignaturas) {
            archivo << asignatura << ", ";
        }
        archivo << "\nCréditos: ";
        for (const auto& credito : plan.creditos) {
            archivo << credito << " ";
        }
        archivo << "\nRequisitos previos: ";
        for (const auto& requisito : plan.requisitosPrevios) {
            archivo << requisito << " ";
        }
        archivo << "\n\n";
    }

    archivo.close();
    std::cout << "Planes exportados exitosamente a " << nombreArchivo << "\n";
}





