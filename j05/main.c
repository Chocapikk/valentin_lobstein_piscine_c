#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int o_digit_to_int(char d){

    char str[2];
    str[0] = d;
    str[1] = '\0';
    return (int) strtol(str, NULL, 10);
}


void display(int **tic_tac_toe){ 

    printf("    1    2    3\n");

    for(int i = 0; i < 3; i++){
        
        printf(" ----------------\n");
        for(int j = 0; j < 3; j++){
            
            printf(" | ");

            switch(tic_tac_toe[i][j]){

                case 0:
                    printf("  ");
                    break;
                case 1:
                    printf("X ");
                    break;
                case 2 :
                    printf("O ");
                    break;

            }        
        }

        printf(" | %d", i + 1);

    printf("\n");
    }

    printf(" ----------------\n\n");


}

void fill_cell(char *cell, int **tic_tac_toe, int *player){
    
    int i,j;
    
    /*printf("Avant : %d\n\n", player);*/

    if (*player == 1)
        *player = 2;

    else if(*player == 2)
        *player = 1;

    else
        printf("Something bad happened !\n");

    /*printf("Après : %d\n\n", player);*/

    if (strlen(cell) > 2 || strlen(cell) < 1){

        printf("Error, please provide only 2 digits (%ld characters), next player :) !!!\n\n",strlen(cell));
    
    }

    else{
       
        i = o_digit_to_int(cell[1]) - 1;
        j = o_digit_to_int(cell[0]) - 1;

        if(i >= 0 && i <=2 && j >= 0 && j <=2){

            if (tic_tac_toe[i][j] == 0){

                tic_tac_toe[i][j] = *player;
            
            }

            else{ 
                printf("Error, please don't erase used cells !! Next player :)\n\n\n\n");
                sleep(1);
            }
        }

        else{
            printf("Error, this cell doesn't exist ! Next player :)\n\n\n\n");
            sleep(1);
        }

    system("clear"); 
    display(tic_tac_toe);
    
    }
}

int **init_game(){

    int** tic_tac_toe;
    tic_tac_toe = (int** )malloc(3 * sizeof(int*));

    for(int index = 0; index < 3; ++index ){
        tic_tac_toe[index] = (int*) malloc(3 * sizeof(int));
    }

    display(tic_tac_toe);

    return tic_tac_toe; 
}


int main(){

    system("clear"); 

    printf("Welcome to the Tic Tac Toe game, please type something to start !...");
    
    scanf("%s");

    char fill_test[100];
    int player = 1;

    int **tic_tac_toe = init_game();

    while(1){

        printf("Fill a number Player %d ([column][line]): ", player);
        scanf("%s",fill_test);
        printf("\n");

        fill_cell(fill_test, tic_tac_toe, &player);
    }
    
    return EXIT_SUCCESS;

}