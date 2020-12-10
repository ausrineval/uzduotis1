#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <numeric>
#include <chrono>

// DUOMENYS
struct data {
    std::string vard, pavard;
    int nd[10], egz = 0;
    float GP = 0; //galutinis
};

int random(){
    return rand()%11;
}

std::vector<int> auto_marks(int how_many_marks){
    std::vector<int> skaiciai;
    for (int i = 0; i < how_many_marks; i++)
    {
        skaiciai.push_back(random());
    }
    return skaiciai;
}

float count_GP(std::vector<int> skaiciai) {
    data Eil;
    Eil.GP = 0.4 * std::accumulate(skaiciai.begin(), skaiciai.end(), 0) / skaiciai.size() + 0.6 * random();
    return Eil.GP;
}

int generavimas(std::vector<int> pazymiai){
    int kiek;
    std::cout << "iveskite studentu skaiciu: " << std::endl;
    std::cin >> kiek;
    std::string pavadinimas = "Studentai_" + std::to_string(kiek) + ".txt";
    auto start = std::chrono::high_resolution_clock::now();
    auto st = start;
    std::ofstream out_data(pavadinimas);
    std::vector<int> skaiciai;
    data Eil;
    out_data << std::setw(20) << std::left << "Vardas"
             << std::setw(20) << std::left << "Pavarde"
             << std::setw(20) << std::left << "Galutinis(vid.)";

    for (int s = 1; s <= kiek; s = s + 1)
    {
        skaiciai = auto_marks(5);
        out_data << std::setw(20) << "Vardas" + std::to_string(s) <<
                 std::setw(20) << "Pavarde" + std::to_string(s) <<
                 std::setw(18) << count_GP(skaiciai) << std::endl;;
        skaiciai.clear();

    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Failo su " + std::to_string(kiek) + " studentu/-ais kurimas uztruko: " << diff.count() << " s\n";

    return kiek;
}

void readFromFile(std::vector<data>& Eil, int kiek)
{
    int student_counter = 0;
    std::ifstream fileRead;
    std::string pavadinimas = "Studentai_" + std::to_string(kiek) + ".txt";
    std::string buff;
    fileRead.open(pavadinimas);
    if (fileRead.is_open()) {

        auto start = std::chrono::high_resolution_clock::now();
        auto st = start;
        getline(fileRead >> std::ws, buff);
        while (student_counter < kiek)
        {

            Eil.resize(Eil.size() + 1);
            fileRead >> Eil.at(student_counter).vard;
            fileRead >> Eil.at(student_counter).pavard;
            fileRead >> Eil.at(student_counter).GP;
            student_counter++;
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        std::cout << "Failo su " + std::to_string(kiek) + " studentais nuskaitymas uztruko: " << diff.count() << " s\n";
    }
}
int main() {
    data eil;
    std::vector <data> eil_vect;
    std::vector<int> ndpaz; //NAMU DARBU VEKTORIUS

    std::vector<int> skaiciai;

    int kiek = generavimas(skaiciai);
    std::vector<data> studentai;
    readFromFile(studentai, kiek);
    std::vector<data> protingi;
    std::vector<data> vargsiukai;
    int vargs = 0;
    int prot = 0;

    auto start = std::chrono::high_resolution_clock::now();
    auto st = start;
    for (int i = 0; i < kiek; i++) {
        float paz = 5.00;
        if (studentai.at(i).GP < paz) {
            vargsiukai.push_back(studentai.at(i));
            vargs++;
        }
    }
    for (int j = 0; j < kiek; j++) {
        float paz = 5.00;
        if (studentai.at(j).GP >= paz) {
            protingi.push_back(studentai.at(j));
            prot++;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Failo rusiavimas su " + std::to_string(kiek)+ " studentais i dvi grupes uztruko : " << diff.count() << " s\n";



    std::string pav;
    pav = "vargsiukai_" + std::to_string(kiek) + ".txt";
    std::ofstream vargs_failas(pav);
    auto start1 = std::chrono::high_resolution_clock::now();
    auto st1 = start1;
    for (int i = 0; i < kiek; i++) {

        float paz = 5.00;
        if (studentai.at(i).GP < paz) {
            vargs_failas << studentai.at(i).vard << std::setw(20) << studentai.at(i).pavard << std::setw(18) << studentai.at(i).GP << std::endl;
        }

    }
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff1 = end1 - start1;
    std::cout << "Failo isvedimas su " + std::to_string(kiek) + " studentais  i vargsiukus uztruko : " << diff1.count() << " s\n";

    pav = "protingi_" + std::to_string(kiek) + ".txt";
    std::ofstream prot_failas(pav);
    auto start2= std::chrono::high_resolution_clock::now();
    auto st2 = start2;
    for (int j = 0; j < kiek; j++) {
        float paz = 5.00;
        if (studentai.at(j).GP >= paz) {
            prot_failas << studentai.at(j).vard << std::setw(20) << studentai.at(j).pavard << std::setw(18) << studentai.at(j).GP << std::endl;
        }
    }
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff2 = end2 - start2;
    std::cout << "Failo isvedimas su " + std::to_string(kiek) + " studentais  i protingus uztruko : " << diff2.count() << " s\n";
}
