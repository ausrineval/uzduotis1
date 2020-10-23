#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <sstream>

using namespace std;

#include "0.3.h"

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

// NAMU DARBU SKAICIAVIMAS IS FAILO
double ndsk(){
    ifstream file("C:\\Users\\ausri\\CLionProjects\\untitled\\kursiokai.txt");
    string line;
    getline(file, line);
    std::stringstream ss(line);

    int ndsk=0;
    string zodis;
    while (ss >> zodis) {
        ++ndsk;
    }
    return ndsk;
}
