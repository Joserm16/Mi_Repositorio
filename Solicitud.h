#ifndef SOLICITUD_H
#define SOLICITUD_H

#include <string>
#include <iostream>

class Solicitud {
private:
    std::string idSolicitud;
    std::string descripcion;
    bool activa;

public:
    // Constructor
    Solicitud(std::string id, std::string desc, bool estado = true);

    // Getters
    std::string getId() const;
    std::string getDescripcion() const;
    bool isActiva() const;

    // Método para anular la solicitud
    void anular();

    // Mostrar información de la solicitud
    void mostrar() const;

    // Serialización y deserialización
    std::string serializar() const;
    static Solicitud deserializar(const std::string& linea);
};

#endif
