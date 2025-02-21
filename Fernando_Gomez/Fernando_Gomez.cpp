#include <iostream>
#include <string>

using namespace std;

class vehiculo {
private:
	string marca;
	int ano;

public: //comentario
	vehiculo(string _marca, int _ano) {
		marca = _marca;
		ano = _ano;
	}
	void mostrarDatos() {
		cout << "Marca: " << marca << ", Año: " << ano << endl;
	}
};
class Carro : public vehiculo {
private:
	string combustible;

public:
	Carro(string _marca, int _ano, string _combustible) :
		vehiculo(_marca, _ano) {
		combustible = _combustible;
	}

	void mostrarTipoCombustible() {
		mostrarDatos();
		cout << "tipo de combustible:" << combustible <<
			endl;
	}
};

int main() {
	string marca, combustible;
	int ano;

	cout << "Ingrese la marca del carro: ";
	cin >> marca;
	cout << "Ingrese el año del carro: ";
	cin >> ano;
	cout << "Ingrese el tipo de combustible: ";
	cin >> combustible;

	Carro miCarro(marca, ano, combustible);

	miCarro.mostrarTipoCombustible();

	return 0;
}