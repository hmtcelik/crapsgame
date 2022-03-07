#include<stdio.h>
#include<stdlib.h>
#include<time.h> 

// github: hmtcelik

int main(){
/*
Rules:
- Roll two dice
- Sum of the spots on two upward faces is calculated
- 7 or 11 on first throw player wins
- 2, 3 or 12 on first throw player loses
- First throw of 4, 5, 6, 8, 9, 10 becomes players point.
- Player must roll his dices till he win or lose:
    - If he rolled his point before rolling 7 he wins, if he rolled 7 he loses.
*/
    int dice1;
    int dice2;
    int sum_of_dices;
    int player_point;
    int end_the_game=0;
    
    printf(" --------- CRAPS GAME  ----------\n");

    // First Throw
    srand (time(NULL));
    dice1 = 1 + rand() % 6;
    dice2 = 1 + rand() % 6;
    
    sum_of_dices = dice1 + dice2;

    printf("Dice 1 = %d\n", dice1);
    printf("Dice 2 = %d\n", dice2);
    printf("Sum of dices = %d\n\n", sum_of_dices);

    if (sum_of_dices == 7 || sum_of_dices == 11){
        printf("!!!!! You Won !!!!!\n");
        end_the_game = 1;
    }
    else if (sum_of_dices == 2 || sum_of_dices == 3 || sum_of_dices == 12){
        printf("!!!!! You Lost !!!!!\n");
        end_the_game = 1;
    }
    else{
        player_point = sum_of_dices;
        end_the_game = 0;
        printf("!!! WARNING !!!\n");
        printf("Your Point is %d\nand you have to find this number on next throws \nbefore find 7 !!\n\n\n", player_point);
    }

    // Other Throws    
    if (end_the_game != 1){
        while (1){
            printf("Throwing Again...\n\n");
    
            dice1 = 1 + rand() % 6;
            dice2 = 1 + rand() % 6;

            sum_of_dices = dice1 + dice2;

            printf("Dice 1 = %d\n", dice1);
            printf("Dice 2 = %d\n", dice2);
            printf("Sum of dices = %d\n", sum_of_dices);
            printf("---------------------------------\n");

            if (sum_of_dices == 7){
                printf("!!!!! You Lost !!!!!\n");
                break;
            }
            else if (sum_of_dices == player_point){
                printf("!!!!! You Won !!!!!\n");
                break;
            }
        }
    }
}
