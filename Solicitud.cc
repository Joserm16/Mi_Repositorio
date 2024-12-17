#include "Solicitud.h"

// Constructor
Solicitud::Solicitud(std::string id, std::string desc, bool estado)
    : idSolicitud(id), descripcion(desc), activa(estado) {}

// Getters
std::string Solicitud::getId() const { return idSolicitud; }
std::string Solicitud::getDescripcion() const { return descripcion; }
bool Solicitud::isActiva() const { return activa; }

// Método para anular la solicitud
void Solicitud::anular() { activa = false; }

// Mostrar información
void Solicitud::mostrar() const {
    std::cout << "ID: " << idSolicitud << " | Descripcion: " << descripcion
              << " | Estado: " << (activa ? "Activa" : "Anulada") << std::endl;
}

// Serialización
std::string Solicitud::serializar() const {
    return idSolicitud + "|" + descripcion + "|" + (activa ? "1" : "0");
}

// Deserialización
Solicitud Solicitud::deserializar(const std::string& linea) {
    size_t pos1 = linea.find("|");
    size_t pos2 = linea.find("|", pos1 + 1);

    std::string id = linea.substr(0, pos1);
    std::string desc = linea.substr(pos1 + 1, pos2 - pos1 - 1);
    bool estado = linea.substr(pos2 + 1) == "1";

    return Solicitud(id, desc, estado);
}
