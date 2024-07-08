#include <iostream>
#include <string>

using namespace std;

struct Atleta {
    string nombre;
    string pais;
    string disciplina;
    int medallas;
};

void mostrarAtletas(const Atleta atletas[], int numAtletas) {
    for (int i = 0; i < numAtletas; ++i) {
        cout << "Nombre: " << atletas[i].nombre << endl;
        cout << "Pais: " << atletas[i].pais << endl;
        cout << "Disciplina: " << atletas[i].disciplina << endl;
        cout << "Medallas: " << atletas[i].medallas << endl;
        cout << "-------------------------\n";
    }
}

void ordenarPorMedallas(Atleta atletas[], int numAtletas) {
    for (int i = 0; i < numAtletas - 1; ++i) {
        for (int j = i + 1; j < numAtletas; ++j) {
            if (atletas[i].medallas < atletas[j].medallas) {
                swap(atletas[i], atletas[j]);
            }
        }
    }
}

int main() {
    const int MAX_ATLETAS = 100;
    Atleta atletas[MAX_ATLETAS];
    int numeroAtletas = 0;

    cout << "Ingrese el numero de atletas: ";
    cin >> numeroAtletas;
    cin.ignore(); // Limpiar el buffer

    for (int i = 0; i < numeroAtletas && i < MAX_ATLETAS; ++i) {
        cout << "\nIngrese datos del atleta " << i + 1 << ":" << endl;
        cout << "Nombre: ";
        getline(cin, atletas[i].nombre);
        cout << "Pais: ";
        getline(cin, atletas[i].pais);
        cout << "Disciplina: ";
        getline(cin, atletas[i].disciplina);
        cout << "Medallas: ";
        cin >> atletas[i].medallas;
        cin.ignore(); // Limpiar el buffer
    }

    cout << "\nInformacion de todos los atletas:\n";
    mostrarAtletas(atletas, numeroAtletas);

    string paisBuscar;
    cout << "\nIngrese un pais para mostrar sus atletas: ";
    getline(cin, paisBuscar);

    Atleta atletasPais[MAX_ATLETAS];
    int numeroAtletasPais = 0;

    for (int i = 0; i < numeroAtletas; ++i) {
        if (atletas[i].pais == paisBuscar) {
            atletasPais[numeroAtletasPais++] = atletas[i];
        }
    }

    if (numeroAtletasPais == 0) {
        cout << "No se encontraron atletas del pais " << paisBuscar << endl;
    } else {
        cout << "\nAtletas del pais " << paisBuscar << ":\n";
        mostrarAtletas(atletasPais, numeroAtletasPais);

        ordenarPorMedallas(atletasPais, numeroAtletasPais);

        cout << "\nAtleta con mayor numero de medallas:\n";
        cout << "Nombre: " << atletasPais[0].nombre << endl;
        cout << "Medallas: " << atletasPais[0].medallas << endl;
    }

    return 0;
}
