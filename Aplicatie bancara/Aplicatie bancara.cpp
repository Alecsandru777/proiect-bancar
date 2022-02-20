#include "Banca.h"
#include "Cont.h"
#include "Persoana.h"
#include <iostream>

int main()
{


    Banca* banca = new Banca();
    Persoana* client = new Persoana();

    while (1) {
        int x;
        cout << "Optiuni disponibile: " << endl;
        cout << "1.Adauga client" << endl;
        cout << "2.Deschide Cont" << endl;
        cout << "3.Depune bani" << endl;
        cout << "4.Retrage bani" << endl;
        cout << "5.Transfera bani dintr-un cont in altul" << endl;
        cout << "6.Inchide cont" << endl;
        cout << "7.Calculeaza sold total" << endl;
        cout << "8.Efectueaza transfer bancar" << endl;
        cout << "Pentru a inchide programul introduceti 0" << endl;
        cin >> x;
        if (x == 1) {
            banca->adaugaClient();
        }
        if (x == 2) {
            int index;
            banca->getClienti();
            cout << "selectati clientul caruia vreti sa ii deschideti un cont" << endl;
            cin >> index;
            banca->deschideCont(index-1);
        }
        if (x == 3) {
            int index;
            banca->getClienti();
            cout << "selectati clientul care vrea sa depuna bani" << endl;
            cin >> index;
            banca->adaugaBani(index-1);
        }
        if (x == 4) {
            int index;
            banca->getClienti();
            cout << "Selectati clientul care vrea sa retraga bani" << endl;
            cin >> index;
            banca->retrageBani(index-1);
        }
        if (x == 5) {
            int index;
            banca->getClienti();
            cout << "Selectati clientul care vrea sa mute banii" << endl;
            cin >> index;
            banca->mutaBani(index-1);
        }
        if (x == 6) {
            int index;
            banca->getClienti();
            cout << "Selectati clientul care vrea sa isi inchida contul" << endl;
            cin >> index;
            banca->inchideCont(index-1);
        }
        if (x == 7) {
            int index;
            banca->getClienti();
            cout << "Selectati clientul al carui sold doriti sa il calculati" << endl;
            cin >> index;
            banca->calculeazaSold(index-1);
        }
        if (x == 8) {
            banca->transfer();
        }
        if (x == 0) {
            break;
        }

    }
   
    
}

