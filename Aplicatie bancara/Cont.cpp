#include "Cont.h"
#include <iostream>
using namespace std;

Cont::Cont()
{
	this->sold = 0;
}

float Cont::getSold()
{
	return sold;
}

void Cont::adaugaBani(int sumaDeDepus)
{
	sold = sold + sumaDeDepus;
}

void Cont::retrageBani(int sumaDeRetras)
{
	if (sumaDeRetras < sold) {
		sold = sold - sumaDeRetras;
	}
	else cout << "Suma pe care vreti sa o retrageti este mai mare decat cea disponibila in cont" << endl;
}
