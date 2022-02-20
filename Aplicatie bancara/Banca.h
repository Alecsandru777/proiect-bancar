#pragma once
#include "Persoana.h"
#include "Cont.h"
#include <vector>
#include <iostream>

class Banca {
	vector<Persoana> clienti;

public:
	Banca();
	void getClienti();
	void transfer();
	void adaugaClient();
	void deschideCont(int index);
	void adaugaBani(int index);
	void retrageBani(int index);
	void mutaBani(int index);
	void inchideCont(int index);
	void calculeazaSold(int index);

};