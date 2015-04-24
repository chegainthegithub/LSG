#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include "UnitStats.h"
#include "gamestatistics.h"
#include "character.h"
#include "enemy.h"
using namespace std;



//problems:const size of field sucks
//how to avoid matrix
//saving positions
//inheiritation?






void gamebody()
{
int candies;
cout << "input amount of candies: "<< endl;
cin >> candies;
Character player(2,1,'@',1,1);
Character:Enemy enemy1(2,1,'!',20,20);
GameStatistics counter;
char field[25][25] = {' '};
field[player.element.x][player.element.y] = player.element.icon;
field[enemy1.element.x][enemy1.element.y] = enemy1.element.icon;
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
    if (candies == counter.element.eaten)
    {
        system("cls");
        cout << "             YOU ARE VICTORIOUS!!!"<<endl;
        cout << "       you ate all the " << candies << " candies in "<<counter.element.movesmade<<" moves!"<<endl;
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
