/*
*   AQOPR 2019 / Lukas Richter
*   BONUSOVE PRIKLADY
*   -Struktury
*   --Zavody aut
*   
*   Vytvořte program pro vyhodnocení závodu aut. Zadejte jednotlivé časy a startovní čísla závodníků, 
*   zobrazte nejrychlejší čas, průměrný čas a nejpomalejší čas.
*/

#include <stdio.h>
#include <stdlib.h>

struct zavodnik {
    int id;
    double cas;
};

int main()
{
    struct zavodnik zavodnici[] = {
        {1,13.5}, {2,18.7}, {4,12.3}, {8,16.2}, {10,15.9}
    };

    int pocet_zavodniku=0; double suma_casu; struct zavodnik nejrychlejsi; struct zavodnik nejpomalejsi;
    for (int j=0; j<5; j++){
        if(j==0){ nejrychlejsi=zavodnici[j]; nejpomalejsi=zavodnici[j];}

        if(zavodnici[j].cas < nejrychlejsi.cas) {nejrychlejsi = zavodnici[j];}
        if(zavodnici[j].cas > nejpomalejsi.cas) {nejpomalejsi = zavodnici[j];}
        pocet_zavodniku++;
        suma_casu = suma_casu+zavodnici[j].cas;
    }
    double avg_cas = suma_casu / pocet_zavodniku;

    printf("prumerny cas byl %.2f\n", avg_cas);
    printf("nejpomalejsi byl jezdec cislo %d s casem %.2f\n", nejpomalejsi.id, nejpomalejsi.cas);

    printf("nejrychlejsi byl jezdec cislo %d s casem %.2f\n", nejrychlejsi.id, nejrychlejsi.cas);

    return 0;
}
