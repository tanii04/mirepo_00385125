#include <iostream>
#include <string>

using namespace std;

struct Direccion {
    string calle;
    int numero;
    string ciudad;
};

struct Estudiante {
    string nombre;
    int edad;
    float calificaciones[5];
    Direccion direccion;
};

void ingresarEstudiantes(Estudiante* estudiantes, int cantidad) 
{
    for (int i = 0; i < cantidad; i++) {
        cout << endl << "Ingrese los datos del estudiante " << i + 1 << "." << endl;
        cout << "Nombre Completo: ";
        cin.ignore(); 
        getline(cin, estudiantes[i].nombre);

        cout << "Edad: ";
        cin >> estudiantes[i].edad;

        cout << endl << "Ingrese las 5 calificaciones." << endl;
        for (int j = 0; j < 5; j++) {
            cout << "Calificacion " << j + 1 << ": ";
            cin >> estudiantes[i].calificaciones[j];
        }

        cout << endl << "Direccion." <<  endl;
        cout << "Calle: ";
        cin.ignore();
        getline(cin, estudiantes[i].direccion.calle);
        cout << "Numero de casa: ";
        cin >> estudiantes[i].direccion.numero;
        cout << "Ciudad: ";
        cin.ignore();
        getline(cin, estudiantes[i].direccion.ciudad);
    }
}


void mostrarEstudiantes(Estudiante* estudiantes, int cantidad) 
{
    cout << endl << "Lista de estudiantes. " << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << endl << "Estudiante " << i + 1 << ": " << endl << endl;
        cout << "Nombre: " << estudiantes[i].nombre << endl;
        cout << "Edad: " << estudiantes[i].edad << endl;
        cout << "Calificaciones: " << endl;
        for (int j = 0; j < 5; j++) {
            cout << estudiantes[i].calificaciones[j] << " " << endl;
        }
        cout << "Direccion: " << estudiantes[i].direccion.calle << " "
             << estudiantes[i].direccion.numero << ", "
             << estudiantes[i].direccion.ciudad << endl;
    }
}


void buscarEstudiante(Estudiante* estudiantes, int cantidad) 
{
    string nombreBuscado;
    bool encontrado = false;
    cout << endl << "Ingrese el nombre del estudiante a buscar: ";
    cin.ignore();
    getline(cin, nombreBuscado);

    for (int i = 0; i < cantidad; i++) {
        if (estudiantes[i].nombre == nombreBuscado) {
            cout << "Estudiante encontrado." << endl << endl;
            cout << "Nombre: " << estudiantes[i].nombre << endl;
            cout << "Edad: " << estudiantes[i].edad << endl;
            cout << "Calificaciones: " << endl;
            for (int j = 0; j < 5; j++) {
                cout << estudiantes[i].calificaciones[j] << " " << endl;
            }
            cout << "Direccion: " << estudiantes[i].direccion.calle << " "
                 << estudiantes[i].direccion.numero << ", "
                 << estudiantes[i].direccion.ciudad << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "No se encontro ningun estudiante con ese nombre.";
    }
}


void modificarEstudiante(Estudiante* estudiantes, int cantidad) 
{
    string nombreBuscado;
    bool encontrado = false;
    cout << endl << "Ingrese el nombre del estudiante a modificar: ";
    cin.ignore();
    getline(cin, nombreBuscado);

    for (int i = 0; i < cantidad; i++) {
        if (estudiantes[i].nombre == nombreBuscado) {
            cout << endl << "Modificando los datos de " << estudiantes[i].nombre << endl;
            cout << "Nueva edad: ";
            cin >> estudiantes[i].edad;

            cout << "Nuevas calificaciones: " << endl;
            for (int j = 0; j < 5; j++) {
                cout << "Calificacion " << j + 1 << ": ";
                cin >> estudiantes[i].calificaciones[j];
            }

            cout << endl <<  "Nueva direccion " << endl;
            cout << "Calle: ";
            cin.ignore();
            getline(cin, estudiantes[i].direccion.calle);
            cout << "Numero de casa: ";
            cin >> estudiantes[i].direccion.numero;
            cout << "Ciudad: ";
            cin.ignore();
            getline(cin, estudiantes[i].direccion.ciudad);

            encontrado = true;
            cout << "Datos actualizados correctamente." << endl;
            break;
        }
    }

    if (!encontrado) {
        cout << "No se encontro ningun estudiante con ese nombre.";
    }
}

int main() {
    int opcion;
    int cantidad = 0;
    Estudiante* estudiantes = nullptr; 

    do {
        cout << endl << "MENU" << endl;
        cout << "1. Ingresar estudiantes" << endl;
        cout << "2. Mostrar estudiantes" << endl;
        cout << "3. Buscar estudiante" << endl;
        cout << "4. Modificar estudiante" << endl;
        cout << "5. Salir" << endl;
        cout << endl << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << endl << "Ingrese la cantidad de estudiantes: ";
            cin >> cantidad;
            estudiantes = new Estudiante[cantidad];
            ingresarEstudiantes(estudiantes, cantidad);
            break;
        case 2:
            if (estudiantes != nullptr)
                mostrarEstudiantes(estudiantes, cantidad);
            else
                cout << "No hay estudiantes registrados." << endl;
            break;
        case 3:
            if (estudiantes != nullptr)
                buscarEstudiante(estudiantes, cantidad);
            else
                cout << "No hay estudiantes registrados." << endl;
            break;
        case 4:
            if (estudiantes != nullptr)
                modificarEstudiante(estudiantes, cantidad);
            else
                cout << "No hay estudiantes registrados." << endl;
            break;
        case 5:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion no valida." << endl;
        }

    } while (opcion != 5);

    delete[] estudiantes;
    return 0;
}
