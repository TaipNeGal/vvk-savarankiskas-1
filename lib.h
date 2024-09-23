#ifndef library
#define library

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::left;
using std::setw;
using std::fixed;
using std::setprecision;

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

    // Metodas kuris skaičiuoja galutinį pažymį
    double gVid() const {
        int suma = 0;
        for (int pazymys : pazymiai) {
            suma += pazymys;
        }
        double vidurkis = static_cast<double>(suma) / pazymiai.size();
        return 0.4 * vidurkis + 0.6 * egzaminas;
    }

    // Metodas kuris išspausdina studento rezultatus
    void rez() const {
        cout << left << setw(15) << pavarde
             << setw(20) << vardas
             << setw(25) << fixed << setprecision(2) << gVid()
             << endl;
    }
};

#endif
