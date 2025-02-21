#include <iostream>
using namespace std;

// Clase base: Pelota
class Pelota {
private:
    string marca;
    int año;

public:
    // Constructor de la clase base
    Pelota(string _marca, int _año) {
        marca = _marca;
        año = _año;
    }

    // Método para mostrar los datos de la pelota
    void mostrarDatos() {
        cout << "Marca: " << marca << ", Año: " << año << endl;
    }
};

// Clase derivada 1: Pelota_Futbol
class Pelota_Futbol : public Pelota {
private:
    string tamaño;

public:
    // Constructor de la clase derivada
    Pelota_Futbol(string _marca, int _año, string _tamaño) : Pelota(_marca, _año) {
        tamaño = _tamaño;
    }

    // Método para mostrar el tipo y tamaño de la pelota
    void mostrarTipoTamaño() {
        mostrarDatos(); // Llama al método de la clase base
        cout << "Tamaño: " << tamaño << endl;
    }
};

// Clase derivada 2: Pelota_Basquet
class Pelota_Basquet : public Pelota {
private:
    string material;

public:
    // Constructor de la clase derivada
    Pelota_Basquet(string _marca, int _año, string _material) : Pelota(_marca, _año) {
        material = _material;
    }

    // Método para mostrar el material de la pelota
    void mostrarMaterial() {
        mostrarDatos(); // Llama al método de la clase base
        cout << "Material: " << material << endl;
    }
};

// Clase derivada 3: Pelota_Tenis
class Pelota_Tenis : public Pelota {
private:
    string superficie;

public:
    // Constructor de la clase derivada
    Pelota_Tenis(string _marca, int _año, string _superficie) : Pelota(_marca, _año) {
        superficie = _superficie;
    }

    // Método para mostrar la superficie de la pelota
    void mostrarSuperficie() {
        mostrarDatos(); // Llama al método de la clase base
        cout << "Superficie: " << superficie << endl;
    }
};

// Función para mostrar el menú
void mostrarMenu() {
    cout << "\n--- MENÚ ---" << endl;
    cout << "1. Crear Pelota de Fútbol" << endl;
    cout << "2. Crear Pelota de Básquet" << endl;
    cout << "3. Crear Pelota de Tenis" << endl;
    cout << "4. Salir" << endl;
    cout << "Ingrese una opción: ";
}

int main() {
    int opcion;
    string marca, tamaño, material, superficie;
    int año;

    do {
        mostrarMenu(); // Mostrar el menú
        cin >> opcion;

        switch (opcion) {
        case 1: {
            cout << "Ingrese la marca de la pelota de fútbol: ";
            cin >> marca;
            cout << "Ingrese el año de creación: ";
            cin >> año;
            cout << "Ingrese el tamaño de la pelota: ";
            cin >> tamaño;

            Pelota_Futbol pelotaFutbol(marca, año, tamaño);
            pelotaFutbol.mostrarTipoTamaño();
            break;
        }

        case 2: {
            cout << "Ingrese la marca de la pelota de básquet: ";
            cin >> marca;
            cout << "Ingrese el año de creación: ";
            cin >> año;
            cout << "Ingrese el material de la pelota: ";
            cin >> material;

            Pelota_Basquet pelotaBasquet(marca, año, material);
            pelotaBasquet.mostrarMaterial();
            break;
        }

        case 3: {
            cout << "Ingrese la marca de la pelota de tenis: ";
            cin >> marca;
            cout << "Ingrese el año de creación: ";
            cin >> año;
            cout << "Ingrese la superficie de la pelota: ";
            cin >> superficie;

            Pelota_Tenis pelotaTenis(marca, año, superficie);
            pelotaTenis.mostrarSuperficie();
            break;
        }

        case 4: {
            cout << "Saliendo del programa..." << endl;
            break;
        }

        default: {
            cout << "Opción no válida. Intente de nuevo." << endl;
            break;
        }
        }
    } while (opcion != 4);

    return 0;
}