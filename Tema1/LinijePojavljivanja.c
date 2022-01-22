//Sa standardnog ulaza se zadaju imena dve datoteke i prirodan broj n. U datoteci čije se ime prvo navodi se nalazi reč r i zatim proizvoljan broj linija teksta. 
//Napisati program koji će u datoteku čije se ime drugo navodi da upiše podatke o linijama koje sarže bar n pojavljivanja reči r. 
//Ispis treba da bude u formatu broj_pojavljivanja:broj_linije, pri čemu se linije broje od 1. Maksimalna dužina naziva datoteka je 63 karaktera.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
}

int main(){
    char ulaz[63],izlaz[63],rec[127],rec2[127],c;
    int n,br1 = 0,brlin = 1,br2 = 0;

    scanf("%s %s %d",ulaz,izlaz,&n);

    if(n < 1){
        greska();
    }

    FILE *fulaz,*fizlaz;

    fulaz = fopen(ulaz,"r");
    fizlaz = fopen(izlaz,"w");

    if(fulaz == NULL|| fizlaz == NULL){
        greska();
    }

    fscanf(fulaz,"%s",rec);

    while(fscanf(fulaz,"%s",rec2) != EOF){

        for(int i = 0,j = 0; i < strlen(rec2);i++,j++){
            if(rec2[i] == rec[j]){
                br1++;
            }else{
                br1 = 0;
                j = -1;
            }
            if(br1 == strlen(rec)){
                br2++;
                j = -1;
                br1 = 0;
            }
        }

        if((c = fgetc(fulaz)) == '\n'){
            if(br2 >= n){
                fprintf(fizlaz,"%d:%d\n",br2,brlin);
            }
            brlin++;
            br2 = 0;
        }
    }

    if(br2 >= n){
        fprintf(fizlaz,"%d:%d",br2,brlin);
    }

    fclose(fulaz);
    fclose(fizlaz);
}
