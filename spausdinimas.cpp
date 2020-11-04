#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "nuskaitymas.h"
#include "spausdinimas.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;
using std::ifstream;
using std::ws;

bool palyginimas(const data& stud1, const data& stud2){
    if (stud1.vard != stud2.vard){
        return stud1.vard < stud2.vard;
    }
    if (stud1.vard == stud2.vard){
        return stud1.pavard < stud2.pavard;
    }
}

void spausdinimasMed(vector <data>& a, int n){
    cout << endl << endl;
    cout << std::left
         << std::setw(20) << "Vardas"
         << std::setw(20) << "Pavarde"
         << std::setw(20) << "Galutinis (Med.)"
         << std::setw(20) << endl;
    cout << "------------------------------------------------------------------------" << endl;
    for (int j = 0; j < n; j++)
    {
        cout << std::left
             << std::setw(20) << a[j].vard
             << std::setw(20) << a[j].pavard
             << std::setw(20) << a[j].mediana << endl;
    }
}

void spausdinimasVid(vector <data>& a, int n){
    cout << endl << endl;
    cout << std::left
         << std::setw(20) << "Vardas"
         << std::setw(20) << "Pavarde"
         << std::setw(20) << "Galutinis (Vid.)"
         << std::setw(20) << endl;
    cout << "------------------------------------------------------------------------" << endl;
    for (int j = 0; j < n; j++)
    {
        cout << std::left
             << std::setw(20) << a[j].vard
             << std::setw(20) << a[j].pavard
             << std::setw(20) << a[j].vidurkis << endl;
        }
}

//SPAUSDINIMAS
void spausdinimas(vector <data>& a, int n, int gal){
    try {
    sort(a.begin(), a.end(), palyginimas);
    }
    catch(std::exception e) {cout << "Ivyko rusiavimo klaida \n";}
    if (gal == 0) spausdinimasVid(a, n);
    else if (gal == 1) spausdinimasMed(a, n);
    else cout<<"Ivesta neteisinga reiksme. \n";

}
