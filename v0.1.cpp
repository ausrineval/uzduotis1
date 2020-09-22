#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using std::cout;
using std::cin;
using std::string;

struct data {
	string vard, pavard;
	int nd[10], egz=0;
	float vidurkis = 0, mediana = 0;
};

int main() {
	data eil; data eil_mas[5];
	std::vector <data> eil_vect;
	std::vector<int> ndpaz;

	// KELIEMS STUDENTAMS (NEVEIKIA)
	/*
	int n;
	cout << "Kiek studentu duomenu ivesite? ";
	cin >> n;
	for (int a = 0; a < n; a++)
	{
		cout << "Iveskite duomenis (vardas, pavarde, egzamino pazymys, 5 pazymiai): \n";
		cin >> eil_vect[a].vard >> eil_vect[a].pavard >> eil_vect[a].egz;
		for (int i = 0; i < 5; i++) {    // NEVEIKIA
			cin >> eil_vect[a].nd[i];
			eil_vect[a].galutinis = eil_vect[a].galutinis + (float)eil_vect[a].nd[i];
		}
		eil_vect[a].galutinis = eil_vect[a].galutinis / 5.0;
		eil_vect[a].galutinis = 0.4 * eil_vect[a].galutinis + 0.6 * eil_vect[a].egz;

		//cout << "Ivesta: " << eil_vect[a].vard << " " << eil_vect[a].pavard << " " << eil_vect[a].egz;

		for (int i = 0; i < 5; i++) cout << " " << eil_vect[a].nd[i];
		cout << " " << eil_vect[a].galutinis << std::endl;
		eil_vect.push_back(eil);
	}
	*/

	// N STUDENTAMS 
	int n = 0;
	cout << "Kiek studentu duomenu ivesite? \n";
	cin >> n;
	for (int a = 0; a < n; a++)
	{
		cout << "Iveskite duomenis (vardas, pavarde, egzamino pazymys): \n";
		//cin >> eil.vard >> eil.pavard >> eil.egz; // eil_mas[] dynaminis masyvas
		cin >> eil.vard >> eil.pavard >> eil.egz;
		// cout << "Iveskite studento nd pazymius, jei baigete vesti, parasykite 'end' /n";
		// string end;
		
		for (int i = 0; i < 5; i++) {
			cin >> eil.nd[i];
			eil.vidurkis = eil.vidurkis + (float)eil.nd[i];
			ndpaz.push_back(eil.nd[i]); //pazymiai surasomi i vektoriu
		}

		// Medianos radimas
		int len = ndpaz.size();
		sort(ndpaz.begin(), ndpaz.end());
		if (ndpaz.size() % 2 == 0)
			cout << std::endl << "Mediana = "
			<< (ndpaz[ndpaz.size() / 2 - 1]);


		eil.vidurkis = eil.vidurkis / 5.0;
		eil.vidurkis = 0.4 * eil.vidurkis + 0.6 * eil.egz;

		cout << "Ivesta: " << eil.vard << " " << eil.pavard << " " << eil.egz;
		for (int i = 0; i < 5; i++) cout << " " << eil.nd[i];
		cout << " " << eil.vidurkis << std::endl;

		eil_vect.push_back(eil); //su indeksu 0
		//eil_vect.push_back(eil); //su indeksu 1
		//eil_vect[1].galutinis = 25;
	}

	
	cout << std::endl << std::endl;
	cout << std::left 
		<< std::setw(20) << "Vardas" 
		<< std::setw(20) << "Pavarde"
		<< std::setw(20) << "Galutinis (Vid.)"
		<< std::setw(20) << "Galutinis (Med.)"
		<< std::setw(20) << std::endl;
	cout << "---------------------------------------------------" << std::endl;
	for (int j = 0; j <n; j++)
	{
		cout << std::left
			<< std::setw(20) << eil_vect[j].vard
			<< std::setw(20) << eil_vect[j].pavard
			<< std::setw(20) << eil_vect[j].vidurkis 
			<< std::setw(20) << eil_vect[j].mediana << std::endl;
		// for (int i = 0; i < 5; i++) cout << " " << eil_vect[j].nd[i];
	}
	cout << std::flush;
	eil_vect.clear(); 




}

