#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <cs50.h>


//print result.
void show_result(char user_pick, char machine_pick, int counter){
    printf("you won, %c beats %c, it yook %i chances for you to win.", user_pick, machine_pick, counter);
}

int main(){
    //var declaration
    int chances_counter = 1;
    char possible_picks[]={'r','p', 's'};
    bool result = 0;
    char user_pick;
    char machine_pick;



    //new seed. make sure every time the code is run genereates new machine picks.
    srand(time(NULL));

    
    do {
        //user pick input
        user_pick = get_char("pick: ");
        
        if (!(user_pick == 'r' || user_pick == 'p' || user_pick == 's')) continue;

        //machine pick
        int random_number = rand() %3;
        char machine_pick = possible_picks[random_number];
        
        //switch
        switch (user_pick)
        {
        case 'r':
            if(machine_pick == 's'){
                show_result(user_pick, machine_pick, chances_counter);
                result = 1;
            }

            break;
        
        case 'p':
            if (machine_pick == 'r'){
                show_result(user_pick, machine_pick, chances_counter);
                result =1;
            }
        
        case 's':
            if (machine_pick == 'p')
            {
                show_result(user_pick, machine_pick, chances_counter);
                result =1;
            }

        }

        //increase 1 try.
        chances_counter++;
    }while(!result);

  
}

//powered - K, JR.