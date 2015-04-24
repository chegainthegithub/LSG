#ifndef ENEMY_H
#define ENEMY_H
#include "character.h"
#include <iostream>
class Enemy:public Character
{
public:
  Enemy(int hp,int dmg,char icon,int x,int y):Character(dmg,hp,icon,x,y)
  {
  }
};

#endif // ENEMY_H

