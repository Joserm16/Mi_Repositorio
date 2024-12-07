#include "SolicitudIntercambio.h"

void SolicitudIntercambio::mostrar(){
    std::cout << "ID: " << id
              << ", Alumno: " << alumno
              << ", Universidad Destino: " << universidadDestino
              << ", Activa: ";
    
    if (activa) {
        std::cout << "Sí";
    } else {
        std::cout << "No";
    }
    
    std::cout << std::endl;
}

void SolicitudIntercambio::guardarEnFichero(std::string nombreFichero) {
        std::ofstream fichero(nombreFichero, std::ios::app);  // Abre el fichero en modo 'append'
        if (fichero.is_open()) {
            // Escribe los datos en el fichero
            fichero << id << "," << alumno << "," << universidadDestino << "\n";  
            std::cout << "Solicitud guardada correctamente en el fichero.\n";
        } else {
            std::cerr << "Error al abrir el fichero.\n";
        }
}