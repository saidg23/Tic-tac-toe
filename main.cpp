#include <iostream>

using namespace std;

void AI()
{
    //coming soon
}

void printMove(int (&board)[3][3], int y, int x)
{
    if(board[y][x] == 0)
        cout << " ";
    else if(board[y][x] == 1)
        cout << "X";
    else if(board[y][x] == 2)
        cout << "O";
}

void printBoard(int (&board)[3][3])
{
    int yPos = 0;
    int xPos = 0;

    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

    for(int y = 1; y <= 11; ++y)
    {
        cout << "\t\t\t\t\t\t";
        for(int x = 1; x <= 17; ++x)
        {
            if(y%2 != 0)
            {
                if(x < 6 || (x > 6 && x < 12) || x > 12 )
                    cout << " ";
                else
                    cout << "#";
            }

            else if(y%4 != 0)
            {
                if(x < 3 || (x > 3 && x < 6) || (x > 6 && x < 9) || (x > 9 && x < 12) || (x > 12 && x < 15) || x > 15)
                    cout << " ";
                else if(x%6 == 0)
                    cout << "#";
                else
                {
                    printMove(board, yPos, xPos);
                    ++xPos;
                    if(xPos == 3)
                    {
                        xPos = 0;
                        ++yPos;
                    }
                }
            }

            else
                cout << "#";
        }

        cout << '\n';
    }

    cout << "\n\n\n\n\n\n\n\n\n";
}

int checkWin(int board[3][3])
{
    int checkO = 0;
    int checkX = 0;

    for(int posY = 0; posY < 3; ++posY)
    {
        for(int posX = 0; posX < 3; ++posX)
        {
            if(board[posY][posX] == 2)
              ++checkO;

            if(board[posY][posX] == 1)
              ++checkX;
        }
        if(checkO == 3)
            return 2;
        else
            checkO = 0;

        if(checkX == 3)
            return 1;
        else
            checkX = 0;

        for(int posX = 0; posX < 3; ++posX)
        {
            if(board[posX][posY] == 2)
              ++checkO;

            if(board[posX][posY] == 1)
              ++checkX;
        }
        if(checkO == 3)
            return 2;
        else
            checkO = 0;

        if(checkX == 3)
            return 1;
        else
            checkX = 0;

    }

    for(int pos = 0; pos < 3; ++pos)
    {
        if(board[pos][pos] == 2)
            ++checkO;

        if(board[pos][pos] == 1)
            ++checkX;
    }
    if(checkO == 3)
        return 2;
    else
        checkO = 0;

    if(checkX == 3)
        return 1;
    else
        checkX = 0;

    for(int pos = 0; pos < 3; ++pos)
    {
        if(board[pos][2-pos] == 2)
            ++checkO;

        if(board[pos][2-pos] == 1)
            ++checkX;
    }
    if(checkO == 3)
        return 2;
    else
        checkO = 0;

    if(checkX == 3)
        return 1;
    else
        checkX = 0;

    return 0;
}

void placeMove(int (&board)[3][3], bool (&invalidCell)[3][3], int player)
{
    while(true)
    {
        cout << "player " << player << " make a move\n";
        int loc;
        cin >> loc;

        int y;
        if(loc < 3)
            y = 0;
        else if(loc < 6)
            y = 1;
        else if(loc < 9)
            y = 2;

        int x;
        if(loc <3)
            x = loc;
        else if(loc < 6)
            x = loc - 3;
        else if(loc < 9)
            x = loc - 6;

        if(invalidCell[y][x] == false)
            board[y][x] = player;
        else
        {
            cout << "invalid position\n";
            continue;
        }

        invalidCell[y][x] = true;
        break;
    }
}

int main()
{
    int board[3][3]
    {
    {0},
    {0},
    {0}
    };

    bool invalidCell[3][3]
    {
    {false,false,false},
    {false,false,false},
    {false,false,false}
    };

    int turn = 1;
    int player = 1;
    while(true)
    {
        printBoard(board);

        placeMove(board, invalidCell, player);

        int win = checkWin(board);

        if(win == 1)
        {
            printBoard(board);
            cout << "\nplayer 1 has won\n";
            break;
        }

        if(win == 2)
        {
            printBoard(board);
            cout << "\nplayer 2 has won\n";
            break;
        }

        if(turn == 9)
        {
            printBoard(board);
            cout << "\nTie\n";
            break;
        }

        if(player == 1)
            player = 2;
        else
            player = 1;
        ++turn;
    }

    return 0;
}
