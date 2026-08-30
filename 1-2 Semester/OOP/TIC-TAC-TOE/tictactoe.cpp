#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

class Player  
{
    char mark; 
public:
    Player(char m) { mark = m; }
    virtual int getMove() = 0;
    char getMark() const { return mark; }
};

class Board         
{                   
    char arr[9];    
    bool setMove(int index, char mark)                                                          
    {                                                                                           
        char m = arr[index - 1];               
        cout << "Index:" << index << '\t';
        if (m >= '1' && m <= '9') 
        {
            arr[index - 1] = mark; 
            cout << "Mark: " << arr[index - 1] << '\n';
            return true;  
        }
        return false;
    }
    friend class Game;

public:
    void init() 
    {            
                
        for (int i = 0; i < 9; i++)
            arr[i] = i + 49;
    }
    void getBoard(char b[])
    {
        for (int i = 0; i < 9; i++)
            b[i] = arr[i];
    }
    void draw()
    {
        cout << endl;
        cout << " ___ ___ ___ " << endl;
        cout << "|   |   |   |" << endl;
        cout << "| " << arr[0] << " | " << arr[1] << " | " << arr[2] << " |" << endl;
        cout << "|___|___|___|" << endl;
        cout << "|   |   |   |" << endl;
        cout << "| " << arr[3] << " | " << arr[4] << " | " << arr[5] << " |" << endl;
        cout << "|___|___|___|" << endl;
        cout << "|   |   |   |" << endl;
        cout << "| " << arr[6] << " | " << arr[7] << " | " << arr[8] << " |" << endl;
        cout << "|___|___|___|" << endl;
    }
};

class HPlayer : public Player
{
public:
    HPlayer(char mark) : Player(mark) {}
    int getMove()  
    {
        int index;
        cout << "Enter box number to put " << getMark() << " : ";
        cin >> index;
        cout << "Human selects cell : " << index << endl;
        return index;
    }
};

class NonsenseComputerPlayer : public Player
{
public:
    NonsenseComputerPlayer(char mark) : Player(mark) {}
    int getMove()
    {
        int random = 1 + rand() % 9;
        cout << "Nonsense Computer selects cell : " << random << endl;
        return random;
    }
};

class SensibleComputerPlayer : public Player
{
protected:
    Board *b;

    char MyMark = getMark();
    char OppMark = (MyMark == 'X') ? 'O' : 'X';

    int lines[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, 
        {0, 3, 6}, {1, 4, 7},{2, 5, 8}, 
        {0, 4, 8},{2, 4, 6}}; 

    int WinBlock(char arr[9])
    {
        for (int i = 0; i < 8; i++)
        {
            int a = lines[i][0], b = lines[i][1], c = lines[i][2];
            if (arr[a] == MyMark && arr[b] == MyMark && arr[c] != 'X' && arr[c] != 'O')
                return c + 1;
            if (arr[a] == MyMark && arr[c] == MyMark && arr[b] != 'X' && arr[b] != 'O')
                return b + 1;
            if (arr[b] == MyMark && arr[c] == MyMark && arr[a] != 'X' && arr[a] != 'O')
                return a + 1;
        }
        return -1;
    }

        int DefBlock(char arr[9])
    {
        for (int i = 0; i < 8; i++)
        {
            int a = lines[i][0], b = lines[i][1], c = lines[i][2];
            if (arr[a] == OppMark && arr[b] == OppMark && arr[c] != 'X' && arr[c] != 'O')
                return c + 1;
            if (arr[a] == OppMark && arr[c] == OppMark && arr[b] != 'X' && arr[b] != 'O')
                return b + 1;
            if (arr[b] == OppMark && arr[c] == OppMark && arr[a] != 'X' && arr[a] != 'O')
                return a + 1;
        }
        return -1;
    }

    int BestMove(char arr[9])                         
    {
        for (int i = 0; i < 8; i++)                   
        {
            int MyCount = 0, EmptYCount = 0, EmptyIndex = -1; 
            for (int j = 0; j < 3; j++)               
            {
                int index = lines[i][j];              
                if (arr[index] == getMark())          
                    MyCount++;                       
                else if (arr[index] >= '1' && arr[index] <= '9') 
                {
                    EmptYCount++;                     
                    EmptyIndex = index;               
                }
            }
            if (MyCount == 1 && EmptYCount == 2)     
                return EmptyIndex + 1;                
        }
        return -1;                                 
    }

    int EmptyCell(char arr[9])
    {
        for (int i = 0; i < 9; i++)
        {
            if (arr[i] != 'X' && arr[i] != 'O')
            {
                return i + 1;
            }
        }
        return -1;
    }

public:

