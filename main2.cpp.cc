#include "sistema.h"

using namespace std;

int main() {
    SistemaConvalidacion sistema;
    int opcion;

    do {
        cout << "\n--- Sistema de Gestión de Planes de Convalidación ---" << endl;
        cout << "1. Crear Plan de Convalidación\n";
        cout << "2. Modificar Plan de Convalidación\n";
        cout << "3. Listar Planes\n";
        cout << "4. Exportar Planes\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                sistema.crearPlan();
                break;
            case 2:
                sistema.modificarPlan();
                break;
            case 3:
                sistema.listarPlanes();
                break;
            case 4:
                sistema.exportarPlanes();
                break;
            case 5:
                cout << "Saliendo del sistema.\n";
                break;
            default:
                cout << "Opción inválida. Intente nuevamente.\n";
        }
    } while (opcion != 5);

    return 0;
}
