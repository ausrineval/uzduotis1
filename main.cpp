#include <iostream>
#include <string>
#include <vector>
#include "duomenys.h"
#include "nuskaitymas.h"
#include "skaiciavimas.h"
#include "spausdinimas.h"

using std::cout;
using std::cin;
using std::string;
using std::bool_constant;
using std::endl;
using std::vector;
using std::ifstream;
using std::ws;

int main() {
    data eil;
    vector <data> eil_vect;
    vector<int> ndpaz; //NAMU DARBU VEKTORIUS

    cout << "Jei norite faila nuskaityti, iveskite a, jei norite ivesti duomenys pats - b. \n";
    char pasirinkimas;
    cin >> pasirinkimas;
    if(pasirinkimas == 'a'){
        nuskaitymas(ndpaz, eil_vect);
    }
    else if(pasirinkimas = 'b'){

        // DUOMENU IVEDIMAS
        int n = 0;
        cout << "Kiek studentu duomenu ivesite? \n";
        cin >> n;
        for (int a = 0; a < n; a++)
        {
            cout << "Iveskite duomenis (vardas, pavarde): \n";
            cin >> eil.vard >> eil.pavard;

            cout << "Jei norite generuoti egzamino pazymi atsitiktinai, parasykite -1. Jei ne, iveskite pazymi paprastai. \n";
            int egz_paz=0;
            cin >> egz_paz;
            if (egz_paz ==-1){
                eil.egz = random();
                cout << "Generuotas egzamino pazymys: " << eil.egz << endl;
            }
            else eil.egz = egz_paz;

            char pazymiai;
            cout << "Jei norite ivesti pazymius paprastai, iveskite 'a', jei norite atsitiktinai generuotu pazymiu - 'b'. \n";
            cin >> pazymiai;
            int sk =1;
            int end; // namu darbo pazymys

            if (pazymiai=='a'){
                // RANKINIS NAMU DARBU PAZYMIU IVEDIMAS
                cout << "Iveskite studento nd pazymius, jei baigete vesti, parasykite '-1'. \n";
                do {
                    cin >> end;
                    if (end != -1) {
                        eil.nd[sk] = end;
                        ndpaz.push_back(eil.nd[sk]); //pazymiai surasomi i vektoriu
                        sk = sk + 1;
                    }
                    else {
                        cout << "Aciu uz suvestus duomenis apie " << eil.vard << " " << eil.pavard << "." << endl;
                    }
                } while (end != -1);
            }
            else if (pazymiai =='b') { //ATSITIKTINIAI PAZYMIAI
                cout << "Iveskite bet koki skaiciu ir bus generuojamas atsitiktinis pazymys, jei baigete vesti, parasykite '-1'. \n";
                do {
                    cin >> end;
                    if (end != -1) {
                        eil.nd[sk] = random();
                        ndpaz.push_back(eil.nd[sk]); //pazymiai surasomi i vektoriu
                        sk = sk + 1;
                    }
                    else {
                        cout << "Aciu uz suvestus duomenis apie " << eil.vard << " " << eil.pavard << "." << endl;
                    }
                } while (end != -1);
            }
            else {
                cout << "Ivesta neteisinga reiksme. \n";
                return 0;
            }

            //PAZYMIU SPAUSDINIMAS
            cout << "Namu darbu pazymiai: ";
            for(int i=0; i<sk-1; i++){
                cout << ndpaz[i] << " ";
            }
            cout << endl;

            // MEDIANOS SKAICIAVIMAS
            eil.mediana = findMedian(ndpaz, ndpaz.size());
            cout << "Pazymiu mediana: " << eil.mediana << endl;
            eil.mediana = 0.4 * eil.mediana + 0.6 * eil.egz;

            // VIDURKIO SKAICIAVIMAS
            eil.vidurkis = findMean(ndpaz, ndpaz.size());
            cout << "Pazymiu vidurkis: " << eil.vidurkis <<endl;
            eil.vidurkis = 0.4 * eil.vidurkis + 0.6 * eil.egz;

            eil_vect.push_back(eil);
            ndpaz.clear();
        }
    }
    else cout<< "Ivesta neteisinga reiksme \n";

    cout << "Studentu skaicius: " << eil_vect.size() << endl;
    // SPAUSDINIMAS
    cout << "Jei norite, kad butu spausdinamas galutinis pazymys pagal vidurki, iveskite 0, "
         << "jei pagal mediana, iveskite 1." << endl;
    int galutinis;
    cin >> galutinis;
    int n = eil_vect.size(); //apskaiciuoti studentu skaiciu

    spausdinimas(eil_vect, n, galutinis);

    eil_vect.clear();

}
