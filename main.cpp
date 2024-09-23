#include "lib.h"

int main() {
    int studentuSkaicius, namuDarbai;
    string vardas, pavarde;

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

    cout << endl << left << setw(15) << "Pavardė"
         << setw(20) << "Vardas"
         << setw(25) << "Galutinis (Vid.)" << endl;
    cout << "--------------------------------------------------" << endl;

    for (const auto& studentas : studentai) {
        studentas.rez();
    }

    return 0;
}
