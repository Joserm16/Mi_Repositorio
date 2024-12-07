#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

// Clase que representa un curso
class Curso {
private:
    std::string nombre;
    int creditos;

public:
    Curso(const std::string& nombreCurso, int creditosCurso);

    void mostrar() const;
    std::string getNombre() const;
    int getCreditos() const;
};

// Clase que representa un plan de convalidación
class PlanConvalidacion {
private:
    std::string nombrePlan;
    std::string universidadDestino;
    std::string tipo; // Cuatrimestral o Anual
    std::vector<Curso> cursos;

public:
    PlanConvalidacion(const std::string& nombre, const std::string& universidad, const std::string& tipoPlan);

    void agregarCurso(const Curso& curso);
    void mostrar() const;
    void exportar(std::ofstream& archivo) const;
    void modificar();
    std::string obtenerNombre() const;
};

// Clase principal para gestionar el sistema de convalidación
class SistemaConvalidacion {
private:
    std::vector<PlanConvalidacion> planes;

public:
    void crearPlan();
    void modificarPlan();
    void listarPlanes() const;
    void exportarPlanes() const;
};

#endif
