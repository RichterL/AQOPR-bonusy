/*
*   AQOPR 2019 / Lukas Richter
*   BONUSOVE PRIKLADY
*   -Struktury
*   --Pixely
*
*   Deklarujte strukturu Pixel a dále:
*   -definujte pole pixelů a inicializujte jej,
*   -vypište počet černých pixelů v poli pixelů,
*   -vypište hodnoty barevných složek (red, green, blue) nejtmavšího pixelu.
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct pixel {
    int r; int g; int b;
};

double tmavost(struct pixel px) {
    return (px.r * 0.299) + (px.g * 0.587) + (px.b * 0.114);
}

int main()
{
    int max=256;
    int pocet_pixelu = 1000;
    srand(time(0));
    
    struct pixel pole[pocet_pixelu];
    for (int i=0;i<pocet_pixelu;i++) {
        pole[i] = (struct pixel){rand() % max,rand() % max,rand() % max};
    }

    struct pixel nejtmavsi; struct pixel nejtmavsi_necerny; int necernych=0; int cernych = 0;
    for(int i=0; i<pocet_pixelu; i++){
        
        if(i==0) {
            nejtmavsi = pole[i];

            if(necernych==0 && tmavost(pole[i])>0) {
                nejtmavsi_necerny=pole[i];
                necernych=1;
            }            
        }
        if(tmavost(pole[i]) < tmavost(nejtmavsi)) {
            nejtmavsi=pole[i];
        }        
        if (tmavost(pole[i]) == 0) {
            cernych++;
        }
        else {
            if(tmavost(pole[i]) < tmavost(nejtmavsi_necerny)) {nejtmavsi_necerny=pole[i];}
        }
    }

    printf("cernych pixelu je %d\n", cernych);
    printf("nejtmavsi pixel ma slozky [R=%d;G=%d;B=%d].\n", nejtmavsi.r, nejtmavsi.g, nejtmavsi.b);
    printf("nejtmavsi NECERNY pixel ma slozky [R=%d;G=%d;B=%d].\n", nejtmavsi_necerny.r, nejtmavsi_necerny.g, nejtmavsi_necerny.b);

    return 0;
}
