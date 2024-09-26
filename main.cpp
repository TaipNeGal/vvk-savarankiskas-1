#include "lib.h"

int main() {
    vector<Studentas> studentai;
    string failoPavadinimas;
    char metodas;

    cout << "Pasirinkite metodą galutiniam balui apskaičiuoti (v - vidurkis, m - mediana): ";
    cin >> metodas;

    while (metodas != 'v' && metodas != 'm') {
        cout << "Neteisinga įvestis. Įveskite 'v' arba 'm': ";
        cin >> metodas;
    }

    // Nuskaitome studentų duomenis iš failo
    cout << "Įveskite failo pavadinimą su studentų duomenimis: ";
    cin >> failoPavadinimas;

    try {
        studentai = nuskaitytiStudentusIsFailo(failoPavadinimas);
    }
    catch (const exception& e) {
        cout << e.what() << endl;
        return 1;
    }

    // Išlyginame duomenų antraštę
    if (metodas == 'v') {
        cout << endl << left << setw(15) << "Pavardė"
            << setw(20) << "Vardas"
            << setw(25) << "Galutinis (Vid.)" << endl;
    }
    else {
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
