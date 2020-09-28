#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <numeric>
// #define size 1

using std::cout;
using std::cin;
using std::string;

struct data {
	string vard, pavard;
	int nd[10], egz=0;
	float vidurkis = 0, mediana = 0, galutinis = 0;
};

int main() {
	data eil; data eil_mas[7];
	std::vector <data> eil_vect;
	std::vector <int> ndpaz;
	std::array <int, 5> nd_paz = {};

	// N STUDENTAMS 
	int n = 0;
	cout << "Kiek studentu duomenu ivesite? \n";
	cin >> n;
	for (int a = 0; a < n; a++)
	{
		cout << "Iveskite duomenis (vardas, pavarde, egzamino pazymys): \n";
		cin >> eil_mas[a].vard >> eil_mas[a].pavard >> eil_mas[a].egz;

		cout << "Iveskite studento nd pazymius, jei baigete vesti, parasykite '-1'. \n";
		int end; // namu darbo pazymys
		int sk = 0; //indekso skaicius

		int mas_sk = 1; // is pradziu elementu skaicius 1
		int* arr = new int(mas_sk);
		//int arr[size]
		do {
			cin >> end; //ivedame pazymi
			if (end != -1) { //stabdoma jei vartotojas iveda -1
				eil_mas[a].nd[sk] = end; //priskiriama ivesta reiksme prie nd duomenu
				eil_mas[a].vidurkis = eil_mas[a].vidurkis + (float)eil_mas[a].nd[sk];
				// ndpaz.push_back(eil_mas[a].nd[sk]); //pazymiai surasomi i vektoriu
				arr[mas_sk] = eil_mas[a].nd[sk]; //pazymiai surasomi i masyva
				cout << arr[mas_sk] << std::endl; // neveikia
				mas_sk = mas_sk + 1;
				sk = sk + 1; //indeksas padidinamas
			}
			else {
				cout<< "Aciu uz suvestus duomenis apie " 
					<< eil_mas[a].vard << " " << eil_mas[a].pavard << "." <<std::endl;
			}
		} while (end != -1); //programa vykdoma kol vartotojas neiveda -1

		int n1 = sizeof(arr) / sizeof(arr[0]);
		std::sort(arr, arr + n1);

		cout << "\nArray after sorting using "
			"default sort is : \n";
		for (int i = 0; i < n1; ++i) cout << arr[i] << " ";

		// MEDIANOS RADIMAS
		cout << "Namu darbu skaicius: " << sizeof(arr) << std::endl;
		sort(ndpaz.begin(), ndpaz.end());  //rusiavimas
		if (ndpaz.size() % 2 == 1) { //nelyginis skaicius
			eil_mas[a].mediana = ndpaz[ndpaz.size() / 2];  //vidurinis elementas	
		}
		else { //lyginis skaicius
			eil_mas[a].mediana = (float)(ndpaz[ndpaz.size() / 2 - 1] + ndpaz[ndpaz.size() / 2]) / 2;
		}
		/*
		if (ndpaz.size() % 2 == 0) { //lyginis skaicius
			eil.mediana = (ndpaz[ndpaz.size() / 2 -1] + ndpaz[ndpaz.size() / 2 ]) / 2;
		}					// jei 4 elementai paima antra [1] ir trecia [2]
		else { //nelyginis
			eil.mediana = ndpaz[ndpaz.size() / 2];  //vidurinis elementas
		} */
		cout << "Pazymiu mediana: " << eil_mas[a].mediana << std::endl;
		eil_mas[a].mediana = 0.4 * eil_mas[a].mediana + 0.6 * eil_mas[a].egz;

		// VIDURKIO SKAICIAVIMAS VEKTORIUI
		eil_mas[a].vidurkis = eil_mas[a].vidurkis / sk;
		cout << "Pazymiu vidurkis: " << eil_mas[a].vidurkis << std::endl;
		eil_mas[a].vidurkis = 0.4 * eil_mas[a].vidurkis + 0.6 * eil_mas[a].egz;

		eil_vect.push_back(eil_mas[a]); //su indeksu 0

	}
	cout << "Jei norite, kad butu spausdinamas galutinis pazymys pagal vidurki, iveskite 0, \n"
		 << "jei pagal mediana, iveskite 1." << std::endl;
	int gal;
	cin >> gal;

	// spausdinimas
	cout << std::endl << std::endl;
	cout << std::left 
		<< std::setw(20) << "Vardas" 
		<< std::setw(20) << "Pavarde"
		<< std::setw(20) << "Galutinis (Vid.)"
		<< std::setw(20) << "Galutinis (Med.)"
		<< std::setw(20) << std::endl;
	cout << "------------------------------------------------------------------------" << std::endl;
	for (int j = 0; j <n; j++)
	{
		cout << std::left
			<< std::setw(20) << eil_mas[j].vard
			<< std::setw(20) << eil_mas[j].pavard
			<< std::setw(20) << eil_mas[j].vidurkis
			<< std::setw(20) << eil_mas[j].mediana << std::endl;
	}
	eil_vect.clear(); 

}

