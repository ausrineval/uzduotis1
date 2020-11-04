
#include <iostream>
#include <string>
#include <vector>
#include <iterator>

#include "nuskaitymas.h"
#include "skaiciavimas.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;
using std::ifstream;
using std::ws;

void nuskaitymas(vector<int>& a, vector<data>& eil_vect){
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
            a.push_back(paz); //pazymiai irasomi i vektoriu
            cout << paz << " ";
        }
        cout << endl;
        string egzaminas;
        fd >> egzaminas >> ws;
        int egz;
        egz = std::stoi(egzaminas);

        stud_duomenys.egz = egz;

        // MEDIANOS SKAICIAVIMAS
        stud_duomenys.mediana = findMedian(a, a.size());
        cout << "Pazymiu mediana: " << stud_duomenys.mediana << endl;
        stud_duomenys.mediana = 0.4 * stud_duomenys.mediana + 0.6 * stud_duomenys.egz;

        // VIDURKIO SKAICIAVIMAS
        stud_duomenys.vidurkis = findMean(a, a.size());
        cout << "Pazymiu vidurkis: " << stud_duomenys.vidurkis <<endl;
        stud_duomenys.vidurkis = 0.4 * stud_duomenys.vidurkis + 0.6 * stud_duomenys.egz;

        eil_vect.push_back(stud_duomenys);
        a.clear();
    }
    fd.close();

}