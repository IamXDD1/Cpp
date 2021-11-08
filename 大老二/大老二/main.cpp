#include <iostream>
#include <time.h>
#include <stdlib.h>

bool deal_check = false;

struct Player
{
    int i_cards[13];
    char ch_card[13][2];
};

void Run_Game(Player* player);
void command();
void deal(Player* player);
void output_player_card(Player* player, int player_num);
void choose_player(Player* player);
char num_to_cardsuit(int num);
char num_to_cardnum(int num);

int main()
{
    Player player[4];

    Run_Game(player);
    return 0;
}

void Run_Game(Player* player){
    command();
    for(int input = 0; input != EOF;)
    {
        std::cout<< "Please Input a number: ";
        std::cin>> input;
        switch(input)
        {
            case 0: command();                  break;
            case 1: deal(player);               break;
            case 2:
                if(deal_check) choose_player(player);
                else std::cout<<"Does't deal yet.\n";      break;
            default: std::cout<< "Wrong Input!\nPlease Input Again.\n";
        }
    }
}
void command(){
    std::cout<< "Command:\n0 : help\n1 : deal\n2 : player\n";
}
void deal(Player* player){

    bool bl_card[52] = {};
    srand(time(NULL));
    deal_check = true;

    for(int i = 0; i < 13; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            for(int temp = 0;;)
            {
                temp = rand()%52;
                if(bl_card[temp] == false)
                {
                    player[j].ch_card[i][0] = num_to_cardsuit(temp);
                    player[j].ch_card[i][1] = num_to_cardnum(temp);
                    bl_card[temp] = true;
                    player[j].i_cards[i] = temp;
                    break;
                }
            }
        }
    }
    std::cout<<"deal success!\n";
}
void output_player_card(Player* player, int player_num){

    std::cout<<"P"<<player_num+1<<" cards: ";

    for(int i = 0; i < 13; i++)
    {
        for(int k=0; k<2; k++)
            std::cout<<player[player_num].ch_card[i][k];

        std::cout<<" ";
    }
    std::cout<<"\n";
}
void choose_player(Player* player){
    int input = 0;
    std::cout<< "\nChoose Player to check card.(Input 1~4, 0 is back to command): P";
    std::cin>> input;
    for(; input==1 || input==2 || input==3 || input==4;)
    {
        switch(input)
        {
            case 1: output_player_card(player, 0); break;
            case 2: output_player_card(player, 1); break;
            case 3: output_player_card(player, 2); break;
            case 4: output_player_card(player, 3); break;
        }
        std::cout<< "\nChoose Player (Input 1~4): P";
        std::cin>> input;
    }
    std::cout<<"\n";
    command();
}
char num_to_cardsuit(int num){
    switch(num / 13)
    {
        case 0: return 'S';
        case 1: return 'H';
        case 2: return 'D';
        case 3: return 'C';
    }
    return '0';
}
char num_to_cardnum(int num){
    switch(num % 13)
    {
        case 0:  return 'A';
        case 1:  return '2';
        case 2:  return '3';
        case 3:  return '4';
        case 4:  return '5';
        case 5:  return '6';
        case 6:  return '7';
        case 7:  return '8';
        case 8:  return '9';
        case 9:  return 'T';
        case 10: return 'J';
        case 11: return 'Q';
        case 12: return 'K';
    }
    return '0';
}
