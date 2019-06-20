/*
功能：
1.用户功能：包括管理员和玩家
管理员可以对玩家信息进行修改，查看所有人分数，
玩家可以修改自己的密码，查看自己所有分数和高分榜
2.游戏功能：
基本贪吃蛇 + 调节速度，预设难度选择，（随机生成墙）

*/
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <vector>

#define M 22
#define N 62 //length, width
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

using namespace std;

class player;

typedef struct lln
{
    int num;
    struct lln *next;
} linknode;

class linklist
{
private:
    linknode *start;
public:
    linklist(linknode *);

    linkini();
    void nodeinsert();
    void nodesort();
    void save();
};



class game
{
private:
    int t;
    int score;
    int wall[M][N];
    int snake[M*N][2];
    int bodynode;
    int direction;
    int food_x;
    int food_y;
    int difficulty;
    int judgegame;
    int die;
    int item[7][2];
    char itemname[7];
    int itemlife[7];
    int bonus;

public:
    game(int t = 200, int score = 0, int bodynode = 3, int direction = RIGHT, int difficulty = 1, int judgegame = 1, int die = 0, int bonus = 0);
    void gotoxy(int, int);
    void Initial();
    void Wall1();
    void Initial_data();
    void Food();
    void Item();
    void Drawmap();
    void Move(player&);
    void Drawsnake();
    void Control();
    int Judgedie(player&);
    void Scoresort(player);
    void Rank(linklist);
    void change_t(int);
    void change_dir(int);
    void print_scoreboard(player);
    void change_die();
    int get_judgegame();
    int relife(player&); //0 means not relife, 1 means relife


    void record_score(player&);
};

class user
{
protected:
    string name;
    string passwd;
public:
    user(string, string);

};

class player: public user
{
protected:
    vector<int> score;
    int life;
public:
    player(string, string, int, int life = 3);
    void life_operate(int);
    int get_life();
    vector<int> get_score();


    friend void game::record_score(player&);
};

class admin: public player
{
public:


};

//<user part>

user::user(string name1, string passwd1):name(name1), passwd(passwd1)
{}

//<user part>


//<player part>
player::player(string name1, string passwd1, int score1, int life1):user(name1, passwd1)
{
    life = life1;
    score.push_back(score1);
}

void player::life_operate(int h)
{
    life = life + h;
}

int player::get_life()
{
    return life;
}

vector<int> player::get_score()
{
    return score;
}
//<player part>


//<game part>
game::game(int t1, int score1, int bodynode1, int direction1, int difficulty1, int judgegame1, int die1, int bonus1)
{
    t = t1;
    score = score1;
    bodynode = bodynode1;
    direction = direction1;
    difficulty = difficulty1;
    judgegame = judgegame1;
    die = die1;
    bonus = bonus1;
}

void game::gotoxy(int i, int j)
{
    COORD position = {j, i};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
}

void game::Initial()
{
    char c;
    int function = 1;
    int i = 5, j = 18;    //i the row, j the column
    srand(time(NULL));
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
    gotoxy(5, 20);
	cout << "1.Start game";
    gotoxy(6, 20);
    cout << "2.Exit";
    gotoxy(5, 18);
    cout << ">>";
	do
    {
        Sleep(100);
        if (kbhit())
        {
            c = getch();
            if (c == 'w' || c == 'W' || c == 's' || c == 'S')
            {
                if (i == 5)
                {
                    gotoxy(i, j);
                    cout << "  ";
                    gotoxy(++i, j);
                    cout << ">>";
                    function = 2;
                    continue;
                }
                else
                {
                    gotoxy(i, j);
                    cout << "  ";
                    gotoxy(--i, j);
                    cout << ">>";
                    function = 1;
                    continue;
                }
            }

            if (c == '\r')
            {
                if (function == 1) break;
                else exit(0);
            }
        }
    } while(1);
}

void game::Wall1()
{
    int i, j;
    for(i = 0; i < M; i++)
    {
        for(j = 0; j < N; j++)
		{
			if(i == 0 || i == M-1 || j == 0 || j == N-1)
			wall[i][j] = 1;
		}
	}
}

void game::Initial_data()
{
    bodynode = 3;
    snake[0][0] = 16;
    snake[0][1] = 11;
    snake[1][0] = 16;
    snake[1][1] = 10;
	snake[2][0] = 16;
	snake[2][1] = 9;
    direction = RIGHT;


}

void game::Food()
{
    int i;
    food_x = 1 + rand() % (M - 2);
    food_y = 1 + rand() % (N - 2);

	for(i = 0; i < bodynode; i++)
	{
    	if(snake[i][0] == food_x && snake[i][1] == food_y)
		{
            food_x = 1 + rand() % (M-2);
            food_y = 1 + rand() % (N-2);
		}
	}
    gotoxy(food_x, food_y);
    cout << '$';
}