    SensibleComputerPlayer(char mark, Board *B) : Player(mark), b(B) {};
    int getMove()
    {
        char arr[9];
        b->getBoard(arr);

        int WinMove = WinBlock(arr);
        if (WinMove != -1)
        {
            cout << "Sensible Computer selects cell : " << WinMove << endl;
            return WinMove;
        }

        int BlockMove = DefBlock(arr);
        if (BlockMove != -1)
        {
            cout << "Sensible Computer selects cell : " << BlockMove << endl;
            return BlockMove;
        }

        int bestmove = BestMove(arr);
        if (bestmove != -1)
        {
            cout << "Sensible Computer selects cell : " << bestmove << endl;
            return bestmove;
        }

        int emptycell = EmptyCell(arr);
        if (emptycell != -1)
        {
            cout << "Sensible Computer selects cell : " << emptycell << endl;
            return emptycell;
        }
    }
};

class Game
{
    Board b;
    Player *p1, *p2;

public:
    Game()
    {
        init();
    }
    void init()
    {
        b.init();
    }
    bool checkRow(char b[], int r, char mark)
    {
        for (int i = r; i < r + 3; i++)
            if (b[i] != mark)
                return false;
        return true;
    }
    bool checkColumn(char b[], int r, char mark)
    {
        for (int i = r; i < 9; i += 3)
            if (b[i] != mark)
                return false;
        return true;
    }
    bool checkD1(char b[], char mark)
    {
        return (b[0] == mark && b[4] == mark && b[8] == mark);
    }
    bool checkD2(char b[], char mark)
    {
        return (b[2] == mark && b[4] == mark && b[6] == mark);
    }
    bool checkWin(char b[], int pos, char mark)
    {
        if (checkRow(b, pos / 3 * 3, mark))
            return true;
        int index;
        if (pos == 0 || pos == 3 || pos == 6)
            index = 0;
        else if (pos == 1 || pos == 4 || pos == 7)
            index = 1;
        else
            index = 2;
        if (checkColumn(b, index, mark))
            return true;
        if ((pos == 0 || pos == 4 || pos == 8) && checkD1(b, mark))
            return true;
        return checkD2(b, mark);
    }

    void toss(Player*& p1, Player*& p2) 
    {
        int toss_result = rand() % 2;
        cout << "\nTossing the coin...\n";
        if (toss_result == 0) {
           cout << "Player 1 will start first.\n";
        } else {
           cout << "Player 2 will start first. Swapping players...\n";
           swap(p1, p2);
        }
    }

        void GameType(Player *&p1, Player *&p2)
    {
        int choice;
        char mark1, mark2;
        cout << "Press 1 to select Human vs. Human." << endl
             << "Press 2 to select Human vs. Nonsense Computer." << endl
             << "Press 3 to select Human vs. Sensible Computer." << endl
             << "Press 4 to selsect Nonsense vs. Sensible Computer." << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        cout << "Enter mark for Player 1: ";
        cin >> mark1;

        mark1 = toupper(mark1);
        mark2 = (mark1 == 'X') ? 'O' : 'X';
        if (choice == 1)
        {
            p1 = new HPlayer(mark1);
            p2 = new HPlayer(mark2);
        }
        else if (choice == 2)
        {
            p1 = new HPlayer(mark1);
            p2 = new NonsenseComputerPlayer(mark2);
            toss(p1,p2);
        }
        else if (choice == 3)
        {
            p1 = new HPlayer(mark1);
            p2 = new SensibleComputerPlayer(mark2, &b);
            toss(p1,p2);
        }
        else if (choice == 4)
        {
            p1 = new NonsenseComputerPlayer(mark1);
            p2 = new SensibleComputerPlayer(mark2, &b);
            toss(p1,p2);
        }
    }

        void runGame()
    {
        int count = 0, pos, turn = 1;
        char a[9];
        GameType(p1, p2);
        char mark = p1->getMark();
        b.draw();
        Player *currentPlayer = p1;
        while (count < 9)
        {
            do
            {
                pos = currentPlayer->getMove();
                mark = currentPlayer->getMark();
            } while (!b.setMove(pos, mark));
            if (turn == 1)
            {
                turn = 2;
                currentPlayer = p2;
            }
            else
            {
                turn = 1;
                currentPlayer = p1;
            }
            b.draw();
            b.getBoard(a);
            if (checkWin(a, pos - 1, mark))
                break;
            count++;
        }
        if (count == 9)
            cout << "Draw\n";
        else if (mark == p1->getMark())
            cout << "Player 1 Won\n";
        else
            cout << "Player 2 Won\n";
        string s;
        cout << endl
             << "Want to Play Again (yes or no)?" << endl;
        cin >> s;

        if (s == "yes")
        {
            b.init();
            runGame();
        }
        else
        {
            cout << "Game Ended" << endl;
        }
    }
};

int main()
{
    srand(time(0));
    Game g;
    g.runGame();
}
