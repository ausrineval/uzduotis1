# Pirmos uzduoties v0.1 dalis.
## Ka daro programa:
- Saugo studentu duomenis (vardas, pavarde, egz. pazymys, n.d. pazymiai), kuriuos iveda vartotojas. 
- Apskaiciuoja vidurki bei mediana pagal duota formule.
- Atspausdina suformatuotus duomenis lenteleje.

### Kaip veikia programa (step-by-step):
1. Vartotojas paraso, kiek studentu duomenu nori ivesti.  
2. Vartotojas iveda studento varda, pavarde.
3. Vartotojas pasirenka, ar nori egzamino pazymi ivesti pats, ar generuoti atsitiktini pazymi.
4. Vartotojas pasirenka, ar nori ivesti ND pazymius pats, ar generuoti atsitiktinai.
5. Baiges vesti privalo parasyti *'-1'*.
6. Programa padekoja uz ivestus duomenis apie studenta.
7. Programa atspausdina studento namu darbu pazymius.
8. Apskaiciuojama bei atspausdinama namu darbu pazymiu mediana (ne galutinis pazymys!) bei galutinis pazymys (med.).
9. Apskaiciuojamas bei atspausdinamas namu darbu pazymiu vidurkis (ne galutinis pazymys!) bei galutinis (vid.).

 **Jei vartotojas nusprende pradzioje ivesti daugiau nei vieno studento duomenis, tai kartojami zingsniai 2-9, kol suvesti visu studentu duomenys.**

10. Spausdinami stulpeliu pavadinimai: Vardas, Pavarde, Galutinis (Vid.), Galutinis (Med.).
11. Spausdinami visu ivestu studentu duomenys pagal stulpelius.

### Issamiau apie v0.1 su vektoriumi
Sukuriamas naujas vektorius **ndpaz**, kuriame saugomi interger tipo duomenys. Jame bus saugomi namu darbu pazymiai.  

Namu darbu pazymiu ivedimo metu vykdomas *while* ciklas, kuris stabdomas, kai vartotojas iveda *'-1'*. Siame while cikle kiekvienas ivestas pazymys saugomas **ndpaz** vektoriuje naudojant *push_back* funkcija.  

Medianos ir vidurkio skaiciavimui sukurtos atskiros dvi funkcijos, kurios iskvieciamos *main* klaseje. 

Programai baigus viska skaiciuoti apie n-ojo studento duomenis panaudojama funkcija *push_back* studento duomenu vektoriui **eil_vect** bei funkcija *clear* **ndpaz** vektoriui.

### Issamiau apie v0.1 su masyvu
Sukasi while ciklas, kurio metu vartotojas iveda reiksme, kuri irasoma i masyva. Jei baige vesti reiksmes, paraso '-1' ir ciklas sustoja.

Sukuriamas paprastas integer **sk**, kurio reiksme pradzioje 1. Jis nusako masyvo dydi ir elemento indeksa.

Sukuriamas naujas masyvas **nd_paz**. Taip pat sukuriamas laikinas masyvas **temp**, i kuri laikinai buna irasomas pazymys ir veliau irasomas i **nd_paz** masyva. Istrinamas **temp** masyvas ir **sk** padidinamas vienu. Tokiu budu sekantis vedamas pazymys tures kitoki indeksa, bei masyvu **nd_paz** ir **temp** dydziai bus didesni.
