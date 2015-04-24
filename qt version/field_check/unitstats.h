#ifndef UNITSTATS_H
#define UNITSTATS_H
class UnitStats
{
    struct Statistics
    {
        int health = 1;
        int damage = 0;
    };
public:
    Statistics Stats;
    UnitStats(int hp,int dmg)
    {
        Stats.damage = dmg;
        Stats.health = hp;
    }
    void IncreaseDamage(int bonus)
    {
        Stats.damage+=bonus;
    }
    void IncreaseHealth(int bonus)
    {
        Stats.health+=bonus;
    }
};

#endif // UNITSTATS_H

