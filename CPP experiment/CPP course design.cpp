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
#include <fstream>

#define M 22
#define N 62 //length, width
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

using namespace std;

class player;

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
    void change_t(int);
    void change_dir(int);
    void print_scoreboard(player);
    void change_die();
    void set_difficulty(int);
    int get_difficulty();
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
    string getname();
    string getpasswd();
};

class player: public user
{
protected:
    int score[50];
    int life;
public:
    player *next;

    player(string, string, int, int life = 3);
    void life_operate(int);
    int get_life();
    void get_score(int[]);
    void score_sort();
    void input_score(int[]);

    friend void game::record_score(player&);
};

class admin: public player
{
public:


};



//<user part>

user::user(string name1, string passwd1):name(name1), passwd(passwd1)
{}

string user::getname()
{
    return name;
}

string user::getpasswd()
{
    return passwd;
}
//<user part>





//<player part>

player::player(string name1, string passwd1, int score1, int life1):user(name1, passwd1)
{
    life = life1;
    for(int i = 0; i < 50; i++)
    {
        score[i] = -1;
    }
}

void player::score_sort()
{
    int length = 0;
    int temp = 0, t;
    while (score[length++] != -1);
    length--;
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (score[temp] < score[j]) temp = j;
        }
        t = score[i];
        score[i] = score[temp];
        score[temp] = t;
        temp = i + 1;
    }
}

void player::life_operate(int h)
{
    life = life + h;
}

int player::get_life()
{
    return life;
}

void player::get_score(int a[])
{
    
    for (int i = 0; i < 50; i++)
    {
        a[i] = score[i];
    }
}

void player::input_score(int a[])
{
    for (int i = 0; i < 50; i++)
    {
        score[i] = a[i];
    }
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
    char title[5][51] =
    {   0,0,0,1,1,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,
        0,0,1,0,0,0,1,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,
        0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,1,0,0,0,1,1,1,1,1,1,1,0,0,0,1,0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,1,1,1,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0};
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 51; j++)
        {
            if(title[i][j] == 0) cout <<" ";
            if(title[i][j] == 1) cout <<"*";
        }
        cout << endl;
    }
    Sleep(1000);
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
    system("cls");
    int temp = 9;
    gotoxy(5, 20);
    cout << "Difficulty(1 ~ 9)  < ";
    cout << temp << " >";
    do
    {
        if (kbhit())
        {
            char d = getch();
            if (d == 'a' || d == 'd')
            {
                gotoxy(5, 41);
                if (d == 'a')
                {
                    if (temp > 1) temp--;
                    else temp = 9;
                }
                if (d == 'd')
                {
                    if (temp < 9) temp++;
                    else temp = 1;
                }
                cout << temp;
                continue;
            }
            if (d == '\r')
            {
                difficulty = temp;
                break;
            }
        }
        Sleep(100);
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

    memset(item, 0, sizeof(item));

}

void game::Food()
{
    int i;
    food_x = 1 + rand() % (M - 2);
    food_y = 1 + rand() % (N - 2);

	for(i = 0; i < bodynode; i++)
	{
    	if(snake[i][0] == food_x && snake[i][1] == food_y) // avoid the snake
		{
            food_x = 1 + rand() % (M - 2);
            food_y = 1 + rand() % (N - 2);
		}
        if(wall[snake[i][0]][snake[i][1]] == 1) // avoid the wall
		{
            food_x = 1 + rand() % (M - 2);
            food_y = 1 + rand() % (N - 2);
		}
	}
    gotoxy(food_x, food_y);
    cout << '$';
}

void game::Item()
{
    int i;
    int randomnum1, randomnum2, sign = 0;
    randomnum1 = rand() % 100;
    for (i = 0; i < 7; i++)
    {
        itemlife[i]--;
        if (itemlife[i] == 0)
        {
            gotoxy(item[i][0], item[i][1]);
            cout << " ";
            item[i][0] = 0;
            item[i][1] = 0;
        }
    }

    for (int j = 0; j < 7; j++)
    {
        if (randomnum1 < 95) break;//decide wheather creat item
        if (item[j][0] != 0 && item[j][1] != 0) continue; //wheather the place has item
        item[j][0] = 1 + rand() % (M-2);
        item[j][1] = 1 + rand() % (N-2);
        itemlife[j] = 30;
        for(i = 0; i < bodynode; i++)
    	{
            if((snake[i][0] == item[j][0] && snake[i][1] == item[j][1]) || (item[j][0] == food_x && item[j][1] == food_y))
        	{
                item[j][0] = 1 + rand() % (M-2);
                item[j][1] = 1 + rand() % (N-2);
        	}
    	}
        if (randomnum1 == 96)
        {
            itemname[j] = 'H';
        }
        else
        {
            itemname[j] = 'B';
        }
        gotoxy(item[j][0], item[j][1]);
        cout << itemname[j];

        break;
    }
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
            else cout << '|';     // \x2580   \x2588
        }
        cout << endl;
    }
}

int game::Judgedie(player &t)
{
    if (wall[snake[0][0]][snake[0][1]] == 1)
    {
        t.life_operate(-1);
        die = 1;
    }
    for(int i = 1; i < bodynode; i++)
    {
        if(snake[i][0] == snake[0][0] && snake[i][1] == snake[0][1])
        {
            t.life_operate(-1);
            die=1;
        }
    }
}

