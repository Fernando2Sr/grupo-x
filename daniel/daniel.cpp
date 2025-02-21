#include <iostream>
#include <string>

using namespace std;

// Clase base (padre)
class Celular {
protected:
    string marca;
    string modelo;

public:
    Celular(string m, string mod) : marca(m), modelo(mod) {}

    virtual void mostrarInfo() {
        cout << "Marca: " << marca << ", Modelo: " << modelo << endl;
    }

    virtual void sistemaOperativo() = 0; // Método puro (hace la clase abstracta)
};

// Clase derivada Android
class Android : public Celular {
private:
    string versionAndroid;

public:
    Android(string m, string mod, string version) : Celular(m, mod), versionAndroid(version) {}

    void sistemaOperativo() override {
        cout << "Este es un celular Android con version " << versionAndroid << endl;
    }
};

// Clase derivada iPhone
class iPhone : public Celular {
private:
    string versioniOS;

public:
    iPhone(string m, string mod, string version) : Celular(m, mod), versioniOS(version) {}

    void sistemaOperativo() override {
        cout << "Este es un iPhone con iOS version " << versioniOS << endl;
    }
};


int main() {
    Android samsung("Samsung", "Galaxy S23", "13.0");
    iPhone apple("Apple", "iPhone 14", "16.3");

    samsung.mostrarInfo();
    samsung.sistemaOperativo();

    apple.mostrarInfo();
    apple.sistemaOperativo();

    return 0;
}

