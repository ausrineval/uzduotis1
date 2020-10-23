#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <sstream>

using namespace std;

#include "0.3.h"

//SPAUSDINIMAS
void spausdinimas(vector <data>& a, int n, int gal){
    cout << endl << endl;
    cout << std::left
         << std::setw(20) << "Vardas"
         << std::setw(20) << "Pavarde" ;
    switch(gal){
        case 0 :
            cout << std::setw(20) << "Galutinis (Vid.)";
        case 1 :
            cout << std::setw(20) << "Galutinis (Med.)";
        default :
            cout << std::setw(20) << endl;
    }
    cout << "------------------------------------------------------------------------" << endl;
    for (int j = 0; j < n; j++)
    {
        cout << std::left
             << std::setw(20) << a[j].vard
             << std::setw(20) << a[j].pavard ;
        switch(gal){
            case 0 :
                cout << std::setw(20) << a[j].vidurkis << endl;
            case 1 :
                cout << std::setw(20) << a[j].mediana << endl;
            default :
                break;
        }
    }
}

void nuskaitymas(vector<int> ndpaz, vector<data>& eil_vect){
    //DUOMENU NUSKAITYMAS
    ifstream fd("C:\\Users\\ausri\\CLionProjects\\untitled\\kursiokai.txt");
    if (fd.fail()) {
        cout << "Failas (kursiokai.txt) nerastas." << endl;
        exit(1);
    }
    if (fd.is_open()) cout << "Sekmingai atidaryta \n";

    while (!fd.eof()) {
        data stud_duomenys;
        fd >> stud_duomenys.vard >> ws >> stud_duomenys.pavard >> ws;
        string pazymys;

        for (int j = 0; j < ndsk() - 3; ++j) { //nuskaito 5 pazymius
            fd >> pazymys >> ws;
            int paz;
            paz = std::stoi(pazymys);
            ndpaz.push_back(paz); //pazymiai irasomi i vektoriu
            cout << paz << " ";
        }
        cout << endl;
        string egzaminas;
        fd >> egzaminas >> ws;
        int egz;
        egz = std::stoi(egzaminas);

        stud_duomenys.egz = egz;

        // MEDIANOS SKAICIAVIMAS
        stud_duomenys.mediana = findMedian(ndpaz, ndpaz.size());
        cout << "Pazymiu mediana: " << stud_duomenys.mediana << endl;
        stud_duomenys.mediana = 0.4 * stud_duomenys.mediana + 0.6 * stud_duomenys.egz;

        // VIDURKIO SKAICIAVIMAS
        stud_duomenys.vidurkis = findMean(ndpaz, ndpaz.size());
        cout << "Pazymiu vidurkis: " << stud_duomenys.vidurkis <<endl;
        stud_duomenys.vidurkis = 0.4 * stud_duomenys.vidurkis + 0.6 * stud_duomenys.egz;

        eil_vect.push_back(stud_duomenys);
        ndpaz.clear();
    }
    fd.close();

}