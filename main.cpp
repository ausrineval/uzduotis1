#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <sstream>

using std::cout;
using std::cin;
using std::string;
using std::bool_constant;
using std::endl;
using std::vector;
using std::ifstream;
using std::ws;

// DUOMENYS
struct data {
    string vard, pavard;
    int nd[10], egz = 0;
    float vidurkis = 0, mediana = 0;
};

double ndsk();
void spausdinimas(vector<data> a, int n, int gal);
double findMean(vector<int> v, int n);
double findMedian( vector<int> v, int n);
void nuskaitymas(vector<int> ndpaz, vector<data> eil_vect);

int main() {
    data eil;
    vector <data> eil_vect;
    vector<int> ndpaz; //NAMU DARBU VEKTORIUS

    cout << "Jei norite faila nuskaityti, iveskite a, jei norite ivesti duomenys pats - b. \n";
    char pasirinkimas;
    cin >> pasirinkimas;
    if(pasirinkimas == 'a'){
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
                eil.egz = rand()%11;
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
                        eil.nd[sk] = rand()%11;
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

    spausdinimas(eil_vect, n, galutinis); //neveikia su nuskaitytu failu

    eil_vect.clear();

}