void game::Move(player &t)
{
    gotoxy(snake[bodynode - 1][0], snake[bodynode - 1][1]);
    cout << " ";      //cut the tail
    if (bonus > 0) bonus--;       //dec bonus time
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
            if (itemname[i] == 'B') bonus += 50;
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
    int i = 0;
    while (p.score[i] > -1)
    {
        i++;
    }
    p.score[i] = score;
}

void game::print_scoreboard(player t)
{
    gotoxy(M + 1, 5);
    cout << "                                                            ";
    gotoxy(M + 1, 5);
    cout << "SCORE:  " << score;
    cout << "         ";
    cout << "life:  " << t.get_life();
    cout << "         ";
    cout << "Bonus time:   " << bonus;
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

void game::set_difficulty(int t)
{
    difficulty = t;
}

int game::get_difficulty()
{
    return difficulty;
}

//<game part>


class linklist
{
private:
    player *start;
public:

    void linkini(string, string);
    void nodeinsert(string, string);
    void save();
    void read();
    player* search(string, string);
};

void linklist::linkini(string name1, string passwd1)
{
    start = new player(name1, passwd1, 0);
}

void linklist::nodeinsert(string name1, string passwd1) //add new player
{
    player *p;
    p = start->next;
    start->next = new player(name1, passwd1, 0);
    start->next->next = p;
}

void linklist::read()
{
    ifstream fin("userdata.txt", ios::in);
    char name1[30];
    char passwd1[30];
    char final[2] = "0";
    int score1[50], sign = 1;
    player *p1, *p2;

    fin >> name1 >>passwd1;
    for (int i = 0; i < 50; i++)
    {
        fin >> score1[i];
    }
    p1 = new player(name1, passwd1, 0);
    p1->input_score(score1);
    start->next = p1;
    while(1)
    {
        fin >> name1 >> passwd1;
        for (int i = 0; i < 50; i++)
        {
            fin >> score1[i];
            //fin >> " ";
        }
        if (name1[0] == '0' && name1[1] == '\0') break;
        p2 = new player(name1, passwd1, 0);
        p2->input_score(score1);
        p1->next = p2;
        p1 = p2;
    }
    p1->next = NULL;
    fin.close();
}

void linklist::save()
{
    player *p = start;
    ofstream fout("userdata.txt", ios::out);
    int score1[50];
    p = p->next;
    while(p)
    {
        fout << p->getname()<< "\n" << p->getpasswd() << "\n";
        p->get_score(score1);
        for (int i = 0; i < 50; i++)
        {
            fout << score1[i] << " ";
        }
        fout << '\n';
        p = p->next;
    }
    fout << "0\n" << "0\n";
    for (int i = 0; i < 50; i++)
    {
        fout << -1;
    }
    fout.close();
}

player* linklist::search(string u, string passwd1)
{
    int judge = 1;
    player *p = start;
    while (p)
    {
        if (p->getname() == u)
        {
            if (p->getpasswd() == passwd1) return p;
            else
            {
                cout << "passwd error";
                return NULL;
            }
        }
        p = p->next;
    }
    return NULL;
}

player* login(linklist &l)
{
    char name1[20];
    string passwd1;
    char pass[50];
    char c;
    string n;
    player *p;
    int i = 0;
    l.linkini("default", "123456");
    l.read();
    cout << "Register?(y/n)";
	cin >> c;
	if (c == 'y')
	{
		cout << "Enter username: ";
		cin >> n;
		cout << "Enter password: ";
		cin >> passwd1;
		l.nodeinsert(n, passwd1);
	}
	system("cls");
A2: cout << "USERNAME: ";
    cin >> name1;
    cout << "PASSWD: ";
    cin >> pass;
    passwd1 = pass;
    n = name1;
    p = l.search(n, passwd1);
    if (p == NULL)
    {
        goto A2;
    }
    return p;
}



int main()
{
    player *p;

    linklist list;
    p = login(list);

    //na = p->getname();
    //pa = p->getpasswd();
    system("cls");

    game maingame;
    int i = 0;

    maingame.Initial();
    system("cls");
A1: maingame.Initial_data();
    maingame.Wall1();
    maingame.Drawmap();
    maingame.Food();
    do
    {
        maingame.Drawsnake();
        maingame.print_scoreboard(*p);
        maingame.Judgedie(*p);
        if (maingame.relife(*p))
        {
            goto A1;
        }
        Sleep(maingame.get_difficulty() * 50);//hlat after draw, ohterwise move would cut the tail
        maingame.Control();
        maingame.Move(*p);
        maingame.Item();

    } while(maingame.get_judgegame());
    system("cls");
    maingame.gotoxy(M/2, N/2);
    cout << "GAME OVER" << endl;
    maingame.record_score(*p);
    Sleep(2000);


//Personal score board
    system("cls");
    p->score_sort();
    int score[50];
    memset(score, -1, sizeof(score));
    p->get_score(score);
    cout << "*********YOUR SCORE BOARD*********" << endl;
    cout << "RANK               SCORE" << endl;
    while (score[i] > -1)
    {
        cout << " " << i + 1 << "                    " << score[i] << endl;
        i++;
    }
    
    list.save();

    return 0;
}
