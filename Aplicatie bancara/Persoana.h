#pragma once

#include "Cont.h"
#include <vector>
#include <string>

using namespace std;
class Persoana {

	string nume;
	string prenume;

	vector<Cont> conturi;

public:

	Persoana();
	Persoana(string nume, string prenume);

	void deschideCont();

	void depuneBani();
	void depuneBani(int indexCont, int SumaDeTransferat);

	void retrageBani();
	void retrageBani(int indexCont, int sumaDeTransferat);

	void getConturi();
	float calculeazaFonduriTotale();

	void inchideCont();

	void transferIntreConturi();

	int numarConturi();

	string getNume();
	string getPrenume();
};