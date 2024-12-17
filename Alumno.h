#ifndef ALUMNO_H
#define ALUMNO_H

#include "Solicitud.h"
#include <vector>
#include <string>

class Alumno {
private:
    std::string nombre;
    std::vector<Solicitud> solicitudes;

public:
    // Constructor
    Alumno(std::string nombreAlumno);

    // Métodos para cargar y guardar solicitudes
    void cargarSolicitudesDesdeFichero(const std::string& fichero);
    void guardarSolicitudesEnFichero(const std::string& fichero) const;

    // Métodos de funcionalidad
    void mostrarSolicitudesActivas() const;
    void anularSolicitud(const std::string& idSolicitud, const std::string& ficheroAnulaciones);
};

#endif
