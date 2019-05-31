#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <math.h>

int max_pot = 10, cont, item, dados=0, maior_pot=0;
char func[300], eqdif[400];
float cons_func[10], cons_ed[10], const_ed, val_y, val_x;

void menu (void);
void dadossin (void);
void calceqdif (void);

void main(){
    ckrscr();

    do {
        menu();
        switch (item){
            {
            case 1:
                dadossin();
                break;
            case 2:
                if(!dados){
                    printf("\nNao houve entrada de dados!\n");
                    printf("Pressione uma tecla!");
                    while (!kbhit());
                }else{
                    calceqdif();
                    printf("\n\nSolucao da Equacao Diferencial da Funcao\n\n");
                    printf("dy/dx = %s\n\n com as condicoes iniciais dadas
                            (y = %4.2f em x = %4.2f), e:\n\nf(x) = %s\n", func, val_y, val_x, eqdif);
                    printf("Pressione uma tecla!");
                    while (!kbhit());
                }
                break;
            case 0:
                break;
        }while (item != 0);
        
    }
}

void menu(void){
    do{
        clrscr();
        printf("\n(0) - Sair");
        printf("\n(1) - Entrada de Dados");
        printf("\n(2) - Calcular Solucao da Equacao Diferencial\n\n");

        scanf("%d", &item);
        if ( (item > 2) || (item < 0) ){
            printf("Invalido!! Pressione uma tecla!");
            while( !kbhit() );
        }        //Págia 187
    }while ( ( item < 0) || (item > 2) );
}

void dadossin (void){
    char functemp[20] = "";
    clrscr();

    printf("\nEntrando com a equacao diferencial dy/dx: ");
    printf("Entre com o valor da maior potencia de x da equacao diferencial> ");
    do{
        scanf("%d", &maior_pot);
    }while(maior_pot > max_pot);

    for(cont = 0; cont < (maior_pot +1); cont++){
        printf("\nEntre com o valor da constate da potencia de %d de x da equacao diferencial: ", maior_pot - cont);
        scanf("%f", cons_func[cont]);
    }

}