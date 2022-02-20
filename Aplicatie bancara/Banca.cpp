#include "Banca.h"
#include <string>
#include "Persoana.h"

Banca::Banca()
{

}

void Banca::getClienti()
{
	for (int i = 0; i < clienti.size(); i++) {
		cout << i + 1 << " "  << clienti[i].getNume() << " " << clienti[i].getPrenume() << endl;
	}
}

void Banca::transfer()
{
	getClienti();
	int indexClientTrimis, indexClientPrimit,indexContTrimis,indexContPrimit;
	float sumaDeTransferat;
	cout << "introduceti indexul clientului care vrea sa trimita banii "<<endl;
	cin >> indexClientTrimis;
	if (indexClientTrimis <= clienti.size()) {
		cout << "Introduceti indexul clientului care trebuie sa primeasca banii " << endl;
		cin >> indexClientPrimit;
		if (indexClientPrimit <= clienti.size()) {
			clienti[indexClientTrimis-1].getConturi();
			cout << "Introduceti indexul contului din care vreti sa fie luati banii " << endl;
			cin >> indexContTrimis;
			if (indexContTrimis <= clienti[indexContTrimis - 1].numarConturi()) {
				clienti[indexClientPrimit -1].getConturi();
				cout << "Introduceti indexul contului in care vreti sa fie adaugati banii" << endl;
				cin >> indexContPrimit;
				if (indexContPrimit <= clienti[indexContPrimit - 1].numarConturi()) {
					cout << "Introduceti suma pe care doriti sa o transferati" << endl;
					cin >> sumaDeTransferat;
					clienti[indexClientTrimis - 1].retrageBani(indexContTrimis-1, sumaDeTransferat);
					clienti[indexClientPrimit - 1].depuneBani(indexContPrimit-1, sumaDeTransferat);
				}
				else cout << "Contul selectat nu exista" << endl;

			}
			else cout << "Contul selectat nu exista" << endl;
		}
		else cout << "Clientul cu acest numar nu exista" << endl;

	}
	else cout << "Clientul cu acest numar nu exista" << endl;


}

void Banca::adaugaClient()
{
	string nume, prenume;
	cout << "Nume: " << endl;
	cin >> nume;
	cout << "Prenume: " << endl;
	cin >> prenume;
	Persoana persoana = Persoana(nume, prenume);
	clienti.push_back(persoana);

}

void Banca::deschideCont(int index)
{
	if (index <= clienti.size() - 1) {
	clienti[index].deschideCont();
	}
	else cout << "Clientul cu acest numar nu exista" << endl;
}

void Banca::adaugaBani(int index)
{
	if (index <= clienti.size() - 1) {
	clienti[index].depuneBani();
	}
	else cout << "Clientul cu acest numar nu exista" << endl;
}

void Banca::retrageBani(int index)
{
	if (index <= clienti.size() - 1) {
	clienti[index].retrageBani();
	}
	else cout << "Clientul cu acest numar nu exista" << endl;
}

void Banca::mutaBani(int index)
{
	if (index <= clienti.size() - 1) {
	clienti[index].transferIntreConturi();
	}
	else cout << "Clientul cu acest numar nu exista" << endl;
}

void Banca::inchideCont(int index)
{
	if (index <= clienti.size() - 1) {
		clienti[index].inchideCont();
	}
}

void Banca::calculeazaSold(int index)
{
	if (index <= clienti.size() - 1) {
		cout << clienti[index].calculeazaFonduriTotale() << endl;
	}
	else cout << "Clientul cu acest numar nu exista" << endl;
}
