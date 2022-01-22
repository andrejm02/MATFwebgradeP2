//Napisati program koji u datoteku izlaz.txt prepisuje sve reči iz datoteke ulaz.txt čiji je zbir ASCII kodova strogo veći od 1000. 
//Reči su odvojene prazninama i nisu duže od 255 karaktera. U slučaju greške na standardni izlaz za greške ispisati -1.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
}

int main(){
    FILE* ulaz,*izlaz;
    ulaz = fopen("ulaz.txt","r");
    izlaz = fopen("izlaz.txt","w");
    if(ulaz == NULL || izlaz == NULL){
        greska();
    }

    char rec[255];
    int zbir = 0;

    while(fscanf(ulaz,"%s",rec) != EOF){
        for(int i = 0; i < strlen(rec); i++){
            zbir += rec[i];
        }
        if(zbir > 1000){
            fprintf(izlaz,"%s ",rec);
        }
        zbir = 0;

    }
    
    fclose(ulaz);
    fclose(izlaz);
}
