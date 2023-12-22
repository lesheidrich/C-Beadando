# C++ Beadandó

Egy autó/munkagép kölcsönző cég számára kell olyan programot írni, amely nyilvántartja az autóparkot.
Az autópark különböző kategóriákat tartalmaz:
1. Személygépkocsi (km egységár, napi egységár)
Busz-kisbusz (km egységár, napi egységár, személyenkénti biztosítás díja)
Teherautó (km egységár, napi egységár, tonna egységár)
Munkagép (munkanap egységár, tonna egységár)
A bérleti díj számítása a következő igénybevételi paraméterek alapján történik:
Személygépkocsi: 
Megtett kilométer
Megkezdett napok száma
Busz-kisbusz:
Megtett kilométer
Megkezdett napok száma
Össz szállított személy
Teherautó:
Megtett kilométer
Megkezdett napok száma
Össz szállított tonna
Munkagép:
Megkezdett napok száma
Rakodott tonna

Minimálisan teljesítendő
Jármű felvétele az autóparkba.
Járműpark listázása a gépjármű paramétereivel, és árajánlattal (napra, km-re, főre, tonnára) becsült igénybevétel alapján.
Közepes szint
A fentiek, és keresés: a listából lehet keresni rendszám alapján, és az illető járműre költséget számolni a teljesített igénybevétel alapján.
Jó szint
A fentiek, és a kiválasztott járművel műveleteket lehet végezni: árajánlat, kiadás, visszavétel, törlés az autóparkból. 
Teljes megoldás:
A fentiek, és több szintű szűrő feltételek alapján történő listázás (elérhető, kategória, költségtartomány, stb)
Fájlba mentés, illetve visszatöltés, egyéb fájl műveletek (biztonsági mentés, stb).
A feladatot code::blocks, vagy onlinegdb projektént oldja meg, a forrást lássa el érthető kommentekkel!
