#include <iostream>
using namespace std;
class basic_monster //基础怪物类
{
public:
    basic_monster(double life = 0, double attac = 0) : hp(life), attack_ability(attac) {}
    virtual void Attack(basic_monster *enemy)
    {
        enemy->hurted(this->attack_ability);
        if (enemy->hp <= 0)
        {
            return;
        }
        enemy->FightBack(*this);
    }
    virtual void FightBack(basic_monster &enemy)
    {
        enemy.hurted((this->attack_ability) / 2);
    }
    virtual void hurted(double decrease)
    {
        this->hp = this->hp - decrease;
    }
    virtual bool IsDead()
    {
        if (hp <= 0)
        {
            return true;
        }
        return false;
    }

protected:
    double attack_ability; //攻击力
    double hp;             //生命值
};
class fire_dragon : public basic_monster
{
public:
    fire_dragon(double life = 0, double attac = 0) : basic_monster(life, attac) {}
    void Attack(basic_monster *enemy)
    {
        cout << "Dragon fire" << endl;
        basic_monster::Attack(enemy);
    }
    void FightBack(basic_monster &enemy)
    {
        cout << "Dragon fire back!" << endl;
        basic_monster::FightBack(enemy);
    }
    void hurted(double decrease)
    {
        cout << "Dragon hurt " << decrease << endl;
        basic_monster::hurted(decrease);
    }
    bool IsDead()
    {
        if (basic_monster::IsDead())
        {
            cout << "Dragon was killed" << endl;
            return true;
        }
        return false;
    }
};
class Cwolf : public basic_monster
{
public:
    Cwolf(double life = 0, double attac = 0) : basic_monster(life, attac) {}
    void Attack(basic_monster *enemy)
    {
        cout << "CWolf palm" << endl;
        basic_monster::Attack(enemy);
    }
    void FightBack(basic_monster &enemy)
    {
        cout << "CWolf palm back!" << endl;
        basic_monster::FightBack(enemy);
    }
    void hurted(double decrease)
    {
        cout << "CWolf hurt " << decrease << endl;
        basic_monster::hurted(decrease);
    }
    bool IsDead()
    {
        if (basic_monster::IsDead())
        {
            cout << "Wolf was killed" << endl;
            return true;
        }
        return false;
    }
};
int main()
{
    int choice;
    double x, y;
    basic_monster *p[2];
    cout << "Game begin" << endl;
    cout << "1.dragon" << endl
         << "2.wolf" << endl;
    for (int i = 0; i < 2; i++)
    {
        cout << "Enter your choice:";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter dragon life value:";
            cin >> x;
            cout << "Enter dragon attack ability";
            cin >> y;
            p[i] = new fire_dragon(x, y);
        }
        if (choice == 2)
        {
            cout << "Enter wolf life value:";
            cin >> x;
            cout << "Enter wolf attack ability:";
            cin >> y;
            p[i] = new Cwolf(x, y);
        }
    }
    while (1)
    {
        p[0]->Attack(p[1]);
        if (p[0]->IsDead() || p[1]->IsDead())
            break;
    }
    return 0;
}