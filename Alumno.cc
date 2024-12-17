#include "Alumno.h"
#include <fstream>
#include <iostream>

// Constructor
Alumno::Alumno(std::string nombreAlumno) : nombre(nombreAlumno) {}

// Cargar solicitudes desde fichero
void Alumno::cargarSolicitudesDesdeFichero(const std::string& fichero) {
    solicitudes.clear();
    std::ifstream archivo(fichero);
    std::string linea;

    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            solicitudes.push_back(Solicitud::deserializar(linea));
        }
        archivo.close();
    }
}

// Guardar solicitudes en fichero
void Alumno::guardarSolicitudesEnFichero(const std::string& fichero) const {
    std::ofstream archivo(fichero);

    if (archivo.is_open()) {
        for (const auto& solicitud : solicitudes) {
            archivo << solicitud.serializar() << std::endl;
        }
        archivo.close();
    }
}

// Mostrar solicitudes activas
void Alumno::mostrarSolicitudesActivas() const {
    std::cout << "\nSolicitudes activas:\n";
    for (const auto& solicitud : solicitudes) {
        if (solicitud.isActiva()) {
            solicitud.mostrar();
        }
    }
}

// Anular solicitud
void Alumno::anularSolicitud(const std::string& idSolicitud, const std::string& ficheroAnulaciones) {
    bool encontrada = false;

    for (auto& solicitud : solicitudes) {
        if (solicitud.getId() == idSolicitud && solicitud.isActiva()) {
            solicitud.anular();
            encontrada = true;

            // Registrar anulación
            std::ofstream archivo(ficheroAnulaciones, std::ios::app);
            if (archivo.is_open()) {
                archivo << "Solicitud anulada: " << idSolicitud << " | Alumno: " << nombre << std::endl;
                archivo.close();
            }
            std::cout << "Solicitud " << idSolicitud << " anulada con exito.\n";
            break;
        }
    }

    if (!encontrada) {
        std::cout << "No se encontro una solicitud activa con ID " << idSolicitud << ".\n";
    }
}
