#include <stdio.h>
 
#define TRUE 1
 
int someone_has_won(){
     
    return 0;
     
}
 
int someone_wants_to_quit(){
     
    return 0;
     
    }
 
int take_turn(){
     
    return 0;
}
 
int main(int argc, char **argv)
{
    int player1 = 0;
    int player2 = 1;
    int true = 1;
     
    while(true)
{
    if (someone_has_won() || someone_wants_to_quit() == TRUE)
    {break;}
    take_turn(player1);
    if (someone_has_won() || someone_wants_to_quit() == TRUE)
    {break;}
    take_turn(player2);
}
    return 0;
}