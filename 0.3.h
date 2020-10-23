#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <sstream>

using namespace std;

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
