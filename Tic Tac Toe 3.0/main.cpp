#include <iostream>
#include <string>
#include "Game.h"


//main function
int main()
{

    char answer;
    bool quit = false;
    Game game;

    while(quit == false)
    {
        game.playGame();

        std::cout<<std::endl;
        std::cout<<"Would you like to play again? (Y/N): ";
        std::cin>>answer;

        if(answer == 'N' || answer == 'n')
        {

            std::cout<<std::endl;
            std::cout<<"COME AGAIN :)"<<std::endl;
            quit = true;
        }

    }


    return 0;
}