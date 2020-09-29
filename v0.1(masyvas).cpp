#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <bits/stdc++.h>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::array;

struct data {
	string vard, pavard;
	int nd[10], egz = 0;
	float vidurkis = 0, mediana = 0, galutinis = 0;
};
// MEDIANOS RADIMAS MASYVUI
double findMedian(int a[], int n){
  // First we sort the array 
  std::sort(a, a+n); 
    
  if (n % 2 != 0) {
    return (double)a[n/2]; }
  else return (double)(a[(n-1)/2] + a[n/2])/2.0; 
}

//VIDURKIO RADIMAS MASYVUI
double findMean(int a[], int n){ 
  int sum = 0; 
  for (int i = 0; i < n; i++)  
    sum += a[i]; 
          
  return (double)sum/(double)n; 
} 

int main() {
	data eil; data eil_mas[7];
	vector <data> eil_vect;
	vector <int> ndpaz;	

	// N STUDENTAMS 
	int n = 0;
	cout << "Kiek studentu duomenu ivesite? \n";
	cin >> n;
	for (int a = 0; a < n; a++)
	{
		cout << "Iveskite duomenis (vardas, pavarde): \n";
		cin >> eil_mas[a].vard >> eil_mas[a].pavard;

    cout << "Jei norite generuoti egzamino pazymi atsitiktinai, parasykite -1. Jei ne, iveskite pazymi paprastai. \n";
    int egz_paz=0;
    cin >> egz_paz;
    if (egz_paz ==-1){
      eil_mas[a].egz = rand()%11;
    }
    else eil_mas[a].egz= egz_paz;

    int pazymiai;
    cout << "Jei norite atsitiktinai generuotu pazymiu, iveskite '0', jei norite ivesti patys - '1'. \n";
    cin >> pazymiai;
    int end; // namu darbo pazymys
    int sk = 1; //indekso skaicius
      
    int* nd_paz = new int[sk];

    if(pazymiai==1){
      cout << "Iveskite studento nd pazymius, jei baigete vesti, parasykite '-1'. \n";
      do {
        cin >> end; //ivedame pazymi
        if (end != -1) { //stabdoma jei vartotojas iveda -1
          int* temp = new int[sk];

          for(int i = 0; i<sk-1; i++){
            temp[i] = nd_paz[i];
          }
          delete[] nd_paz;
          nd_paz = new int[sk];
          for(int i =0; i < sk-1; i++){
            nd_paz[i]= temp[i];
          }
          delete [] temp;
          nd_paz[sk-1] = end;
          sk++;
        }
        else {
          cout << "Aciu uz suvestus duomenis apie "
            << eil_mas[a].vard << " " << eil_mas[a].pavard << "." << std::endl;
        }
      } while (end != -1); //programa vykdoma kol vartotojas neiveda -1
    }
    else{
      cout << "Iveskite bet koki skaiciu ir bus generuojamas atsitiktinis pazymys, jei baigete vesti, parasykite '-1'. \n";
      do {
        cin >> end; //ivedame pazymi
        if (end != -1) { //stabdoma jei vartotojas iveda -1
          int* temp = new int[sk];

          for(int i = 0; i<sk-1; i++){
            temp[i] = nd_paz[i];
          }
          delete[] nd_paz;
          nd_paz = new int[sk];
          for(int i =0; i < sk-1; i++){
            nd_paz[i]= temp[i];
          }
          delete [] temp;
          nd_paz[sk-1] = rand()%11;
          sk++;
        }
        else {
          cout << "Aciu uz suvestus duomenis apie "
            << eil_mas[a].vard << " " << eil_mas[a].pavard << "." << std::endl;
        }
      } while (end != -1); //programa vykdoma kol vartotojas neiveda -1

    }

    // PAZYMIU SPAUSDINIMAS
		for (int i = 0; i < sk-1; i++) { 
    cout << nd_paz[i] << "; ";
		} 
    cout << std::endl;

    int n = sizeof(nd_paz)/sizeof(nd_paz[0]);
    eil_mas[a].mediana = findMedian(nd_paz, n);
    cout << "Pazymiu median: " << eil_mas[a].mediana << std::endl;
    eil_mas[a].vidurkis = findMean(nd_paz, n);
    cout << "Pazymiu vidurkis: " << eil_mas[a].vidurkis << std::endl;

		eil_vect.push_back(eil_mas[a]); //su indeksu 0
	}



	cout << "Jei norite, kad butu spausdinamas galutinis pazymys pagal vidurki, iveskite 0, \n"
		<< "jei pagal mediana, iveskite 1." << std::endl;
	int gal;
	cin >> gal;

	// spausdinimas
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
