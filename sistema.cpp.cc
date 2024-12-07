#include "sistema.h"

using namespace std;

/* Implementación de la clase Curso */
Curso::Curso(const string& nombreCurso, int creditosCurso) 
    : nombre(nombreCurso), creditos(creditosCurso) {}

void Curso::mostrar() const {
    cout << "  - " << nombre << " (" << creditos << " créditos)" << endl;
}

string Curso::getNombre() const {
    return nombre;
}

int Curso::getCreditos() const {
    return creditos;
}

/* Implementación de la clase PlanConvalidacion */
PlanConvalidacion::PlanConvalidacion(const string& nombre, const string& universidad, const string& tipoPlan)
    : nombrePlan(nombre), universidadDestino(universidad), tipo(tipoPlan) {}

void PlanConvalidacion::agregarCurso(const Curso& curso) {
    cursos.push_back(curso);
}

void PlanConvalidacion::mostrar() const {
    cout << "\nPlan: " << nombrePlan << endl;
    cout << "Universidad: " << universidadDestino << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Cursos:\n";
    for (const auto& curso : cursos) {
        curso.mostrar();
    }
}

void PlanConvalidacion::exportar(ofstream& archivo) const {
    archivo << "\nPlan: " << nombrePlan << endl;
    archivo << "Universidad: " << universidadDestino << endl;
    archivo << "Tipo: " << tipo << endl;
    archivo << "Cursos:\n";
    for (const auto& curso : cursos) {
        archivo << "  - " << curso.getNombre() << " (" << curso.getCreditos() << " créditos)\n";
    }
}

void PlanConvalidacion::modificar() {
    cout << "Modificando el plan: " << nombrePlan << endl;

    cout << "Nuevo nombre del plan (" << nombrePlan << "): ";
    getline(cin, nombrePlan);

    cout << "Nueva universidad de destino (" << universidadDestino << "): ";
    getline(cin, universidadDestino);

    cout << "Nuevo tipo de plan (" << tipo << "): ";
    getline(cin, tipo);

    cursos.clear();
    int numCursos;
    cout << "Número de cursos a incluir: ";
    cin >> numCursos;
    cin.ignore();

    for (int i = 0; i < numCursos; ++i) {
        string nombreCurso;
        int creditosCurso;
        cout << "  - Curso " << i + 1 << " Nombre: ";
        getline(cin, nombreCurso);
        cout << "    Créditos: ";
        cin >> creditosCurso;
        cin.ignore();
        agregarCurso(Curso(nombreCurso, creditosCurso));
    }
    cout << "Plan actualizado exitosamente.\n";
}

string PlanConvalidacion::obtenerNombre() const {
    return nombrePlan;
}

/* Implementación de la clase SistemaConvalidacion */
void SistemaConvalidacion::crearPlan() {
    cout << "\n--- Crear Plan de Convalidación ---" << endl;

    string nombrePlan, universidad, tipoPlan;
    cout << "Nombre del Plan: ";
    cin.ignore();
    getline(cin, nombrePlan);

    cout << "Universidad de Destino: ";
    getline(cin, universidad);

    cout << "Tipo de Plan (Cuatrimestral/Anual): ";
    getline(cin, tipoPlan);

    PlanConvalidacion nuevoPlan(nombrePlan, universidad, tipoPlan);

    int numCursos;
    cout << "Número de cursos a incluir: ";
    cin >> numCursos;
    cin.ignore();

    for (int i = 0; i < numCursos; ++i) {
        string nombreCurso;
        int creditosCurso;
        cout << "  - Curso " << i + 1 << " Nombre: ";
        getline(cin, nombreCurso);

        cout << "    Créditos: ";
        cin >> creditosCurso;
        cin.ignore();

        nuevoPlan.agregarCurso(Curso(nombreCurso, creditosCurso));
    }

    planes.push_back(nuevoPlan);
    cout << "Plan de convalidación creado exitosamente.\n";
}

void SistemaConvalidacion::modificarPlan() {
    cout << "\n--- Modificar Plan de Convalidación ---" << endl;
    cout << "Ingrese el nombre del plan a modificar: ";
    string nombrePlan;
    cin.ignore();
    getline(cin, nombrePlan);

    for (auto& plan : planes) {
        if (plan.obtenerNombre() == nombrePlan) {
            plan.modificar();
            return;
        }
    }
    cout << "Plan no encontrado.\n";
}

void SistemaConvalidacion::listarPlanes() const {
    cout << "\n--- Lista de Planes de Convalidación ---" << endl;
    if (planes.empty()) {
        cout << "No hay planes registrados.\n";
        return;
    }
    for (const auto& plan : planes) {
        plan.mostrar();
    }
}

void SistemaConvalidacion::exportarPlanes() const {
    ofstream archivo("planes_convalidacion.txt");
    if (archivo.is_open()) {
        archivo << "--- Planes de Convalidación ---\n";
        for (const auto& plan : planes) {
            plan.exportar(archivo);
        }
        archivo.close();
        cout << "\nPlanes exportados a 'planes_convalidacion.txt'.\n";
    } else {
        cout << "Error al crear el archivo.\n";
    }
}
