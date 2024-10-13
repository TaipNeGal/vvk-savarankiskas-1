#include "lib.h"

void generuotiStudentuDuomenis(const string& failoPavadinimas, int irasuKiekis) {
    std::ofstream failas(failoPavadinimas);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> pazymiuDist(1, 10);

    if (failas.is_open()) {
        cout << "Irasoma..." << endl;
        failas << setw(15) << "Vardas" << setw(15) << "Pavarde";
        for (int i = 1; i <= 5; i++) failas << setw(6) << "ND" + to_string(i);
        failas << setw(6) << "Egz." << endl;

        for (int i = 1; i <= irasuKiekis; ++i) {
            failas << setw(15) << "Vardas" + to_string(i)
                   << setw(15) << "Pavarde" + to_string(i);

            for (int j = 0; j < 5; ++j) {
                failas << setw(6) << pazymiuDist(gen);
            }
            failas << setw(6) << pazymiuDist(gen) << endl;
        }
    }
    failas.close();
}

void rusiuotiStudentus(const string& inputFailas, const string& goodFailas, const string& badFailas) {
    vector<Studentas> studentai = nuskaitytiStudentusIsFailo(inputFailas);
    
    std::ofstream goodIsrasymas(goodFailas);
    std::ofstream badIsrasymas(badFailas);

    if (!goodIsrasymas.is_open() || !badIsrasymas.is_open()) {
        throw std::runtime_error("Nepavyko atidaryti failu.");
    }

    goodIsrasymas << setw(15) << "Pavarde" << setw(20) << "Vardas" << setw(25) << "Vidurkis" << endl;
    badIsrasymas << setw(15) << "Pavarde" << setw(20) << "Vardas" << setw(25) << "Vidurkis" << endl;

    for (const auto& student : studentai) {
        if (student.gVid() >= 5.0) {
            goodIsrasymas << setw(15) << student.getPavarde()
                       << setw(20) << student.getVardas()
                       << setw(25) << fixed << std::setprecision(2) << student.gVid() << endl;
        } else {
            badIsrasymas << setw(15) << student.getPavarde()
                      << setw(20) << student.getVardas()
                      << setw(25) << fixed << std::setprecision(2) << student.gVid() << endl;
        }
    }

    goodIsrasymas.close();
    badIsrasymas.close();
}

int main() {
//    Sarasu generavimas
    auto genPradzia = std::chrono::high_resolution_clock::now();
    generuotiStudentuDuomenis("studentai_1000.txt", 1000);
    generuotiStudentuDuomenis("studentai_10000.txt", 10000);
    generuotiStudentuDuomenis("studentai_100000.txt", 100000);
    generuotiStudentuDuomenis("studentai_1000000.txt", 1000000);
    generuotiStudentuDuomenis("studentai_10000000.txt", 10000000);
    auto genPabaiga = std::chrono::high_resolution_clock::now();
    cout << "Studentai sugeneruoti!" << endl;
    std::chrono::duration<float> gen_rezas = genPabaiga - genPradzia;
    cout << "Generavimo laikas - " << gen_rezas.count() << " sec\n";

    auto sortPradzia = std::chrono::high_resolution_clock::now();
    rusiuotiStudentus("studentai_1000.txt", "studentai_1000_galvociai.txt", "studentai_1000_nuskriaustukai.txt");
    rusiuotiStudentus("studentai_10000.txt", "studentai_10000_galvociai.txt", "studentai_10000_nuskriaustukai.txt");
    rusiuotiStudentus("studentai_100000.txt", "studentai_100000_galvociai.txt", "studentai_100000_nuskriaustukai.txt");
    rusiuotiStudentus("studentai_1000000.txt", "studentai_1000000_galvociai.txt", "studentai_1000000_nuskriaustukai.txt");
    rusiuotiStudentus("studentai_10000000.txt", "studentai_10000000_galvociai.txt", "studentai_10000000_nuskriaustukai.txt");
    auto sortPabaiga = std::chrono::high_resolution_clock::now();
    cout << "Studentai surusiuoti!" << endl;
    std::chrono::duration<float> sort_rezas = sortPabaiga - sortPradzia;
    cout << "Rusiavimo laikas - " << sort_rezas.count() << " sec\n";
    
    return 0;
}
