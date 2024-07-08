#include <iostream>
#include <string>
using namespace std;

struct Persona {
  string nombre;
  int diaNacimiento;
  int mesNacimiento;
  int anio;
};

int main() {
  const int MAX_PERSONAS = 100;
  Persona personas[MAX_PERSONAS];
  int numPersonas = 0;

  int cantPersonas;
  cout << "Ingrese el numero de personas: ";
  cin >> cantPersonas;
  cin.ignore(); // Limpiar el buffer de entrada

  for (int i = 0; i < cantPersonas && i < MAX_PERSONAS; ++i) {
    cout << "Ingrese el nombre de la persona " << i + 1 << ": ";
    getline(cin, personas[i].nombre);

    cout << "Ingrese el dia de nacimiento de la persona " << i + 1 << ": ";
    cin >> personas[i].diaNacimiento;

    cout << "Ingrese el mes de nacimiento de la persona " << i + 1 << ": ";
    cin >> personas[i].mesNacimiento;

    cout << "Ingrese el anio de nacimiento de la persona " << i + 1 << ": ";
    cin >> personas[i].anio;

    cin.ignore(); // Limpiar el buffer de entrada
    numPersonas++;
  }

  int mesBuscado;
  do {
    cout << "Ingrese un numero de mes (0 para salir): ";
    cin >> mesBuscado;

    if (mesBuscado != 0) {
      bool encontrado = false;
      for (int i = 0; i < numPersonas; ++i) {
        if (personas[i].mesNacimiento == mesBuscado) {
          encontrado = true;
          cout << "Nombre: " << personas[i].nombre << endl;
          cout << "Fecha de nacimiento: " << personas[i].diaNacimiento << "/" << personas[i].mesNacimiento << "/" << personas[i].anio << endl;
          cout << endl;
        }
      }
      if (!encontrado) {
        cout << "No se encontraron personas con cumpleanios en el mes " << mesBuscado << "." << endl;
      }
    }
  } while (mesBuscado != 0);

  return 0;
}

