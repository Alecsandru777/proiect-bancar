#include "Persoana.h"
#include "Cont.h"
#include <iostream>

Persoana::Persoana()
{
	this->nume = "-";
	this->prenume = "-";
}
Persoana::Persoana(string nume, string prenume) {
	this->nume = nume;
	this->prenume = prenume;

}

void Persoana::deschideCont()
{
	Cont cont = Cont();
	conturi.push_back(cont);
}

void Persoana::depuneBani()
{
	int numarCont;
	float sumaDeDepus;
	cout << "selecati contul: " << endl;
	for (int i = 0; i < conturi.size(); i++) {
		cout << "contul numarul" << i + 1 << ": " << "sold: " << conturi[i].getSold() << endl;
	}
	cin >> numarCont;
	if (numarCont <= conturi.size()) {
		cout << "Introduceti suma pe care vreti sa o depundeti" << endl;
		cin >> sumaDeDepus;
		conturi[numarCont - 1].adaugaBani(sumaDeDepus);
	}
	else cout << "Contul introdus nu exista" << endl;


}

void Persoana::depuneBani(int indexCont, int SumaDeTransferat)
{
	conturi[indexCont].adaugaBani(SumaDeTransferat);
}

void Persoana::retrageBani()
{
	int numarCont;
	int sumaDeRetras;
	cout << "selecati contul: " << endl;
	for (int i = 0; i < conturi.size(); i++) {
		cout << "contul numarul" << i + 1 << ": " << "sold: " << conturi[i].getSold();
	}
	cin >> numarCont;
	if (numarCont <= conturi.size()) {
		cout << "Introduceti suma pe care vreti sa o retrageti" << endl;
		cin >> sumaDeRetras;
		conturi[numarCont - 1].retrageBani(sumaDeRetras);
	}
	else cout << "Contul introdus nu exista" << endl;
	
}

void Persoana::retrageBani(int indexCont, int sumaDeTransferat)
{
	conturi[indexCont].retrageBani(sumaDeTransferat);
}

void Persoana::getConturi()
{
	for (int i = 0; i < conturi.size(); i++) {
		cout << "Contul numarul " << i+1 << "are soldul " << conturi[i].getSold() << endl;
	}
}

float Persoana::calculeazaFonduriTotale()
{
	float suma = 0;
	for (int i = 0; i < conturi.size(); i++) {
		suma = suma + conturi[i].getSold();
	}
	return suma;
}

void Persoana::inchideCont()
{
	int index;
	for (int i = 0; i < conturi.size(); i++) {
		cout << "Contul numarul " << i + 1 << "are soldul " << conturi[i].getSold() << endl;
	}
	cout << "Introduceti numarul contului pe care vreti sa il stergeti." << endl;
	cout << "Fondurile din acesta vor fi transferate in contul numarul 1" << endl;
	cin >> index;
	if (index <= conturi.size()) {
		conturi[0].adaugaBani(conturi[index-1].getSold());
		conturi.erase(conturi.begin() + index-1);
	}
	else cout << "Contul introdus nu exista" << endl;
}

void Persoana::transferIntreConturi()
{
	int indexTrimis,indexPrimit;
	float sumaDeTransferat;
	for (int i = 0; i < conturi.size(); i++) {
		cout << "Contul numarul " << i + 1 << "are soldul " << conturi[i].getSold() << endl;
	}
	cout << "Introduceti numarul contului din care vreti sa mutati banii";
	cin >> indexTrimis;
	if (indexTrimis < conturi.size()) {
		cout << "Introduceti numarul contului in care vreti sa mutati banii";
		cin >> indexPrimit;
		if (indexPrimit < conturi.size()) {
			cout << "Introduceti suma pe care vreti sa o transferati" << endl;
			cin >> sumaDeTransferat;
			conturi[indexTrimis - 1].retrageBani(sumaDeTransferat);
			conturi[indexPrimit - 1].adaugaBani(sumaDeTransferat);
		}
	}
}

string Persoana::getNume()
{
	return nume;
}

string Persoana::getPrenume()
{
	return prenume;
}
int Persoana::numarConturi() {
	return conturi.size();
}