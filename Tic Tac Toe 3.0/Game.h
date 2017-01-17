

#ifndef TIC_TAC_TOE_3_0_GAME_H
#define TIC_TAC_TOE_3_0_GAME_H


class Game
{

public:
    Game();
    void playGame();
private:
    void welcomeMessage();
    void space();
    bool checkVictory(char currentPlayer);
    std::string getPlayerOneName();
    std::string getPlayerTwoName();
    char getPlayerOneSymbol();
    char getPlayerTwoSymbol();
    int getXCood();
    int getYCood();
    bool placeMarker(int x,int y,char currentPlayer);
    void clearBoard();
    void printBoard();
    char board[3][3];


};


#endif
