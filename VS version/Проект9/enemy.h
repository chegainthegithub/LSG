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
  
  
	int DistanceCalculation(int x1,int y1)
  {
	  return distX(x1)^2 + distY(y1)^2;
  }
	int distX(int x1)
	{
		return(element.x - x1);
	}
	int distY(int y1)
	{
		return(element.y - y1);
	}

	virtual void TurnMake()
	{

	}

	virtual void Attack()
	{

	}
	virtual void Move(int x1,int y1,char field[25][25])
	{
		int dY = distY(y1);
		int dX = distX(x1);
		int distance = DistanceCalculation(dX,dY);
		if (distance == 1)
		{
			Attack();
			return;
		}
		if (dX>0)
			left(field);
		else
			if (dX < 0)
				right(field);
			else
				if (dY>0)
					down(field);
				else
					if (dY<0)
						up(field);
					else
					{
						Attack();
						return;
					}

	}


};
#endif // ENEMY_H
