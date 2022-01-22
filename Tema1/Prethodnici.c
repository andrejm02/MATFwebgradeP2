//Ako je data tekstualna datoteka plain.txt napraviti tekstualnu datoteku sifra.txt koja će sadržati sledeći sadržaj: svako slovo iz plain.txt treba 
//zameniti sa njegovim prethodnikom suprotne veličine. Na primer, za slovo 'b' prethodnik je 'a', a prethodnik suprotne veličine je 'A'. 
//Za slovo 'D' prethodnik suprotne veličine je 'c' itd. Prethodnike treba računati ciklično (za slovo 'a', prethodnik suprotne veličine je 'Z'). 
//Sve karaktere koji nisu slova treba ostaviti nepromenjenim. U slučaju greške na standardni izlaz za greške ispisati -1.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void greska(){
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
}

int main(){

    FILE* plain,*sifra;
    plain = fopen("plain.txt","r");
    sifra = fopen("sifra.txt","w");
    if(plain == NULL || sifra == NULL){
        greska();
    }

    char c;

    while((c = fgetc(plain)) != EOF){
        if(isalpha(c)){
            if(isupper(c)){
                c = tolower(c);
            }else{
                c = toupper(c);
            }
            if(c != 'a' && c!= 'A'){
                fprintf(sifra,"%c",c-1);
            }else{
                if(isupper(c)){
                    c = 'Z';
                }else if(islower(c)){
                    c = 'z';
                }
                fprintf(sifra,"%c",c);
            }
        }else{
            fprintf(sifra,"%c",c);
        }
    }

    fclose(plain);
    fclose(sifra);  
}
