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

struct data {
	string vard, pavard;
	int nd[10], egz=0;
	float vidurkis = 0, mediana = 0, galutinis = 0;
};

int main() {
	data eil; data eil_mas[7];
	std::vector <data> eil_vect;
	std::vector <int> ndpaz;

	// N STUDENTAMS 
	int n = 0;
	cout << "Kiek studentu duomenu ivesite? \n";
	cin >> n;
	for (int a = 0; a < n; a++)
	{
		cout << "Iveskite duomenis (vardas, pavarde, egzamino pazymys): \n";
		cin >> eil_mas[a].vard >> eil_mas[a].pavard >> eil_mas[a].egz;

		cout << "Iveskite studento nd pazymius, jei baigete vesti, parasykite '-1'. \n";
		int end;
		int sk = 0;

		int mas_sk = 1; // is pradziu elementu skaicius 1
		int* arr = new int(mas_sk);
		do {
			cin >> end;
			if (end != -1) {
				eil_mas[a].nd[sk] = end;
				eil_mas[a].vidurkis = eil_mas[a].vidurkis + (float)eil_mas[a].nd[sk];
				ndpaz.push_back(eil_mas[a].nd[sk]); //pazymiai surasomi i vektoriu
				arr[mas_sk] = eil_mas[a].nd[sk]; //pazymiai surasomi i masyva
				cout << arr[mas_sk] << std::endl;
				mas_sk = mas_sk + 1;
				sk = sk + 1;
			}
			else {
				cout<< "Aciu uz suvestus duomenis apie " 
					<< eil_mas[a].vard << " " << eil_mas[a].pavard << "." <<std::endl;
			}

		} while (end != -1);

		int n1 = sizeof(arr) / sizeof(arr[0]);
		std::sort(arr, arr + n1);

		cout << "\nArray after sorting using "
			"default sort is : \n";
		for (int i = 0; i < n1; ++i) cout << arr[i] << " ";

		// MEDIANOS RADIMAS
		cout << "Namu darbu skaicius: " << sizeof(arr) << std::endl;
		sort(ndpaz.begin(), ndpaz.end());
		if (ndpaz.size() % 2 == 1) { //nelyginis skaicius
			eil_mas[a].mediana = ndpaz[ndpaz.size() / 2];  //vidurinis elementas	
		}
		else { //lyginis
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
		int suma = accumulate(ndpaz.begin(), ndpaz.end(), 0); //sudeda visus nd vektoriaus elementus
		eil_mas[a].vidurkis = eil_mas[a].vidurkis / sk;
		cout << "Pazymiu vidurkis: " << eil_mas[a].vidurkis << std::endl;
		eil_mas[a].vidurkis = 0.4 * eil_mas[a].vidurkis + 0.6 * eil_mas[a].egz;

		eil_vect.push_back(eil); //su indeksu 0
		//eil_vect.push_back(eil); //su indeksu 1
		//eil_vect[1].galutinis = 25;
		//ndpaz.clear();
	}
	cout << eil_mas[1].vard << std::endl;
	
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
			<< std::setw(20) << eil_mas[j].vidurkis // neteisingas antras
			<< std::setw(20) << eil_mas[j].mediana << std::endl; //neteisingas antras
		// for (int i = 0; i < 5; i++) cout << " " << eil_vect[j].nd[i];
	}
	eil_vect.clear(); 

}

