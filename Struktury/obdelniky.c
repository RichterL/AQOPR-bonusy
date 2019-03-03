/*
*   AQOPR 2019 / Lukas Richter
*   
*   BONUSOVE PRIKLADY
*   - Struktury
*   -- Obdelniky

*   Deklarujte strukturu Obdelnik reprezentující obdélník (nebo kruh, čtverec atd.) a dále definujte:
*   -proměnnou x typu obdélník,
*   -dvě funkce pro výpočet obsahu a obvodu obdélníka:
*   --první funkce bude mít jako parametr proměnnou typu struktura Obdelnik,
*   --druhá funkce bude mít jako parametr ukazatel na proměnnou typu struktura Obdelnik
*   -s použitím první i druhé funkce spočítejte a vypište obvod a obsah proměnné x,
*   -proměnnou y typu Obdelnik a kód, který určí, zda je proměnná x větší nebo rovna (podle rozměrů) proměnné y,
*   -definujte pole obdélníků a inicializujte jej a spočítejte sumu obsahů, průměrný obsah a vypište rozměry největšího a nejmenšího obdélníku v poli
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// deklarace struktury obdelnik
struct obdelnik {
    int a;
    int b;
};

// funkce s ukazatelem na promennou struct jako parametr
int obvod(struct obdelnik* o) {
    return 2*(o->a + o->b);
}

// funkce se samotnou promennou struct jako parametr
int obsah(struct obdelnik o) {
    return o.a * o.b;
}

int main()
{
        // inicializace promenne x typu obdelnik
        struct obdelnik x = { 5,10 };
        struct obdelnik* p = &x;

        int obv = obvod(p);
        int obs = obsah(x);
        printf("obvod je %d a obsah je %d \n", obv, obs);

        // inicializace promenne y a porovnani x >= y
        struct obdelnik y = { 6,12 };
        if ( obsah(x) > obsah(y) ) {
            printf("obdelnik y je mensi nez obdelnik y \n");
        }
        else {
            printf("obdelnik y je vetsi nebo roven obdelniku x \n");
        }

        // inicializace pole obdelniku
        struct obdelnik pole[] = {
            {2,4}, {5,5}, {3,5}, {6,8}
        };

        // vypocet sumy obsahu, prumerneho obsahu a vypsani nejmensiho a nejvetsiho obdelnika
        int suma_obsahu=0; int pocet; struct obdelnik nejvetsi; struct obdelnik nejmensi;
        for(int i=0; i<4; i++) {
            if (i==0){
                nejvetsi = pole[i]; nejmensi = pole[i];
            }
            suma_obsahu = suma_obsahu + obsah(pole[i]);
            if ( obsah(pole[i]) > obsah(nejvetsi) ) {nejvetsi = pole[i];}
            if ( obsah(pole[i]) < obsah(nejmensi) ) {nejmensi = pole[i];}
            pocet++;
        }
        double avg_obsah = suma_obsahu / pocet;
        printf("suma obsahu zadanych obdelniku je %d a prumerny obsah je %.2f\n", suma_obsahu, avg_obsah);
        printf("nejvetsi obdelnik ma strany %d a %d\n", nejvetsi.a, nejvetsi.b);
        printf("nejmensi obdelnik ma strany %d a %d\n", nejmensi.a, nejmensi.b);

    return 0;
}
