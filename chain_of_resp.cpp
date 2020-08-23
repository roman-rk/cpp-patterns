#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Creature;

struct StatQuery
{
    enum Statistic {
        attack, defense
    } statistic;
    int result;

    StatQuery(Statistic st) : result{ 0 }, statistic{ st } {}
};

struct Game
{
    vector<Creature*> creatures;
};

struct Creature
{
protected:
    Game& game;
    int base_attack, base_defense;

public:
    Creature(Game &game, int base_attack, int base_defense) : game(game), base_attack(base_attack),
        base_defense(base_defense) {}
    virtual int get_attack() = 0;
    virtual int get_defense() = 0;
    virtual void handle(Creature* creature, StatQuery& q) = 0;
};

class Goblin : public Creature
{
public:
    Goblin(Game &game, int base_attack, int base_defense) : Creature(game, base_attack, base_defense) {}

    Goblin(Game &game) : Creature(game, 1, 1) {}

    int get_attack() override {
        StatQuery q{ StatQuery::Statistic::attack };
        for (auto cr : game.creatures)
        {
            cr->handle(this, q);
        }
        return base_attack + q.result;
    }

    int get_defense() override {
        StatQuery q{ StatQuery::Statistic::defense };
        for (auto cr : game.creatures)
        {
            cr->handle(this, q);
        }
        return base_defense + q.result;
    }

    void handle(Creature* creature, StatQuery& q) override {
        if (creature == this) return;
        switch (q.statistic)
        {
        case StatQuery::Statistic::attack:
            break;
        case StatQuery::Statistic::defense:
            q.result++;
            break;
        default:
            break;
        }
    }
};

class GoblinKing : public Goblin
{
public:
    GoblinKing(Game &game) : Goblin(game, 3, 3) {}

    void handle(Creature* creature, StatQuery& q) override {
        if (creature == this) return;
        switch (q.statistic)
        {
        case StatQuery::Statistic::attack:
            q.result++;
            break;
        case StatQuery::Statistic::defense:
            q.result++;
            break;
        default:
            break;
        }
    }
};

int main()
{
  Game game;
  Goblin goblin(game);
  Goblin goblin2(game);
  Goblin goblin3(game);
  GoblinKing gk(game);

  game.creatures.push_back(&goblin);
  game.creatures.push_back(&goblin2);
  game.creatures.push_back(&goblin3);
  game.creatures.push_back(&gk);
  cout << goblin.get_attack() << " " << goblin.get_defense() << "\n"
       << goblin2.get_attack() << " " << goblin2.get_defense() << "\n"
       << goblin3.get_attack() << " " << goblin3.get_defense() << "\n"
       << gk.get_attack() << " " << gk.get_defense() << "\n";
}