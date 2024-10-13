#ifndef library
#define library

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <stdexcept>
#include <random>
#include <sstream>
#include <list>
#include <deque>
#include <chrono>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::left;
using std::setw;
using std::fixed;
using std::setprecision;
using std::sort;
using std::ifstream;
using std::exception;
using std::getline;
using std::fixed;
using std::to_string;
using std::list;
using std::deque;

class Studentas {
    string vardas;
    string pavarde;
    vector<int> pazymiai;
    int egzaminas;

public:
    // Konstruktorius duomenims i� failo
    Studentas(const string& vardas, const string& pavarde, const vector<int>& nd, int egzaminas)
        : vardas(vardas), pavarde(pavarde), pazymiai(nd), egzaminas(egzaminas) {}

    // Kopijavimo konstruktorius
    Studentas(const Studentas& Kopija) :
        vardas(Kopija.vardas),
        pavarde(Kopija.pavarde),
        pazymiai(Kopija.pazymiai),
        egzaminas(Kopija.egzaminas) {}

    // Priskyrimo operatorius
    Studentas& operator=(const Studentas& Kopija) {
        if (this != &Kopija) {
            vardas = Kopija.vardas;
            pavarde = Kopija.pavarde;
            pazymiai = Kopija.pazymiai;
            egzaminas = Kopija.egzaminas;
        }
        return *this;
    }

    // Destruktorius
    ~Studentas() {}

    // Metodas kuris skai?iuoja vidurk?
    double gVid() const {
        int suma = 0;
        for (int pazymys : pazymiai) {
            suma += pazymys;
        }
        double vidurkis = static_cast<double>(suma) / pazymiai.size();
        return 0.4 * vidurkis + 0.6 * egzaminas;
    }

    // Metodas kuris skai?iuoja median?
    double gMed() const {
        vector<int> temp = pazymiai;
        sort(temp.begin(), temp.end());

        double mediana;
        if (temp.size() % 2 == 0) {
            mediana = (temp[temp.size() / 2 - 1] + temp[temp.size() / 2]) / 2.0;
        }
        else {
            mediana = temp[temp.size() / 2];
        }

        return 0.4 * mediana + 0.6 * egzaminas;
    }

    // Metodas kuris i�spausdina studento rezultatus pagal pasirinkim?
    void rez(char metodas) const {
        cout << left << setw(15) << pavarde
            << setw(20) << vardas;

        if (metodas == 'v') {
            cout << setw(25) << fixed << setprecision(2) << gVid();
        }
        else if (metodas == 'm') {
            cout << setw(25) << fixed << setprecision(2) << gMed();
        }

        cout << endl;
    }

    string getVardas() const { return vardas; }
    string getPavarde() const { return pavarde; }
};

// Funkcija nuskaityti studentus i� failo
vector<Studentas> nuskaitytiStudentusIsFailo(const string& failoPavadinimas) {
    vector<Studentas> studentai;
    ifstream failas(failoPavadinimas);

    if (!failas) {
        throw std::runtime_error("Nepavyko atidaryti failo: " + failoPavadinimas);
    }

    string pavarde, vardas;
    int nd1, nd2, nd3, nd4, nd5, egzaminas;

    // Ignoruojame antra�t?
    string header;
    getline(failas, header);

    while (failas >> pavarde >> vardas >> nd1 >> nd2 >> nd3 >> nd4 >> nd5 >> egzaminas) {
        vector<int> nd = { nd1, nd2, nd3, nd4, nd5 };
        studentai.emplace_back(vardas, pavarde, nd, egzaminas);
    }

    return studentai;
}

#endif
