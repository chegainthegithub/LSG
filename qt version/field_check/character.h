#ifndef CHARACTER_H
#define CHARACTER_H
#include "unitstats.h"
class Character
{
public:
    struct character
    {
        char icon ;
        int x ;
        int y ;
        int local = 0;
    };
    character element;
    Character(int dmg,int hp,char icon,int x,int y)
    {
        UnitStats characteristics(hp,dmg);
        element.icon = icon;
        element.x = x;
        element.y = y;
    }
        int down(char field[25][25])
        {
            if (field[element.x+1][element.y]=='*')
                element.local = 1;
            if (field[element.x+1][element.y] != '#')
            {
            field[element.x+1][element.y] = element.icon;
            field[element.x][element.y] = ' ';
            element.x++;
            }
            return element.local;
        }
        int up(char field[25][25])
        {
            if (field[element.x-1][element.y]=='*')
                element.local = 1;
            if (field[element.x-1][element.y]!='#')
            {
            field[element.x-1][element.y] = element.icon;
            field[element.x][element.y] = ' ';
            element.x--;
            }
            return element.local;
        }
        int left(char field[25][25])
        {
            if (field[element.x][element.y-1]=='*')
                element.local = 1;
            if (field[element.x][element.y-1]!='#')
            {
            field[element.x][element.y-1] = element.icon;
            field[element.x][element.y] = ' ';
            element.y--;
            }
            return element.local;
        }
        int right(char field[25][25])
        {
            if (field[element.x][element.y+1]=='*')
                element.local = 1;
            if (field[element.x][element.y+1]!='#')
            {
            field[element.x][element.y+1] = element.icon;
            field[element.x][element.y] = ' ';
            element.y++;
            }
            return element.local;
        }
        int waseaten()
        {
            int local2 = element.local;
            element.local = 0;
            return local2;
        }
};

#endif // CHARACTER_H

