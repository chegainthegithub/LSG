#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;


struct statistics
{
    int eaten = 0;
    int movesmade = 0;

    void UpdateStats(int local)
    {
        if (local)
            eaten++;
        movesmade++;
    }
    void show()
    {
        cout << "eaten == " << eaten<<endl;
        cout << "moves made == " << movesmade << endl;
    }
};

struct character
{
    char icon = '@';
    int x = 1;
    int y = 1;
    int local = 0;
    int down(char field[25][25])
    {
        if (field[x+1][y]=='*')
            local = 1;
        if (field[x+1][y] != '#')
        {
        field[x+1][y] = '@';
        field[x][y] = ' ';
        x++;
        }
        return local;
    }
    int up(char field[25][25])
    {
        if (field[x-1][y]=='*')
            local = 1;
        if (field[x-1][y]!='#')
        {
        field[x-1][y] = '@';
        field[x][y] = ' ';
        x--;
        }
        return local;
    }
    int left(char field[25][25])
    {
        if (field[x][y-1]=='*')
            local = 1;
        if (field[x][y-1]!='#')
        {
        field[x][y-1] = '@';
        field[x][y] = ' ';
        y--;
        }
        return local;
    }
    int right(char field[25][25])
    {
        if (field[x][y+1]=='*')
            local = 1;
        if (field[x][y+1]!='#')
        {
        field[x][y+1] = '@';
        field[x][y] = ' ';
        y++;
        }
        return local;
    }
    int waseaten()
    {
        int local2 = local;
        local = 0;
        return local2;
    }
};
struct ghost
{

};


void gamebody()
{
int candies;
cout << "input amount of candies: "<< endl;
cin >> candies;
character player;
statistics counter;
char field[25][25] = {' '};
field[1][1] = '@';
for(int i = 0;i<candies;i++)
{
   int x = rand() % 24;
   int y = rand() % 24;
   if (x==1||y==1)
   {
       i--;
       continue;
   }
   field[x][y] = '*';
}
for (int i = 0;i<25;i++)
{
    field[0][i] = '#';
    field[24][i] = '#';
    field[i][0] = '#';
    field[i][24] = '#';
}
for (int i =0;i<25;i++)
{
    for (int j = 0;j<25;j++)
    {
        cout << field[i][j];
    }
    cout<<endl;
}
while (true)
{
    int move;
    cin >> move;
    if (move == 8)
        player.up(field);
    if (move == 2)
        player.down(field);
    if (move == 4)
        player.left(field);
    if (move == 6)
        player.right(field);
    system("cls");
    for (int i =0;i<25;i++)
    {
        for (int j = 0;j<25;j++)
        {
            cout << field[i][j];
        }
        cout<<endl;
    }
    counter.UpdateStats(player.waseaten());
    counter.show();
    if (candies == counter.eaten)
    {
        system("cls");
        cout << "             YOU ARE VICTORIOUS!!!"<<endl;
        cout << "       you ate all the " << candies << " candies in "<<counter.movesmade<<" moves!"<<endl;
        cout << "             wanna another game? "<<endl;
        cout << "                   ";
        string answer;
        cin >> answer;
        cout << endl;
        if (answer[0] == 'y'||answer[0] == 'Y'||answer[0] == 'Д'||answer[0] == 'д')
            gamebody();
        else
        {
            cout << "              see you later!"<<endl;
            return;
        }
    }
}
}

int main()
{
    gamebody();
    return 0;
}
