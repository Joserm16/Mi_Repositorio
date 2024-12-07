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