#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <math.h>

class Warrior
{
private:
    int attack;
    int block;

public:
    int health;
    std::string name;
    // std::string getName()
    // {
    //     return this->name;
    // }
    // void SetName(std::string name) { this->name = name; }
    // int getHealth()
    // {
    //     return this->health;
    // }
    // void SetHealth(int health) { this->health = health; }
    // int getAttack()
    // {
    //     return this->attack;
    // }
    // void SetAttack(int attack) { this->attack = attack; }
    // int getBlock()
    // {
    //     return this->block;
    // }
    // void SetBlock(int block) { this->block = block; }

    // void SetAll(std::string, int, int, int);

    Warrior(std::string name, int health,
            int attack, int block)
    {
        this->name = name;
        this->health = health;
        this->attack = attack;
        this->block = block;
    }

    // Warrior();

    ~Warrior();

    int AttackHandler()
    {
        return std::rand() % this->attack;
    }

    int BlockHandler()
    {
        return std::rand() % this->block;
    }

    // void StartFight(std::string, std::string);
};

// void Warrior::SetAll(std::string name, int health, int attack, int block)
// {
//     this->name = name;
//     this->health = health;
//     this->attack = attack;
//     this->block = block;
// }

// Warrior::Warrior(std::string name, int health, int attack, int block)
// {
//     this->name = name;
//     this->health = health;
//     this->attack = attack;
//     this->block = block;
// }

// Warrior::Warrior()
// {
//     this->name = "";
//     this->health = 0;
//     this->attack = 0;
//     this->block = 0;
// }

Warrior::~Warrior()
{
    std::cout << "the Warrior " << this->name << " has been destroyed.\n";
}

class Battle
{
public:
    static void StartFight(Warrior &warrior1, Warrior &warrior2)
    {
        while (true)
        {
            if (Battle::GetAttackResult(warrior1, warrior2).compare("Game Over") == 0)
            {
                std::cout << "Game Over\n";
                break;
            }
            if (Battle::GetAttackResult(warrior2, warrior1).compare("Game Over") == 0)
            {
                std::cout << "Game Over\n";
                break;
            }
        }
    }

    static std::string GetAttackResult(Warrior &warriorA,
                                       Warrior &warriorB)
    {
        // Get random attack & block amounts and calculate damage
        int warriorAAttkAmt = warriorA.AttackHandler();
        int warriorBBlockAmt = warriorB.BlockHandler();
        int damage2WarriorB = ceil(warriorAAttkAmt - warriorBBlockAmt);

        // Change health total if > 0 and output changes
        damage2WarriorB = (damage2WarriorB <= 0) ? 0 : damage2WarriorB;
        warriorB.health = warriorB.health - damage2WarriorB;
        printf("%s attacks %s and deals %d damage\n",
               warriorA.name.c_str(), warriorB.name.c_str(),
               damage2WarriorB);
        printf("%s is down to %d health\n", warriorB.name.c_str(),
               warriorB.health);

        // static std::string GetAttackResult(Warrior &warriorA, Warrior &warriorB)
        // {
        //     int warriorAAttkAmt = warriorA.AttackHandler();
        //     int warriorBBlckAmt = warriorB.BlockHandler();
        //     int damage2wWarriorB = ceil(warriorAAttkAmt - warriorBBlckAmt);
        //     damage2wWarriorB = (damage2wWarriorB <= 0) ? 0 : damage2wWarriorB;
        //     warriorB.health = warriorB.health - damage2wWarriorB;

        //     printf("%s attacks %s and deals %d damage.\n", warriorA.name().c_str(), warriorB.name().c_str(), damage2wWarriorB);

        //     printf("% s is down to % d health\n", warriorB.name().c_str(), warriorB.health);

        //         if (warriorB.health <= 0)
        //         {
        //             printf("%s has died and %s is victorious.", warriorB.name().c_str(), warriorA.name().c_str());
        //             return "Game Over";
        //         }
        //         else
        //         {
        //             return "Fight Again!";
        //         }
        //     }
        // };

        if (warriorB.health <= 0)
        {
            printf("%s has Died and %s is Victorious\n",
                   warriorB.name.c_str(), warriorA.name.c_str());
            return "Game Over";
        }
        else
        {
            return "Fight Again";
        }
    }
};

// void Battle::StartFight(std::string player1, std::string player2)
// {
// }

int main()
{
    srand(time(NULL));
    // Warrior thor("Thor", 150, 30, 20);
    // Warrior hulk("Hulk", 145, 25, 25);
    Warrior batman("Batman", 180, 35, 35);
    Warrior superman("Superman", 185, 30, 40);

    // Battle::StartFight(thor, hulk);
    Battle::StartFight(batman, superman);
    system("pause");
}