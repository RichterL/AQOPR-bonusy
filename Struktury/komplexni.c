/*
*   AQOPR 2019 / Lukas Richter
*   BONUSOVE PRIKLADY
*   -Struktury
*   --Komplexni cisla
*
*   Deklarujte strukturu komplexní číslo, definujte pole komplexních čísel, 
*   napište program, který vypíše hodnoty největšího komplexního čísla dle absolutní hodnoty.
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct complex {
    double x; double y;
};
double abs_c(struct complex cislo) {
    double abs = sqrt(pow(cislo.x,2)+pow(cislo.y,2));
    return abs;
}

int main()
{

    struct complex pole_c[] = {
    {2,4}, {3,-3}, {4,6}, {-5,3}
    };
    double abs_max; double abs; struct complex c_max;
    for(int k=0;k<4;k++){
        abs = abs_c(pole_c[k]);
        if(k==0) { c_max = pole_c[0]; abs_max = abs;}

        if (abs>abs_max) {abs_max = abs; c_max=pole_c[k];}
    }

    printf("absolutni hodnota nejvetsiho cisla [%.2f,%.2f] je %.4f\n", c_max.x, c_max.y, abs_c(pole_c[0]));

    return 0;
}
