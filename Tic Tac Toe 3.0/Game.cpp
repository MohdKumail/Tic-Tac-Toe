
#include <iostream>
#include <string>
#include "Game.h"


Game::Game()
{
    clearBoard();
}

//play game function
void Game::playGame()
{
    //welcome name
    space();
    welcomeMessage();
    space();

    //players name
    std::string  playerOneName = getPlayerOneName();
    space();
    std::string  playerTwoName = getPlayerTwoName();
    space();
    std::string currentPlayerName = playerOneName;

    char playerOneSymbol = getPlayerOneSymbol();
    space();
    char playerTwoSymbol = getPlayerTwoSymbol();
    space();
    char currentPlayer = playerOneSymbol;

    //other variables
    int turn = 0;
    bool isDone = false;
    int x,y;


    while(isDone == false)
    {
        printBoard();
        space();
        x = getXCood();
        y = getYCood();
        space();
        if (placeMarker(x,y,currentPlayer) == false)
        {
            std::cout<<"THAT PLACE IS OCCUPIED!"<<std::endl;

        }
        else
        {

            turn++;
            if(checkVictory(currentPlayer) == true )
            {
                space();
                std::cout<<"THE GAME IS OVER & THE WINNER IS: "<<currentPlayerName<<std::endl;
                isDone = true;
            }
            else if(turn == 9)
            {
                space();
                std::cout<<"THE GAME IS OVER AND ITS A TIE!!!!"<<std::endl;
                isDone = true;
            }


            //switch player
            if(currentPlayer == playerOneSymbol && currentPlayerName == playerOneName)
            {
                space();
                std::cout<<playerTwoName<<"'s turn"<<std::endl;
                std::cout<<"-----------------------"<<std::endl;
                currentPlayer = playerTwoSymbol;
                std::string currentPlayerName = playerTwoName;
            }
            else
            {
                space();
                std::cout<<playerOneName<<"'s turn"<<std::endl;
                std::cout<<"-----------------------"<<std::endl;
                currentPlayer = playerOneSymbol;
                std::string currentPlayerName = playerOneName;
            }

        }
    }
}

//clear board
void Game::clearBoard()
{
    for(int row = 0;row<3;row++) {
        for (int col = 0; col < 3; col++)
        {
            board[row][col] = ' ';
        }
    }
}

//print board
void Game::printBoard()
{
    std::cout<<"| 1 2 3|"<<std::endl;
    for(int row = 0;row<3;row++)
    {
        std::cout<<"--------"<<std::endl;
        std::cout<<row+1<<"|"<<board[row][0]<<"|"<<board[row][1]<<"|"<<board[row][2]<<"|"<<std::endl;
    }
    std::cout<<"--------"<<std::endl;
}

//welcome message
void Game::welcomeMessage()
{
    std::cout<<"*********** WELCOME TO TIC TAC TOE ***********"<<std::endl;
    std::cout<<"-----------------------------------------------"<<std::endl;
}

//space function
void Game::space()
{
    std::cout<<std::endl;
}

//get player one name
std::string Game::getPlayerOneName()
{
    std::string namePlayerOne;
    std::cout<<"Enter Player 1 Name: ";
    getline(std::cin,namePlayerOne);

    std::cout<<std::endl;\
    std::cout<<"Hello "<<namePlayerOne<<"!"<<std::endl;

    return namePlayerOne;
}

//get player two name
std::string Game::getPlayerTwoName()
{
    std::string namePlayerTwo;
    std::cout<<"Enter Player 2 Name: ";
    getline(std::cin,namePlayerTwo);

    std::cout<<std::endl;
    std::cout<<"Hello "<<namePlayerTwo<<"!"<<std::endl;

    return namePlayerTwo;
}

//player one symbol
char Game::getPlayerOneSymbol()
{
    char symbol;
    std::cout<<"Player 1 Enter your symbol: ";
    std::cin>>symbol;

    return symbol;
}

//player two symbol
char Game::getPlayerTwoSymbol()
{
    char symbol2;
    std::cout << "Player 1 Enter your symbol: ";
    std::cin >> symbol2;

    return symbol2;
}

//get X Coordinate
int Game::getXCood()
{
    bool isInputBad = true;
    int x;

    while(isInputBad == true)
    {
        std::cout << "Enter X Coordinate: ";
        std::cin >> x;

        if(x>3 || x<0)
        {
            std::cout<<"That was an Bad Input:"<<std::endl;
        }
        else
        {
            isInputBad  = false;
        }
    }

    return x - 1;
}

//get Y Coordinate
int Game::getYCood()
{
    bool isInputBad = true;
    int y;

    while(isInputBad == true)
    {
        std::cout<<"Enter Y Coordinate: ";
        std::cin>>y;

        if(y>3 || y<0)
        {
            std::cout<<"That was an Bad Input:"<<std::endl;
        }
        else
        {
            isInputBad  = false;
        }
    }

    return y - 1;
}

//place marker or check if allowed to
bool Game::placeMarker(int x, int y, char currentPlayer)
{
    if(board[x][y] != ' ')
    {
        return false;
    }

    board[x][y] = currentPlayer;

    return true;
}


//check for victory
bool Game::checkVictory(char currentPlayer)
{
    //check rows
    for(int row = 0;row<3;row++)
    {
        if(board[row][0] == currentPlayer && board[row][0] == board[row][1] && board[row][1] == board[row][2])
        {
            return true;//exit the function some one won
        }
    }

    //check coloums
    for(int col = 0;col<3;col++)
    {
        if(board[0][col] == currentPlayer &&board[0][col] == board[1][col] && board[1][col] == board[2][col])
        {
            return true;//exit the function some one won
        }
    }

    //check the left the diagonal
    if(board[0][0] == currentPlayer && board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return true;//exit the function some one won
    }


    //check the right the diagonal
    if(board[2][0] == currentPlayer && board[2][0] == board[1][1] && board[1][1] == board[0][2])
    {
        return true;//exit the function some one won
    }


    return false;
}
