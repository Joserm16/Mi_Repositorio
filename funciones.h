#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>
#include <vector>

struct PlanConvalidacion {
    std::string nombre;
    std::string universidadDestino;
    std::vector<std::string> asignaturas;
    std::vector<int> creditos;
    std::vector<std::string> requisitosPrevios;
};

class SistemaConvalidacion {
public:
    void mostrarPlanesDisponibles(const std::vector<PlanConvalidacion>& planes);
    bool inscribirseEnPlan(const PlanConvalidacion& plan, const std::vector<std::string>& asignaturasCursadas);
    void crearPlanConvalidacion(const std::string& nombre, const std::string& universidadDestino, 
                                 const std::vector<std::string>& asignaturas, const std::vector<int>& creditos,
                                 const std::vector<std::string>& requisitosPrevios);
    bool anularSolicitudIntercambio(int idSolicitud);
    void exportarPlanesAFichero(const std::vector<PlanConvalidacion>& planes, const std::string& nombreArchivo);
};

#endif // FUNCIONES_H
