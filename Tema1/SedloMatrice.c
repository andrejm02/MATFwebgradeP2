//Kao argumenti komandne linije se zadaju dimenzije matrice A (m i n). 
//Napisati program koji sa standardnog ulaza učitava matricu A i na standardni izlaz ispisuje podatke o elementima matrice koji su sedlo. 
//Element matrice je sedlo ukoliko je istovremeno najmanji u svojoj vrsti, a najveći u svojoj koloni. 
//Ispisati indekse i vrednosti onih elemenata matrice koji su sedlo. Pretpostaviti da je maksimalna dimenzija matrice 50*50. 
//U slučaju greške na standardni izlaz za greške ispisati -1.
#include <stdio.h>
#include <stdlib.h>

void greska(){
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
}

int main(int argc,char *argv[]){
    int a[argc],min = 1000,mini = 0,minj = 0,br = 0;

    if(argc != 3){
        greska();
    }

    for(int i = 1; i < argc; i++){
        a[i] = atoi(argv[i]);
        if(a[i] < 1 || a[i] > 50){
            greska();
        }
    }

    int b[a[1]][a[2]];

    for(int i = 0; i < a[1]; i++){
        for(int j = 0; j < a[2];j++){
            scanf("%d",&b[i][j]);
        }
    }

    for(int i = 0;i < a[1]; i++){
        for(int j = 0; j < a[2];j++){
            if(b[i][j] < min){
                min = b[i][j];
                mini = i;
                minj = j;
            }
        }
        for(int j = 0; j < a[1];j++){
            if(b[mini][minj] > b[j][minj]){
                br++;
            }
        }
        if(br == a[1] - 1){
            printf("%d %d %d\n",mini,minj,b[mini][minj]);
        }
        br = 0;
        min = 1000;
    }
}
