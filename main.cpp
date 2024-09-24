#include "lib.h"

int main() {
    int studentuSkaicius, namuDarbai;
    string vardas, pavarde;
    char metodas;


    cout << "Pasirinkite metodą galutiniam balui apskaičiuoti (v - vidurkis, m - mediana): ";
    cin >> metodas;

    while (metodas != 'v' && metodas != 'm') {
        cout << "Neteisingas įvestis. Įveskite 'v' arba 'm': ";
        cin >> metodas;
    }

    cout << "Įveskite studentų skaičių: ";
    cin >> studentuSkaicius;

    vector<Studentas> studentai;

    for (int i = 0; i < studentuSkaicius; ++i) {
        cout << "Vardas: ";
        cin >> vardas;
        cout << "Pavardė: ";
        cin >> pavarde;

        cout << "Namų darbų skaičius: ";
        cin >> namuDarbai;

        studentai.push_back(Studentas(vardas, pavarde, namuDarbai));
    }

    if (metodas == 'v') {
        cout << endl << left << setw(15) << "Pavardė"
             << setw(20) << "Vardas"
             << setw(25) << "Galutinis (Vid.)" << endl;
    } else {
        cout << endl << left << setw(15) << "Pavardė"
             << setw(20) << "Vardas"
             << setw(25) << "Galutinis (Med.)" << endl;
    }

    cout << "--------------------------------------------------" << endl;

    for (const auto& studentas : studentai) {
        studentas.rez(metodas);
    }

    return 0;
}
