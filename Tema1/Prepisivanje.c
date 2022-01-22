//Napisati program koji sa standardnog ulaza učitava imena dve datoteke (ulazna i izlazna datoteka) i iz ulazne datoteke kopira u izlaznu datoteku svaki 
//drugi karakter, polazeći od prvog pročitanog karaktera. U slučaju greške na standardni izlaz za greške ispisati -1. 
//Maksimalna dužina naziva datoteka je 20 karaktera.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
}

int main(){
    char ulaz[21],izlaz[21],niska[21];

    scanf("%s %s",ulaz,izlaz);
    
    FILE* fulaz, *fizlaz;
    
    fulaz = fopen(ulaz,"r");
    
    fizlaz = fopen(izlaz,"w");

    if(fulaz == NULL || fizlaz == NULL){
        greska();
    }

    while(fscanf(fulaz,"%s",niska) != EOF){
        for(int i = 0; i < strlen(niska); i++){ 
            if(i%2 == 0){
                fprintf(fizlaz,"%c",niska[i]);
            }
        }
        fprintf(fizlaz," ");
    }

    fclose(fulaz);
    fclose(fizlaz);
}
