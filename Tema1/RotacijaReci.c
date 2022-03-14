//Sa standardnog ulaza se učitava ime tekstualne datoteke i nenegativan broj k. Podrazumevati da će svaka reč u datoteci biti dužine najviše 127 karaktera. 
//Napisati program koji će svaku reč iz ove datoteke rotirati za k mesta ulevo i tako dobijene reči upisati u datoteku čiji je naziv rotirano.txt. 
//U slučaju greške na standardni izlaz za greške ispisati -1. Maksimalna dužina naziva datoteke je 63 karaktera.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
}

int main(){
    char ulaz[63],rec[127];
    int k, i;
    scanf("%s %d",ulaz,&k);
    FILE* fulaz, *izlaz;

    fulaz = fopen(ulaz,"r");
    izlaz = fopen("rotirano.txt","w");

    if(fulaz == NULL || izlaz == NULL || k < 0){
        greska();
    }
    
    while(fscanf(fulaz,"%s",rec) != EOF){

        if(strlen(rec) > k){
            for(i = k; i < strlen(rec);i++){
                fprintf(izlaz,"%c",rec[i]);
            }
            for(int j = 0; j < k; j++){
                fprintf(izlaz,"%c",rec[j]);
            }
        }else if(strlen(rec) == k){
            for(int i = 0; i < strlen(rec); i++){
                fprintf(izlaz,"%c",rec[i]);
            }
        }else{
            for(int i = strlen(rec)-1; i >= 0; i--){
                fprintf(izlaz,"%c",rec[i]);
            }
        }

        fprintf(izlaz," ");
    }

    fclose(fulaz);
    fclose(izlaz);
}
