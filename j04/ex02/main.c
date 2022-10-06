#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void start_game(char user_1, char user_2, int nb_questions){

    char questions[3][2][100] = { {"question1","reponse1"},{"question2","reponse2"},{"question3","reponse3"} };

    size_t nb_lst_questions = sizeof(questions[0]) / sizeof(questions[0][0]);
    for (int i = 0; i < nb_questions; i++){

        printf("%ld\n", rand() % nb_lst_questions);

    }


}




void main(){

    char user_1,user_2;
    int nb_questions;

        printf("Nom du joueur user_1 : ");
        scanf("%s", &user_1);
        printf("\n");
        printf("Nom du joueur user_2 : ");
        scanf("%s", &user_2);
        printf("\n");
        printf("Combien de questions voulez vous ? : ");
        scanf("%d", &nb_questions);


    if (user_1 != 0 && user_2 != 0){

        start_game(user_1,user_2,nb_questions);

    }

}