void game::Item()
{
    int i;
    int randomnum;
    randomnum = rand() % 10;

	for(i = 0; i < bodynode; i++)
	{
        for (int j = 0; j < 7; j++)
        {
            if(snake[i][0] == item[j][0] && snake[i][1] == item[j][1] && randomnum > 6)
    		{
                food_x = 1 + rand() % (M-2);
                food_y = 1 + rand() % (N-2);
    		}
        }
	}
    gotoxy(food_x, food_y);
    cout << '$';
}

void game::Drawmap()
{
    gotoxy(0, 0);
    int i, j;
    for(i = 0; i < M; i++)
    {
        for(j = 0; j < N; j++)
        {
            if(wall[i][j] == 0) cout << " ";
            else cout << '|';
        }
        cout << endl;
    }
}

int game::Judgedie(player &t)//unfinished
{
    if (wall[snake[0][0]][snake[0][1]] == 1)
    {
        t.life_operate(-1);
        die = 1;
    }
}

void game::Move(player &t)
{
    gotoxy(snake[bodynode - 1][0], snake[bodynode - 1][1]);
    cout << " ";      //cut the tail
    if (bonus > 0) bonus--;  //dec bonus time
    if(snake[0][0] == food_x && snake[0][1] == food_y)//if eat food
    {
        if (bonus == 0) score++;
        else score += 5; //score calculate

        bodynode++;
        Food();
    }
    for (int i = 0; i < 7; i++) //if eat item
    {
        if(snake[0][0] == item[i][0] && snake[0][1] == item[i][1])
        {
            if (itemname[i] == 'H') t.life_operate(1);
            if (itemname[i] == 'B') bonus = 15;
            item[i][0] = 0;
            item[i][1] = 0;
        }
    }
    //move part
    for (int i = bodynode; i > 0; --i)//move body
    {
        snake[i][0] = snake[i - 1][0];
        snake[i][1] = snake[i - 1][1];
    }
    switch (direction)//move head
    {
        case UP:
        {
            snake[0][0]--;
            break;
        }
        case DOWN:
        {
            snake[0][0]++;
            break;
        }
        case RIGHT:
        {
            snake[0][1]++;
            break;
        }
        case LEFT:
        {
            snake[0][1]--;
            break;
        }
    }
}

void game::Drawsnake()
{
    gotoxy(snake[0][0], snake[0][1]);
    cout << '@';
    for (int i = 1; i < bodynode; ++i)
    {
        gotoxy(snake[i][0], snake[i][1]);
        cout << '*';
    }
}

void game::Control()
{
    char c;
    if (kbhit())
    {
        c = getch();
        switch (c)
        {
            case 'w':
            case 'W':
            {
                if (direction == DOWN) break;
                direction = UP;
                break;
            }
            case 's':
            case 'S':
            {
                if (direction == UP) break;
                direction = DOWN;
                break;
            }
            case 'a':
            case 'A':
            {
                if (direction == RIGHT) break;
                direction = LEFT;
                break;
            }
            case 'd':
            case 'D':
            {
                if (direction == LEFT) break;
                direction = RIGHT;
                break;
            }
        }
    }
}

void game::record_score(player &p)
{
    p.score.push_back(score);
}

void game::print_scoreboard(player t)
{
    gotoxy(M + 1, 5);
    cout << "SCORE:  " << score;
    cout << "         ";
    cout << "life  " << t.get_life();
}

void game::change_die()
{
    die = -die;
}

int game::get_judgegame()
{
    return judgegame;
}

int game::relife(player &t)
{
    if (t.get_life() == 0)
    {
        judgegame = 0;
        return 0;
    }
    if (t.get_life() != 0 && die == 1)
    {
        die = 0;
        system("cls");
        return 1; // able to relife
    }
}



//<game part>



int main()
{
    player p("a", "a", 0);
    game maingame;

    maingame.Initial();
    system("cls");
A1: maingame.Initial_data();
    maingame.Wall1();
    maingame.Drawmap();
    maingame.Food();
    do
    {
        maingame.Drawsnake();
        maingame.print_scoreboard(p);
        maingame.Judgedie(p);
        if (maingame.relife(p))
        {
            goto A1;
        }
        Sleep(200);//hlat after draw, ohterwise move would cut the tail
        maingame.Control();
        maingame.Move(p);

    } while(maingame.get_judgegame());
    system("cls");
    maingame.gotoxy(M/2, N/2);
    cout << "GAME OVER" << endl
    ;


    return 0;
}
