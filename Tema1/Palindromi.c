//Datoteka razno.txt sadrži proizvoljan tekst. Napisati program koji će u datoteku palindromi.txt upisati sve reči iz datoteke razno.txt koje su palindromi. 
//Rač je palindrom ako se isto čita sa leve i sa desne strane. Za reč smatramo niz karaktera koji se nalazi izmedju belina. 
//Pretpostaviti da reči neće biti duže od 127 karaktera. Maksimalan broj reči nije poznat. U slučau greške na standardni izlaz za greške ispisati -1.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void greska(){
    fputs("-1\n",stderr);
    exit(EXIT_FAILURE);
}

int main(){
    FILE *ulaz,*izlaz;

    ulaz = fopen("razno.txt","r");
    izlaz = fopen("palindromi.txt","w");
    
    if(ulaz == NULL || izlaz == NULL){
        greska();
    }

    char rec[127];
    int br = 0;

    while(fscanf(ulaz,"%s",rec) != EOF){
        for(int i = 0; i < strlen(rec); i++){
            if(tolower(rec[i]) == tolower(rec[strlen(rec)-1-i])){
                br++;
            }
        }
        if(br == strlen(rec)){
            fprintf(izlaz,"%s ",rec);
        }
        br = 0;
    }

    fclose(ulaz);
    fclose(izlaz);
}
