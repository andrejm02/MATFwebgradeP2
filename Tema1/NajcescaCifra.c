//Napisati program koji sa standardnog ulaza čita naziv ulazne datoteke i na standardni izlaz ispisuje cifru koja se najviše puta pojavljuje u toj datoteci. 
//Ukoliko ima više takvih cifara, ispisati najmanju. Ukoliko datoteka ne sadrži ni jednu cifru, ispisati -1. 
//Maksimalna dužina naziva datoteke je 20 karaktera. U slučaju greške, na standardni izlaz za greške ispisati -1.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void greska(){
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
}

int main(){

    char ulaz[21],c;
    scanf("%s",ulaz);
    FILE* fulaz;
    int a[10],max = 0,isnum = 0,maxdig = 0;

    for(int i = 0; i <= 9; i++){
        a[i] = 0;
    }

    fulaz = fopen(ulaz,"r");
    if(fulaz == NULL){
        greska();
    }
    
    while((c = fgetc(fulaz)) != EOF){
        if(isdigit(c)){
            a[c - 48]++;
        }
    }

    for(int i = 0; i <= 9; i++){
        if(a[i] == 0){
            isnum++;
        }
        if(a[i] > max){
            max = a[i];
            maxdig = i;
        }
    }

    if(max == 0){
        puts("-1");
        return 1;
    }

    printf("%d\n",maxdig);

    fclose(fulaz);
}
