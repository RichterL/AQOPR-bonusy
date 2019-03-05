# AQOPR-bonusy
Bonusové příklady z AQOPR

## Příklady k procvičování

### Opakování C
- **Struktury**
  - [x] Deklarujte strukturu Obdelnik reprezentující obdélník (nebo kruh, čtverec atd.) a dále definujte:
    - proměnnou x typu obdélník,
	- dvě funkce pro výpočet obsahu a obvodu obdélníka:
	  - první funkce bude mít jako parametr proměnnou typu struktura Obdelnik,
	  - druhá funkce bude mít jako parametr ukazatel na proměnnou typu struktura Obdelnik
	- s použitím první i druhé funkce spočítejte a vypište obvod a obsah proměnné x,
	- proměnnou y typu Obdelnik a kód, který určí, zda je proměnná x větší nebo rovna (podle rozměrů) proměnné y,
	- definujte pole obdélníků a inicializujte jej a spočítejte sumu obsahů, průměrný obsah a vypište rozměry největšího a nejmenšího obdélníku v poli
  - [x] Vytvořte program pro vyhodnocení závodu aut. Zadejte jednotlivé časy a startovní čísla závodníků, zobrazte nejrychlejší čas, průměrný čas a nejpomalejší čas.
  - [x] Deklarujte strukturu komplexní číslo, definujte pole komplexních čísel, napište program, který vypíše hodnoty největšího komplexního čísla dle absolutní hodnoty.
  - [x] Deklarujte strukturu Pixel a dále:
	- definujte pole pixelů a inicializujte jej,
	- vypište počet černých pixelů v poli pixelů,
	- vypište hodnoty barevných složek (red, green, blue) nejtmavšího pixelu.
- **Ukazatele a funkce:**
  - [x] vytvořte funkci, které předáte pole a ona vrátí největší prvek v poli,
  - [x] vytvořte funkci, které předáte pole a ona vrátí strukturu obsahující nejmenší, největší a průměrný prvek,
  - [x] vytvořte funkci, která prohodí hodnoty proměnných v poli (swap),
  - [ ] vytvořte program pro součet a násobení matic s proměnnými rozměry s využitím pole ukazatelů a alokací paměti na haldě pomocí funkce malloc,
  - [ ] vytvořte dynamické pole s pomocí struktury a funkce realloc.

### Třídy
- [x] Deklarujte třídu reprezentující obdelník s následujícími podrobnostmi:
  - vytvořte konstruktor s délkou a šírkou obdelníka,
  - vytvořte členské funkce pro výpočet obsahu a obvodu,
  - dále definujte pole obdelníků a vytvořte kód, který vypíše rozměry největšího obdelníku v poli.
- [x] Deklarujte třídu reprezentující komplexní číslo s následujícími podrobnostmi:
  - členské proměnné (reálná a imaginární část) budou private,
  - vytvořte konstruktor s reálnou i imaginární složkou,
  - vytvořte členskou funkci, která vrátí absolutní hodnotu komplexního čísla,
  - definujte pole komplexních čísel na zásobníku,
  - najděte komplexní číslo s největší absolutní hodnotou a vypište jeho komplexní a reálnou část.
- [x] Deklarujte třídu reprezetující zásobník s následujícími funkcemi:
  - konstruktor s kapacitou zásobníku,
  - funkci pro vložení nového prvku (push),
  - funkci která vrátí hodnotu posledního prvku a odebere ho ze zásobníku (pop).

### Vybrané vlastnosti (features) C++
- [ ] Deklarujte třídu reprezetující zásobník obsahující konstruktor s kapacitou zásobníku, funkci pro vložení nového prvku (push) a funkci která vrátí hodnotu posledního prvku a odebere ho ze zásobníku (pop), a využijte následující vlastnosti C++:
  - třídu vložte do namespace,
  - data pro zásobník alokujte pomocí operátoru new a uvolněte pomocí operátoru delete,
  - Vyberte jednu z následujících implementací
  - kapacitu deklarujte jako konstantní členskou proměnnou a inicializujte v konstruktoru pomocí constructor inicializer list,
  - pro členské proměnné inicializované konstantami využíjte in class inicializaci,
  - vytvořte ukázkový konzolový program s využitím objektů std::cout a std::cin.
- [ ] Deklarujte třídu Student v namespace utb, kdy student bude mít jméno a příjmení a výsledky tří testů. Využijte std::cout a případně std::cin a třídu std::string. Dále:
  - členské proměnné budou skryté (private) a k proměnným přistupujte pomocí veřejných (public) členských funkcí,
  - vytvořte členskou funkci, která vrátí true, pokud student získal zápočet, to znamená že z každého ze tří testů získal alespoň 15 bodů,
  - vytvořte členskou funkci, která vrátí průměr bodů ze tří testů studenta,
  - definujte dynamické pole (std::vector) studentů a vložte do něj alespoň tři studenty,
  - vypište jméno a příjmení studenta, který získal nejvíce bodů,
  - vypište průměrný počet bodů všech studentů a vypište jméno a příjmení studenta, který má svůj průměr bodů nejbližší celkovému průměru bodů,
  - vypište jména a příjmení studentů, kteří získali zápočet,
  - seřaďte studenty dle získaných bodů vzestupně a vypište jména, příjmení a průměrné body všech seřazených studentů.

### Dědičnost
- [ ] Navrhněte třídy pro automobilové součástky s použitím dědičnosti, zvolte minimálně 3 součástky a kód který by měli společné vložte do rodičovské třídy. Navrhněte dvě třídy pro automobilové součástky pro demonstraci kompozice.

### Dědičnost a překývání virtuálních členských funkcí
- [ ] Vytvořte **konzolovou aplikaci** pro správu geometrických útvaru viz. wireframe
- [ ] Vytvořte **konzolovou aplikaci** pro správu farmy zvířátek:
  - [ ] Nejdříve vytvořte verzi s jednou farmou viz wireframe farma
    - Přidání nového zvířátka do farmy
    - Výpis indexu a jména všech zvířátek ve farmě
    - Výpis detailu jednoho zvířátka dle indexu
  - [ ] Potom vytvořte verzi se třemi farmami, kdy každá farma bude mít jiné zvířátka viz wireframe 3 farmy. Funkcionalita bude stejná jako v předchozím úkolu ale navíc bude možné volit aktuální farmu, která bude mít jiné zvířátka.
- [ ] Vytvořte **konzolovou aplikaci** - klienta elektronického bankovnictví, který bude mít následující vlastností.
  - uživatel může měnit své jméno a příjmení
  - uživatel bude mít předem vytvořené 3 účty, využijte dědičnost a překrývání override členských funkcí:
    - Účet bez poplatků
    - Účet s poplatky
    - Účet s prvními třemi převody zdarma
  - Převod částky z účtu uživatele na cizí účet
  - Výpis historie zvoleného účtu uživatele

### Šablony
- [ ] Vytvořte šablonu zásobníku (a nebo fronty) s pevnou kapacitou. Využijte alokaci paměti pomocí klíčových slov new a delete.
- [ ] Vytvořte šablonu lineárního spojového seznamu a navíc vytvořte funkci, která sloučí dva seznamy
