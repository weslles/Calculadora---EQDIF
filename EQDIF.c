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


int main(){
 
    do {
        menu();
        switch (item){
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
                    printf("dy/dx = %s\n\n com as condicoes iniciais dadas y = %4.2f em x = %4.2f), e:\n\nf(x) = %s\n", func, val_y, val_x, eqdif);
                    printf("Pressione uma tecla!");
                    while (!kbhit());
                }
                break;
            case 0:
                break;
        }
    }while (item != 0);
    
    return 0;
}

void menu(void){
    do{

        printf("\n(0) - Sair");
        printf("\n(1) - Entrada de Dados");
        printf("\n(2) - Calcular Solucao da Equacao Diferencial\n\n");

        scanf("%d", &item);
        if ( (item > 2) || (item < 0) ){
            printf("Invalido!! Pressione uma tecla!");
            while( !kbhit() );
        }    
    }while ( ( item < 0) || (item > 2) );
}

void dadossin (void){
    char functemp[20] = "";
    
    printf("\nEntrando com a equacao diferencial dy/dx: ");
    printf("Entre com o valor da maior potencia de x da equacao diferencial> ");
    do{
        scanf("%d", &maior_pot);
    }while(maior_pot > max_pot);

    for(cont = 0; cont < (maior_pot +1); cont++){
        printf("\nEntre com o valor da constate da potencia de %d de x da equacao diferencial: ", maior_pot - cont);
        scanf("%f", &cons_func[cont]);
    }

    for (cont =0; cont < maior_pot+1; cont++){
        if( cont == 0){
            if( (maior_pot - cont) > 1){
                sprintf(functemp, "%4.2fx^%d", cons_func[cont], maior_pot - cont );
            }
            else if( (maior_pot - cont) == 1 ){
                sprintf(functemp, "%4.2fx", cons_func[cont]);
                strcat(func, functemp);
            }else if ((maior_pot - cont) == 0){
                sprintf(functemp, "%4.2f", cons_func[cont]);
                strcat(func, functemp);
            }
        }else if( (maior_pot - cont) == 1 ){
            if(cons_func[cont] > 0 ){
                sprintf(functemp, "+ %4.2fx", cons_func[cont]);
                strcat(func, functemp);
            }
            else if( cons_func[cont] < 0 ){
                sprintf(functemp, "%4.2fx", cons_func[cont]);
                strcat(func, functemp);
            }
        }else if( (( maior_pot - cont) > 1) && cont != 0 ){
            if (cons_func[cont] > 0 ){
                sprintf(functemp, "+ %4.2fx^%d", cons_func[cont], maior_pot-cont );
                strcat(func, functemp);
            }else if( cons_func[cont] < 0 ){
                sprintf(functemp, "%4.2f^x", cons_func[cont], maior_pot-cont);
                strcat(func, functemp);
            }
        }else if ( (maior_pot - cont) == 0 ){
            if(cons_func[cont] > 0 ){
                sprintf(functemp, "+ %4.2f", cons_func[cont]);
                strcat(func, functemp);
            }
            if ( cons_func[cont] < 0 ){
                sprintf(functemp, "%4.2f", cons_func[cont]);
                strcat(func, functemp);
            }
        }
    }

    printf("\nEntre com a condicao Inicial 'Y': ");
    scanf("%f", &val_y);
    printf("\nEntre com a condicao Inicial 'X': ");
    scanf("%f", &val_x);
    
    printf("\n\nA Equacao Diferencial eh:\ndy/dx = %s", func);
    printf("\n\nAs condicoes iniciais sao: \ny = %4.2f\nx = %4.2f", val_y, val_x);
    printf("\n\nDados completos! Pressione uma tecla...");
    while ( !kbhit() );
    dados = 1;

}

void calceqdif(void){
    char functemp[20] = "";
    float val_ed;

    for (cont = 0; cont < maior_pot +1; cont++){
        cons_ed[cont] = cons_func[cont] / (maior_pot - cont + 1); 
    }
    strcpy(eqdif, "");

    for (cont = 0; cont < maior_pot +1; cont++){
        if (cont == 0){
            if((maior_pot - cont + 1)> 1){
                sprintf(functemp, "%4.2fx^%d", cons_ed[cont], maior_pot- cont + 1);
                strcat(eqdif, functemp);
            }
            else if((maior_pot - cont + 1) == 1){
                sprintf(functemp, "%4.2fx", cons_ed[cont]);
                strcat(eqdif, functemp);
            }else if((maior_pot - cont - 1 ) == 0){
                sprintf(functemp, "%4.2f", cons_ed[cont]);
                strcat(eqdif, functemp);
            }
        }
        else if((maior_pot - cont + 1) == 1){
            if(cons_ed[cont] > 0){
                sprintf(functemp, "+ %4.2fx", cons_ed[cont]);
                strcat(eqdif, functemp);
            }else if(cons_ed[cont] < 0){
                sprintf(functemp, "%4.2fx", cons_ed[cont]);
                strcat(eqdif, functemp);
            }
        }else if ( ((maior_pot - cont + 1) > 1) && (cont != 0)){
            if (cons_ed[cont] > 0){
                sprintf(functemp, "+ %4.2fx^%d", cons_ed[cont], maior_pot - cont +1);
                strcat(eqdif, functemp);
            }
            else if( cons_ed[cont] < 0){
                sprintf(functemp, "%4.2fx^%d", cons_ed[cont], maior_pot - cont + 1);
                strcat(eqdif, functemp);
            }
        }else if( (maior_pot - cont + 1) == 0){
            if (cons_ed[cont] > 0){
                sprintf(functemp, "+ %4.2f", cons_ed[cont]);
                strcat(eqdif, functemp);
            }else if (cons_ed < 0 ){
                sprintf(functemp, "%4.2f", cons_ed[cont]);
                strcat(eqdif, functemp);
               }   
        }
    }

    val_ed = 0;

    for (cont = 0; cont < maior_pot +1; cont++){
        if ((maior_pot + 1 - cont ) > 0){
            val_ed = val_ed + cons_ed[cont] * pow(val_x, (double)maior_pot+1-cont);
        }else{
            val_ed += cons_ed[cont];
        }
    }
    const_ed = val_y - val_x;

    if(cons_ed > 0){
        sprintf(functemp, "+ %4.2f", cons_ed);
    }else if(cons_ed < 0){
        sprintf(functemp, "%4.2f", cons_ed);
    }
    strcat(eqdif, functemp);

}