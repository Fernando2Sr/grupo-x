#include <iostream>
#include <string>
#include <vector>
#include <memory> 
#include <locale.h>

using namespace std;

class Producto {
protected:
    string nombre;
    double precio;
    string marca;

public:
    Producto(string nom, double prec, string mar) : nombre(nom), precio(prec), marca(mar) {}

    virtual void MostrarDatos() {
        cout << "Nombre: " << nombre << endl;
        cout << "Precio: Q" << precio << endl;
        cout << "Marca: " << marca << endl;
    }

    string getNombre() const {
        return nombre;
    }
};

class Electronico : public Producto {
private:
    string garantia;

public:
    Electronico(string nom, double prec, string mar, string gar) : Producto(nom, prec, mar), garantia(gar) {}

    void MostrarDatos() override {
        Producto::MostrarDatos();
        cout << "Garantía: " << garantia << endl;
    }
};

class Alimento : public Producto {
private:
    string fechaCaducidad;

public:
    Alimento(string nom, double prec, string mar, string fecha) : Producto(nom, prec, mar), fechaCaducidad(fecha) {}

    void MostrarDatos() override {
        Producto::MostrarDatos();
        cout << "Fecha de caducidad: " << fechaCaducidad << endl;
    }
};

class Ropa : public Producto {
private:
    string talla;

public:
    Ropa(string nom, double prec, string mar, string tal) : Producto(nom, prec, mar), talla(tal) {}

    void MostrarDatos() override {
        Producto::MostrarDatos();
        cout << "Talla: " << talla << endl;
    }
};

void MostrarInventario(const vector<shared_ptr<Producto>>& inventario) {
    if (inventario.empty()) {
        cout << "\nEl inventario está vacío." << endl;
        return;
    }

    cout << "\n--- Inventario ---" << endl;
    for (size_t i = 0; i < inventario.size(); ++i) {
        cout << "Producto #" << i + 1 << ":" << endl;
        inventario[i]->MostrarDatos();
        cout << "---------------------" << endl;
    }
}

void BorrarProducto(vector<shared_ptr<Producto>>& inventario) {
    if (inventario.empty()) {
        cout << "\nEl inventario está vacío. No hay productos para borrar." << endl;
        return;
    }

    string nombre;
    cout << "\nIngrese el nombre del producto a borrar: ";
    cin >> nombre;

    bool encontrado = false;
    for (auto it = inventario.begin(); it != inventario.end(); ++it) {
        if ((*it)->getNombre() == nombre) {
            inventario.erase(it);
            cout << "Producto '" << nombre << "' borrado del inventario." << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Producto '" << nombre << "' no encontrado en el inventario." << endl;
    }
}

void MostrarMenu() {
    cout << "\n--- Menú Principal ---" << endl;
    cout << "1. Crear Producto Electrónico" << endl;
    cout << "2. Crear Alimento" << endl;
    cout << "3. Crear Ropa" << endl;
    cout << "4. Mostrar Inventario" << endl;
    cout << "5. Borrar Producto" << endl;
    cout << "6. Salir" << endl;
}

int main() {
    setlocale(LC_ALL, "es_ES.UTF-8");

    vector<shared_ptr<Producto>> inventario;
    int opcion;
    string nombre, marca, garantia, fechaCaducidad, talla;
    double precio;

    do {
        MostrarMenu();
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            cout << "Ingrese el nombre del producto: ";
            cin >> nombre;
            cout << "Ingrese el precio: ";
            cin >> precio;
            cout << "Ingrese la marca: ";
            cin >> marca;
            cout << "Ingrese la garantía: ";
            cin >> garantia;
            inventario.push_back(make_shared<Electronico>(nombre, precio, marca, garantia));
            cout << "Producto Electrónico creado y añadido al inventario." << endl;
            break;
        }
        case 2: {
            cout << "Ingrese el nombre del producto: ";
            cin >> nombre;
            cout << "Ingrese el precio: ";
            cin >> precio;
            cout << "Ingrese la marca: ";
            cin >> marca;
            cout << "Ingrese la fecha de caducidad: ";
            cin >> fechaCaducidad;
            inventario.push_back(make_shared<Alimento>(nombre, precio, marca, fechaCaducidad));
            cout << "Alimento creado y añadido al inventario." << endl;
            break;
        }
        case 3: {
            cout << "Ingrese el nombre del producto: ";
            cin >> nombre;
            cout << "Ingrese el precio: ";
            cin >> precio;
            cout << "Ingrese la marca: ";
            cin >> marca;
            cout << "Ingrese la talla: ";
            cin >> talla;
            inventario.push_back(make_shared<Ropa>(nombre, precio, marca, talla));
            cout << "Ropa creada y añadida al inventario." << endl;
            break;
        }
        case 4:
            MostrarInventario(inventario);
            break;
        case 5:
            BorrarProducto(inventario);
            break;
        case 6:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opción no válida. Intente de nuevo." << endl;
        }
    } while (opcion != 6);

    return 0;
}