<b>Programos aprašymas</b>

<hr>

v0.1

Sukuriau GitHub repositorija
Susikuriau subrepositorija v0.1

Realizavau klasę

Deklaravau kintamuosiu studento vardą, pavardę, namų darbus, egzamino pažymius ir galutinį pažymį
Realizavau klasės metodus tokius kaip konstruktorius su parametrais

Realizavau priskyrimo kopijavimo operatoriu (trįjų taisyklė)
Realizavau kopijavimo konstruktoriu (trįjų taisyklė)
Realizavau destruktoriu (trįjų taisyklė)

Realizavau duomenų įvedimo metodą (perdengtas cin)
Realizavau duomenų išvedimo metodą (perdengtas cout)

Realizavau galutinio skaičiavimo metodą pagal vidurkį
Realizavau galutinio skaičiavimo metodą pagal medianą (renkasi žmogus)

<hr>
v0.2

Visų studentų sąrašų iš: 1 000, 10 000, 100 000, 1 000 000, 10 000 000 įrašų, generavimo rezultatas.
Generavimo laikas - 38.0127 sec
Taip pat, rūšiavimo laikas
Rusiavimo laikas - 54.0946 sec
Bendras visų failų dydis ~1.4GB.

<hr>

v1.0

Realizavau programą kuri sugeneruoja penkis studenų sąrašus su: 1 000, 10 000, 100 000, 1 000 000, 10 000 000 įrašais.

Sugeneravus sąrašą galima jį rūšiuoja.

Buvo išbandytos dvi strategijos and 10 000 000 studentų rušiavimui:

Pirma strategija: <br>
Vector: Atminties sunaudota po rūšiavimo funkcijos: 4759352 KB = 4.76 GB <br>
List: Atminties sunaudota po rūšiavimo funkcijos: 5181848 KB = 5.18 GB <br>
Deque: Atminties sunaudota po rūšiavimo funkcijos: 5156908 KB = 5.16 GB <br>

Antra strategija: <br>
Vector: Atminties sunaudota po rūšiavimo funkcijos: 3875384 KB = 3.87 GB <br>
List: Atminties sunaudota po rūšiavimo funkcijos: 3095064 KB = 3.09 GB <br>
Deque: Atminties sunaudota po rūšiavimo funkcijos: 4032188 KB = 4.03 GB <br>  
<br> 
Pabandžiau Kitokias duotas funkcijas: <br>
Panaudojau std::copy_if - leido man sukurti efektyvią filtravimo sistemą, nereikalaujančią papildomų "if" patikrinimo per kiekvieną studentą.
Leidžia mažiau loginių operacijų naudoti ir norimas vertes kopijuoti galima.
<br><br>
Dar panaudojau std::transform - leido man suformatuoti kiekvieną Studentas objektą kaip eilutę prieš ją įrašant į failą.
Šis metodas yra patogus, kai norime, kad originalus sąrašas studentai išliktų nepakitęs.
<hr>
<b>Pridėjau .exe failą, kuris turėtų paleisti visą programą. Įkelti visų failų su CMake ir .bat negalėjau, nes failas per didelis.</b>
<hr>
