#ifndef library
#define library

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

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

class Studentas {
    string vardas;
    string pavarde;
    vector<int> pazymiai;
    int egzaminas;

public:

    // Konstruktorius kuris gauna studento vardą, pavardę ir namų darbų kiekį
    Studentas(const string& vardas, const string& pavarde, int namudarbai) 
        : vardas(vardas), pavarde(pavarde) {
        int pazymys;
        // Renkami namų darbų pažymiai
        for (int i = 0; i < namudarbai; ++i) {
            cout << vardas << " " << pavarde << ": Įveskite " << (i + 1) << "-ojo namų darbo pažymį: ";
            cin >> pazymys;
            pazymiai.push_back(pazymys);
        }

        cout << "Įveskite egzamino pažymį: ";
        cin >> egzaminas;
    }

    // Kopijavimo konstruktorius
    Studentas(const Studentas& Kopija): 
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
    ~Studentas(){}

    // Metodas kuris skaičiuoja vidurkį
    double gVid() const {
        int suma = 0;
        for (int pazymys : pazymiai) {
            suma += pazymys;
        }
        double vidurkis = static_cast<double>(suma) / pazymiai.size();
        return 0.4 * vidurkis + 0.6 * egzaminas;
    }

    // Metodas kuris skaičiuoja medianą
    double gMed() const {
        vector<int> temp = pazymiai;
        sort(temp.begin(), temp.end());

        double mediana;
        if (temp.size() % 2 == 0) {
            mediana = (temp[temp.size() / 2 - 1] + temp[temp.size() / 2]) / 2.0;
        } else {
            mediana = temp[temp.size() / 2];
        }

        return 0.4 * mediana + 0.6 * egzaminas;
    }

    // Metodas kuris išspausdina studento rezultatus pagal pasirinkimą
    void rez(char metodas) const {
        cout << left << setw(15) << pavarde
             << setw(20) << vardas;

        if (metodas == 'v') {
            cout << setw(25) << fixed << setprecision(2) << gVid();
        } else if (metodas == 'm') {
            cout << setw(25) << fixed << setprecision(2) << gMed();
        }

        cout << endl;
    }
};

#endif
