#include <iostream>
#include <string>

using namespace std;

struct Persona {
    string nombre;
    string dni;
    int edad;
};

int main() {
    int n;
    cout << "Ingrese el numero de personas: ";
    cin >> n;

    if (n <= 0) {
        cout << "El numero de personas debe ser mayor a 0." << endl;
        return 1;
    }

    // Usar un arreglo estático lo suficientemente grande
    Persona personas[100];

    int mayores_50 = 0;
    int suma_edades = 0;

    for (int i = 0; i < n; ++i) {
        cout << "Persona " << i + 1 << ":\n";
        cout << "Nombre: ";
        cin >> personas[i].nombre;
        cout << "DNI: ";
        cin >> personas[i].dni;
        cout << "Edad: ";
        cin >> personas[i].edad;

        if (personas[i].edad > 50) {
            mayores_50++;
        }
        suma_edades += personas[i].edad;
    }

    float promedio_edades = (float)suma_edades / n;

    cout << "\nCantidad de personas mayores de 50 anios: " << mayores_50 << "\n";
    cout << "Promedio de edades: " << promedio_edades << "\n";
    cout << "\nDatos de las personas ingresadas:\n";

    for (int i = 0; i < n; ++i) {
        cout << "Persona " << i + 1 << ":\n";
        cout << "Nombre: " << personas[i].nombre << "\n";
        cout << "DNI: " << personas[i].dni << "\n";
        cout << "Edad: " << personas[i].edad << "\n";
    }

    return 0;
}
