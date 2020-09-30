#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <numeric>

using std::cout;
using std::cin;
using std::string;
using std::bool_constant;

// DUOMENYS
struct data {
	string vard, pavard;
	int nd[10], egz = 0;
	float vidurkis = 0, mediana = 0, galutinis = 0;
};





int main() {
	data eil; data eil_mas[5];
	std::vector <data> eil_vect;
	std::vector<int> ndpaz; //NAMU DARBU VEKTORIUS

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
    }
    else eil.egz= egz_paz;

    int pazymiai;
    cout << "Jei norite atsitiktinai generuotu pazymiu, iveskite '0', jei norite ivesti patys - '1'. \n";
    cin >> pazymiai;
    int end; // namu darbo pazymys
    int sk = 1; //indekso skaicius

    if (pazymiai ==1){
		// NAMU DARBU PAZYMIU IVEDIMAS
		cout << "Iveskite studento nd pazymius, jei baigete vesti, parasykite '-1'. \n";

      do {
        cin >> end;
        if (end != -1) {
          eil.nd[sk] = end;
          eil.vidurkis = eil.vidurkis + (float)eil.nd[sk];
          ndpaz.push_back(eil.nd[sk]); //pazymiai surasomi i vektoriu
          sk = sk + 1;
        }
        else {
          cout << "Aciu uz suvestus duomenis apie " << eil.vard << " " << eil.pavard << "." << std::endl;
        }
      } while (end != -1);
    }
    else {
      cout << "Iveskite bet koki skaiciu ir bus generuojamas atsitiktinis pazymys, jei baigete vesti, parasykite '-1'. \n";
      do {
        cin >> end;
        if (end != -1){
          eil.nd[sk] = rand()%11;
          eil.vidurkis = eil.vidurkis + (float)eil.nd[sk];
          ndpaz.push_back(eil.nd[sk]); //pazymiai surasomi i vektoriu
          sk = sk + 1;
        }
        else{
          cout << "Aciu uz suvestus duomenis apie "
          << eil.vard << " " << eil.pavard << "." << std::endl;
        }
      } while (end != -1);

    }
    for(int i=0; i<sk-1; i++){
      cout << ndpaz[i] << "; ";
    }
    cout << std::endl;

		// MEDIANOS SKAICIAVIMAS
		cout << "Namu darbu skaicius: " << ndpaz.size() << std::endl;
		sort(ndpaz.begin(), ndpaz.end());
		if (ndpaz.size() % 2 == 1) { //nelyginis skaicius
			eil.mediana = ndpaz[ndpaz.size() / 2];  //vidurinis elementas	
		}
		else { //lyginis
			eil.mediana = (float)(ndpaz[ndpaz.size() / 2 - 1] + ndpaz[ndpaz.size() / 2]) / 2;
		}

		cout << "Pazymiu mediana: " << eil.mediana << std::endl;
		eil.mediana = 0.4 * eil.mediana + 0.6 * eil.egz;

		// VIDURKIO SKAICIAVIMAS
		int suma = accumulate(ndpaz.begin(), ndpaz.end(), 0); //sudeda visus nd vektoriaus elementus
		eil.vidurkis = eil.vidurkis / sk;
		cout << "Pazymiu vidurkis: " << eil.vidurkis << std::endl;
		eil.vidurkis = 0.4 * eil.vidurkis + 0.6 * eil.egz;

		eil_vect.push_back(eil); //su indeksu 0
		ndpaz.clear();
		eil.vidurkis = 0;
		eil.mediana = 0;
	}

	// SPAUSDINIMAS
	cout << "Jei norite, kad butu spausdinamas galutinis pazymys pagal vidurki, iveskite 0, "
		<< "jei pagal mediana, iveskite 1." << std::endl;
	int gal;
	cin >> gal;

	if (gal == 0) {
		cout << std::endl << std::endl;
		cout << std::left
			<< std::setw(20) << "Vardas"
			<< std::setw(20) << "Pavarde"
			<< std::setw(20) << "Galutinis (Vid.)"
			<< std::setw(20) << std::endl;
		cout << "------------------------------------------------------------------------" << std::endl;
		for (int j = 0; j < n; j++)
		{
			cout << std::left
				<< std::setw(20) << eil_vect[j].vard
				<< std::setw(20) << eil_vect[j].pavard
				<< std::setw(20) << eil_vect[j].vidurkis << std::endl;
		}
	}
	else {
		cout << std::endl << std::endl;
		cout << std::left
			<< std::setw(20) << "Vardas"
			<< std::setw(20) << "Pavarde"
			<< std::setw(20) << "Galutinis (Med.)"
			<< std::setw(20) << std::endl;
		cout << "------------------------------------------------------------------------" << std::endl;
		for (int j = 0; j < n; j++)
		{
			cout << std::left
				<< std::setw(20) << eil_vect[j].vard
				<< std::setw(20) << eil_vect[j].pavard
				<< std::setw(20) << eil_vect[j].mediana << std::endl;
		}

	}

	eil_vect.clear();

}
