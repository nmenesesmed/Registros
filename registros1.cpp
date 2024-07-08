#include <iostream>
#include <string>
using namespace std;

struct Empleado {
    string nombre;
    char sexo;
    float sueldo;
};

int main() {
    int n;
    cout << "Ingrese el número de empleados: "; cin >> n;

    Empleado empleados[n];

    for (int i = 0; i < n; ++i) {
        cout << "Empleado " << i + 1 << ":\n";
        cout << "Nombre: "; cin >> empleados[i].nombre;
        cout << "Sexo (M/F): "; cin >> empleados[i].sexo;
        cout << "Sueldo: "; cin >> empleados[i].sueldo;
    }

    if (n == 0) {
        cout << "No hay empleados para procesar." << endl;
        return 0;
    }

    Empleado mayor_sueldo = empleados[0];
    Empleado menor_sueldo = empleados[0];

    for (int i = 1; i < n; ++i) {
        if (empleados[i].sueldo > mayor_sueldo.sueldo) {
            mayor_sueldo = empleados[i];
        }
        if (empleados[i].sueldo < menor_sueldo.sueldo) {
            menor_sueldo = empleados[i];
        }
    }

    cout << "\nEmpleado con mayor sueldo:\n";
    cout << "Nombre: " << mayor_sueldo.nombre << "\n";
    cout << "Sexo: " << mayor_sueldo.sexo << "\n";
    cout << "Sueldo: " << mayor_sueldo.sueldo << "\n";

    cout << "\nEmpleado con menor sueldo:\n";
    cout << "Nombre: " << menor_sueldo.nombre << "\n";
    cout << "Sexo: " << menor_sueldo.sexo << "\n";
    cout << "Sueldo: " << menor_sueldo.sueldo << "\n";

    return 0;
}