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
using std::endl;
using std::vector;

// DUOMENYS
struct data {
	string vard, pavard;
	int nd[10], egz = 0;
	float vidurkis = 0, mediana = 0, galutinis = 0;
};

// MEDIANA
double findMedian( vector<int> v, int n){
  sort(v.begin(), v.end() );
  if (v.size() % 2 == 1) { //nelyginis skaicius
	  return v[v.size() / 2];  //vidurinis elementas	
	}
	else { //lyginis
		return (float)(v[v.size() / 2 - 1] + v[v.size() / 2]) / 2; 
	}
}
// VIDURKIS
double findMean(vector<int> v, int n){
  int suma = accumulate(v.begin(), v.end(), 0); //sudeda visus nd vektoriaus elementus
  return (double)suma/(double)n;
}

// SPAUSDINIMAS
void spausdinimas(vector<data> a, int n, int gal){
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

int main() {
	data eil;
	vector <data> eil_vect;
	vector<int> ndpaz; //NAMU DARBU VEKTORIUS

	// DUOMENU IVEDIMAS 
	int n = 0;
	cout << "Kiek studentu duomenu ivesite? \n";
	cin >> n;
  if (isdigit(n)){
    for (int a = 0; a < n; a++)
    {
      cout << "Iveskite duomenis (vardas, pavarde): \n";
      cin >> eil.vard >> eil.pavard;

      cout << "Jei norite generuoti egzamino pazymi atsitiktinai, parasykite -1. Jei ne, iveskite pazymi paprastai. \n";
      int egz_paz;
      cin >> egz_paz;
      if (egz_paz ==-1){
        eil.egz = rand()%11;
        cout << "Egzamino pazymys: " << eil.egz << endl;
      }
      else if(egz_paz==0 || egz_paz<=10) {
        eil.egz = egz_paz;
        cout << "Egzamino pazymys: " << eil.egz << endl;}
      else cout << "Ivesta neteisinga reiksme. \n";

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

    // SPAUSDINIMAS
    cout << "Jei norite, kad butu spausdinamas galutinis pazymys pagal vidurki, iveskite 0, "
      << "jei pagal mediana, iveskite 1." << endl;
    int gal;
    cin >> gal;

    spausdinimas(eil_vect, n, gal);

    eil_vect.clear();
  }
  else cout << "Ivesta neteisinga reiksme. \n";
}
