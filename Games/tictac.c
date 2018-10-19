#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

char tictac [3] [3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };
int x = 0;
int y = 0;
char alpha;
int gamon = 0;


void display();
int valid(int p);
void assign (int any);
char player (int aa);
int winner (void);
//main
int main(void) {

    display();



    while(gamon < 9){
        player (gamon);

        int a = 0;

        if(gamon % 2 == 0){
            printf("Choose a position player 1: ");
        }
        else {
            printf("Choose a position player 2: ");
        }

        scanf("%d", &a);

        int playernumber = 2;

        playernumber = valid(a);

        //printf("%d\n", playernumber);


        while( playernumber != 1 ){
            printf("Invalid input. Try again: ");
            scanf("%d", &a);
            playernumber = valid(a);
        }

        if( valid(a) == 1 ){
            assign (a);

            gamon++;
        }

        display();

        int winnerdeclare = winner();
        //printf("%d\n", winnerdeclare);
        if (winnerdeclare == 2){
            printf("Player 1 wins\n");
            break;
        }
        else if (winnerdeclare == 1){
            printf("Player 2 wins\n");
            break;
        }

    }
}


//funtion to display tictactoe
void display() {
    //printf("i am in display\n");
    for(x=0; x<3; x++) {
            for(y=0; y<3; y++) {
                printf("%c ", tictac [x] [y]);
            }
            printf("\n");
        }
}

//function to check if input is valid or not
int valid (int p){
     p--;

     if ((p>0 || p<9) && tictac [p/3] [p%3] - 48 == (char) p + 1) {
        return 1;
     }

     return 0;
}


//function to assign value
void assign (int any){
    any--;
    int e = any/3;
    int f = any%3;
    tictac [e] [f] = alpha;

}

 // player 1 or 2
char player (int aa){

            if(aa%2 == 0){
               return alpha = 'x';
            }
            else{
               return alpha = 'o';
            }
    }

//functon to check winner
int winner (){
if(
        (tictac [0] [0] == 'o' && tictac [0] [1] == 'o' && tictac [0] [2] == 'o') ||
        (tictac [1] [0] == 'o' && tictac [1] [1] == 'o' && tictac [1] [2] == 'o') ||
        (tictac [2] [0] == 'o' && tictac [2] [1] == 'o' && tictac [2] [2] == 'o') ||
        (tictac [0] [0] == 'o' && tictac [1] [0] == 'o' && tictac [2] [0] == 'o') ||
        (tictac [0] [1] == 'o' && tictac [1] [1] == 'o' && tictac [2] [1] == 'o') ||
        (tictac [0] [2] == 'o' && tictac [1] [2] == 'o' && tictac [2] [2] == 'o') ||
        (tictac [0] [0] == 'o' && tictac [1] [1] == 'o' && tictac [2] [2] == 'o') ||
        (tictac [0] [2] == 'o' && tictac [1] [1] == 'o' && tictac [2] [0] == 'o')){
            return 1;
        }

 else if(
        (tictac [0] [0] == 'x' && tictac [0] [1] == 'x' && tictac [0] [2] == 'x') ||
        (tictac [1] [0] == 'x' && tictac [1] [1] == 'x' && tictac [1] [2] == 'x') ||
        (tictac [2] [0] == 'x' && tictac [2] [1] == 'x' && tictac [2] [2] == 'x') ||
        (tictac [0] [0] == 'x' && tictac [1] [0] == 'x' && tictac [2] [0] == 'x') ||
        (tictac [0] [1] == 'x' && tictac [1] [1] == 'x' && tictac [2] [1] == 'x') ||
        (tictac [0] [2] == 'x' && tictac [1] [2] == 'x' && tictac [2] [2] == 'x') ||
        (tictac [0] [0] == 'x' && tictac [1] [1] == 'x' && tictac [2] [2] == 'x') ||
        (tictac [0] [2] == 'x' && tictac [1] [1] == 'x' && tictac [2] [0] == 'x')){
            return 2;
        }
else {
    return 0;
}



}
