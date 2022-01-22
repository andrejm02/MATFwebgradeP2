//Sa standardnog ulaza se učitava pozitivan broj k i ime datoteke u kojoj se prvo nalazi nenegativan broj n, a zatim i n celih brojeva. 
//Napisati program koji prebrojava koliko k-tocifrenih brojeva ima u datoteci. Rezultat ispisati na standardni izlaz. 
//Pretpostaviti da se u datoteci nalaze samo brojevi. U slučau greške na standardni izlaz za greške ispisati -1. Maksimalna dužina naziva datoteke je 63 karaktera.
#include <stdio.h>
#include <stdlib.h>

void greska(){
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
}

int main(){
    int a,n,m,br = 0,br2 = 0;
    char ulaz[63];
    scanf("%d %s",&a,ulaz);

    if(a < 1){
        greska();
    }

    FILE* fulaz;

    fulaz = fopen(ulaz, "r");

    if(fulaz == NULL){
        greska();
    }

    fscanf(fulaz,"%d",&n);

    if(n < 0){
        greska();
    }

    for(int i = 0; i < n; i++){
        fscanf(fulaz,"%d",&m);
        m = abs(m);
        while(m > 0){
            br++;
            m /= 10;
        }
        if(br == a){
            br2++;
        }
        br = 0;
    }
    printf("%d\n",br2);

    fclose(fulaz);
}
