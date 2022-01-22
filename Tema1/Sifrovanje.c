//Napisati program koji za dve datoteke čija se imena zadaju na standardnom ulazu radi sledeće: za svaku cifru iz prve datoteke, u drugu datoteku upisuje 0 
//za svako slovo upisuje 1, a za sve ostale karaktere upisuje 2. U slučaju greške na standardni izlaz za greške ispisati -1. 
//Maksimalna dužina naziva datoteka je 63 karaktera.
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void greska(){
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
}

int main(){
    char dat1[63],dat2[63],c;
    scanf("%s %s",dat1,dat2);

    FILE* fdat1, *fdat2;
    fdat1 = fopen(dat1,"r");
    fdat2 = fopen(dat2, "w");

    if(fdat1 == NULL || fdat2 == NULL){
        greska();
    }
    
    while((c = fgetc(fdat1)) != EOF){
        if(isdigit(c)){
            fprintf(fdat2,"0");
        }else if(isalpha(c)){
            fprintf(fdat2,"1");
        }else{
            fprintf(fdat2,"2");
        }
    }
    
    fclose(fdat1);
    fclose(fdat2);

}
