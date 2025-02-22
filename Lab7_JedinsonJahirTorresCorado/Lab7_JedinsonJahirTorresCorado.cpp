#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Empleados {
protected:
    string Nombre, Puesto;
    double Salario;

public:
    Empleados(string nombre, string puesto, double salario)
        : Nombre(nombre), Puesto(puesto), Salario(salario) {
    }

    virtual void MostrarDatos() {
        cout << "Nombre: " << Nombre << endl;
        cout << "Puesto: " << Puesto << endl;
        cout << "Salario: " << Salario << endl;
    }

    virtual ~Empleados() {}
};

class Gerente : public Empleados {
private:
    string AreaDegerencia;

public:
    Gerente(string nombre, string puesto, string areaDegerencia, double salario)
        : Empleados(nombre, puesto, salario), AreaDegerencia(areaDegerencia) {
    }

    void MostrarDatos() override {
        Empleados::MostrarDatos();
        cout << "Área de gerencia: " << AreaDegerencia << endl;
    }
};

class Obrero : public Empleados {
private:
    string AreadelObrero;

public:
    Obrero(string nombre, string puesto, double salario, string areadelObrero)
        : Empleados(nombre, puesto, salario), AreadelObrero(areadelObrero) {
    }

    void MostrarDatos() override {
        Empleados::MostrarDatos();
        cout << "Área del obrero: " << AreadelObrero << endl;
    }
};

class Servicios : public Empleados {
private:
    string AreadeServicio;

public:
    Servicios(string nombre, string puesto, double salario, string areadeServicios)
        : Empleados(nombre, puesto, salario), AreadeServicio(areadeServicios) {
    }

    void MostrarDatos() override {
        Empleados::MostrarDatos();
        cout << "Área de servicio: " << AreadeServicio << endl;
    }
};

vector<Empleados*> empleados;

void AgregarEmpleado() {
    int tipo;
    string nombre, puesto, area;
    double salario;

    cout << "Seleccione el tipo de empleado: \n1. Gerente\n2. Obrero\n3. Servicio\nOpción: ";
    cin >> tipo;
    cin.ignore();

    cout << "Nombre: ";
    getline(cin, nombre);
    cout << "Puesto: ";
    getline(cin, puesto);
    cout << "Salario: ";
    cin >> salario;
    cin.ignore();

    if (tipo == 1) {
        cout << "Área de gerencia: ";
        getline(cin, area);
        empleados.push_back(new Gerente(nombre, puesto, area, salario));
    }
    else if (tipo == 2) {
        cout << "Área del obrero: ";
        getline(cin, area);
        empleados.push_back(new Obrero(nombre, puesto, salario, area));
    }
    else if (tipo == 3) {
        cout << "Área de servicio: ";
        getline(cin, area);
        empleados.push_back(new Servicios(nombre, puesto, salario, area));
    }
    else {
        cout << "Opción inválida. Intente de nuevo." << endl;
    }
}

int main() {
    int opcion;
    do {
        cout << "\nMenú de empleados:\n1. Agregar Empleado\n2. Salir\nOpción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1:
            AgregarEmpleado();
            break;
        case 2:
            cout << "Saliendo...\n";
            break;
        default:
            cout << "Opción inválida, intente nuevamente.\n";
        }
    } while (opcion != 2);

    // Liberar memoria antes de salir
    for (auto emp : empleados) {
        delete emp;
    }
    empleados.clear();

    return 0;
}

