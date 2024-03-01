#include "character.hpp"
#include <iostream>
#include <random>

enum Environment
{
    YIN,
    YANG
};

static Environment getEnvironment()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, 1);
    int random_value = distr(gen);
    return static_cast<Environment>(random_value);
}

int main()
{
    Player player(2000, 5);
    Enemy enemy(10000, 100);
    while (player.get_health() > 0 && enemy.get_health() > 0)
    {
        Action player_action = player.getAction();
        Action enemy_action = enemy.getAction();

        if (player_action == Action::ATTACK && enemy_action == Action::ATTACK)
        {
            player.take_damage(enemy.get_attack_strength());
            enemy.take_damage(player.get_attack_strength());

            std::cout << "Player and enemy attack each other\n";
            std::cout << "Player health: " << player.get_health() << "\n";
            std::cout << "Enemy health: " << enemy.get_health() << "\n";
        }

        if (player_action == Action::ATTACK && enemy_action == Action::MAGIC)
        {
            if (getEnvironment() == YIN)
            {
                player.take_damage(enemy.get_attack_strength() * 2);
                enemy.take_damage(player.get_attack_strength());
            }
            else
            {
                player.take_damage(enemy.get_attack_strength() / 2);
                enemy.take_damage(player.get_attack_strength());
            }

            std::cout << "Player attacks and enemy uses magic\n";
            std::cout << "Player health: " << player.get_health() << "\n";
            std::cout << "Enemy health: " << enemy.get_health() << "\n";
        }

        if (player_action == Action::ATTACK && enemy_action == Action::FOCUS)
        {
            enemy.take_damage(player.get_attack_strength() * 2);

            std::cout << "Player attacks and enemy focuses\n";
            std::cout << "Enemy fails to focus\n";
            std::cout << "Player health: " << player.get_health() << "\n";
            std::cout << "Enemy health: " << enemy.get_health() << "\n";
        }

        if (player_action == Action::ATTACK && enemy_action == Action::SHIELD)
        {
            enemy.take_damage(player.get_attack_strength());

            std::cout << "Player attacks and enemy uses shield\n";
            std::cout << "Enemy still takes the hit\n";
            std::cout << "Player health: " << player.get_health() << "\n";
            std::cout << "Enemy health: " << enemy.get_health() << "\n";
        }

        if (player_action == Action::ATTACK && enemy_action == Action::BLOCK)
        {
            std::cout << "Player attacks and enemy blocks\n";
            std::cout << "Enemy blocks the attack\n";
            std::cout << "Player health: " << player.get_health() << "\n";
            std::cout << "Enemy health: " << enemy.get_health() << "\n";
        }

        if (player_action == Action::ATTACK && enemy_action == Action::HEAL)
        {
            enemy.take_healing(50);
            enemy.take_damage(player.get_attack_strength());

            std::cout << "Player attacks and enemy heals\n";
            std::cout << "Player health: " << player.get_health() << "\n";
            std::cout << "Enemy health: " << enemy.get_health() << "\n";
        }

        if (player_action == Action::MAGIC && enemy_action == Action::ATTACK)
        {
            if (getEnvironment() == YIN)
            {
                player.take_damage(enemy.get_attack_strength());
                enemy.take_damage(player.get_attack_strength() / 2);
            }
            else
            {
                player.take_damage(enemy.get_attack_strength());
                enemy.take_damage(player.get_attack_strength() * 2);
            }
            std::cout << "Player uses magic and enemy attacks\n";
            std::cout << "Player health: " << player.get_health() << "\n";
            std::cout << "Enemy health: " << enemy.get_health() << "\n";
        }

        if (player_action == Action::MAGIC && enemy_action == Action::MAGIC)
        {
            if (getEnvironment() == YIN)
            {
                player.take_damage(enemy.get_attack_strength() * 2);
                enemy.take_damage(player.get_attack_strength() / 2);
            }
            else
            {
                player.take_damage(enemy.get_attack_strength() / 2);
                enemy.take_damage(player.get_attack_strength() * 2);
            }
            std::cout << "Player and enemy use magic\n";
            std::cout << "Player health: " << player.get_health() << "\n";
            std::cout << "Enemy health: " << enemy.get_health() << "\n";
        }

        if (player_action == Action::MAGIC && enemy_action == Action::FOCUS)
        {
            enemy.take_damage(player.get_attack_strength() * 2);

            std::cout << "Player uses magic and enemy focuses\n";
            std::cout << "Enemy fails to focus\n";
            std::cout << "Player health: " << player.get_health() << "\n";
            std::cout << "Enemy health: " << enemy.get_health() << "\n";
        }

        if (player_action == Action::MAGIC && enemy_action == Action::SHIELD)
        {
            std::cout << "Player uses magic and enemy uses shield\n";
            std::cout << "Enemy shield the magic\n";
            std::cout << "Player health: " << player.get_health() << "\n";
            std::cout << "Enemy health: " << enemy.get_health() << "\n";
        }

        if (player_action == Action::MAGIC && enemy_action == Action::BLOCK)
        {
            enemy.take_damage(player.get_attack_strength());

            std::cout << "Player uses magic and enemy blocks\n";
            std::cout << "Enemy still takes the hit\n";
            std::cout << "Player health: " << player.get_health() << "\n";
            std::cout << "Enemy health: " << enemy.get_health() << "\n";
        }

        if (player_action == Action::MAGIC && enemy_action == Action::HEAL)
        {
            enemy.take_healing(50);
            enemy.take_damage(player.get_attack_strength());

            std::cout << "Player uses magic and enemy heals\n";
            std::cout << "Player health: " << player.get_health() << "\n";
            std::cout << "Enemy health: " << enemy.get_health() << "\n";
        }

        if (player_action == Action::FOCUS && enemy_action == Action::ATTACK)
        {
            player.take_damage(enemy.get_attack_strength() * 2);

            std::cout << "Player focuses and enemy attacks\n";
            std::cout << "Player fails to focus\n";
            std::cout << "Player health: " << player.get_health() << "\n";
            std::cout << "Enemy health: " << enemy.get_health() << "\n";
        }

        if (player_action == Action::FOCUS && enemy_action == Action::MAGIC)
        {
            player.take_damage(enemy.get_attack_strength() * 2);

            std::cout << "Player focuses and enemy uses magic\n";
            std::cout << "Player fails to focus\n";
            std::cout << "Player health: " << player.get_health() << "\n";
            std::cout << "Enemy health: " << enemy.get_health() << "\n";
        }

        if (player_action == Action::FOCUS && enemy_action == Action::FOCUS)
        {
            player.focused();
            enemy.focused();

            std::cout << "Player and enemy focus\n";
            std::cout << "Player attack strength: " << player.get_attack_strength() << "\n";
            std::cout << "Enemy attack strength: " << enemy.get_attack_strength() << "\n";
            std::cout << "Player health: " << player.get_health() << "\n";
            std::cout << "Enemy health: " << enemy.get_health() << "\n";
        }

        if (player_action == Action::FOCUS && enemy_action == Action::SHIELD)
        {
            player.focused();

            std::cout << "Player focuses and enemy uses shield\n";
            std::cout << "Player focuses successfully\n";
            std::cout << "Player attack strength: " << player.get_attack_strength() << "\n";
            std::cout << "Player health: " << player.get_health() << "\n";
            std::cout << "Enemy health: " << enemy.get_health() << "\n";
        }

        if (player_action == Action::FOCUS && enemy_action == Action::BLOCK)
        {
            player.focused();

            std::cout << "Player focuses and enemy blocks\n";
            std::cout << "Player focuses successfully\n";
            std::cout << "Player attack strength: " << player.get_attack_strength() << "\n";
            std::cout << "Player health: " << player.get_health() << "\n";
            std::cout << "Enemy health: " << enemy.get_health() << "\n";
        }

        if (player_action == Action::FOCUS && enemy_action == Action::HEAL)
        {
            player.focused();
            enemy.take_healing(50);

            std::cout << "Player focuses and enemy heals\n";
            std::cout << "Player focuses successfully and enemy heals\n";
            std::cout << "Player attack strength: " << player.get_attack_strength() << "\n";
            std::cout << "Player health: " << player.get_health() << "\n";
            std::cout << "Enemy health: " << enemy.get_health() << "\n";
        }

        if (player_action == Action::SHIELD && enemy_action == Action::ATTACK)
        {
            player.take_damage(enemy.get_attack_strength());

            std::cout << "Player uses shield and enemy attacks\n";
            std::cout << "Player takes the hit\n";
            std::cout << "Player health: " << player.get_health() << "\n";
            std::cout << "Enemy health: " << enemy.get_health() << "\n";
        }

        if (player_action == Action::SHIELD && enemy_action == Action::MAGIC)
        {
            std::cout << "Player uses shield and enemy uses magic\n";
            std::cout << "Player shields the magic\n";
            std::cout << "Player health: " << player.get_health() << "\n";
            std::cout << "Enemy health: " << enemy.get_health() << "\n";
        }

        if (player_action == Action::SHIELD && enemy_action == Action::FOCUS)
        {
            enemy.focused();

            std::cout << "Player uses shield and enemy focuses\n";
            std::cout << "Enemy focuses successfully\n";
            std::cout << "Enemy attack strength: " << enemy.get_attack_strength() << "\n";
            std::cout << "Player health: " << player.get_health() << "\n";
            std::cout << "Enemy health: " << enemy.get_health() << "\n";
        }

        if (player_action == Action::SHIELD && enemy_action == Action::SHIELD)
        {
            std::cout << "Player and enemy use shield\n";
            std::cout << "Player health: " << player.get_health() << "\n";
            std::cout << "Enemy health: " << enemy.get_health() << "\n";
        }

        if (player_action == Action::SHIELD && enemy_action == Action::BLOCK)
        {
            std::cout << "Player uses shield and enemy blocks\n";
            std::cout << "Player health: " << player.get_health() << "\n";
            std::cout << "Enemy health: " << enemy.get_health() << "\n";
        }

        if (player_action == Action::SHIELD && enemy_action == Action::HEAL)
        {
            enemy.take_healing(50);

            std::cout << "Player uses shield and enemy heals\n";
            std::cout << "Enemy heals successfully\n";
            std::cout << "Player health: " << player.get_health() << "\n";
            std::cout << "Enemy health: " << enemy.get_health() << "\n";
        }

        if (player_action == Action::BLOCK && enemy_action == Action::ATTACK)
        {
            std::cout << "Player blocks and enemy attacks\n";
            std::cout << "Player blocks the attack\n";
            std::cout << "Player health: " << player.get_health() << "\n";
            std::cout << "Enemy health: " << enemy.get_health() << "\n";
        }

        if (player_action == Action::BLOCK && enemy_action == Action::MAGIC)
        {
            player.take_damage(enemy.get_attack_strength());

            std::cout << "Player blocks and enemy uses magic\n";
            std::cout << "Player takes the hit\n";
            std::cout << "Player health: " << player.get_health() << "\n";
            std::cout << "Enemy health: " << enemy.get_health() << "\n";
        }

        if (player_action == Action::BLOCK && enemy_action == Action::FOCUS)
        {
            enemy.focused();

            std::cout << "Player blocks and enemy focuses\n";
            std::cout << "Enemy focuses successfully\n";
            std::cout << "Enemy attack strength: " << enemy.get_attack_strength() << "\n";
            std::cout << "Player health: " << player.get_health() << "\n";
            std::cout << "Enemy health: " << enemy.get_health() << "\n";
        }

        if (player_action == Action::BLOCK && enemy_action == Action::SHIELD)
        {
            std::cout << "Player blocks and enemy uses shield\n";
            std::cout << "Player health: " << player.get_health() << "\n";
            std::cout << "Enemy health: " << enemy.get_health() << "\n";
        }

        if (player_action == Action::BLOCK && enemy_action == Action::BLOCK)
        {
            std::cout << "Player and enemy use block\n";
            std::cout << "Player health: " << player.get_health() << "\n";
            std::cout << "Enemy health: " << enemy.get_health() << "\n";
        }

        if (player_action == Action::BLOCK && enemy_action == Action::HEAL)
        {
            enemy.take_healing(50);

            std::cout << "Player blocks and enemy heals\n";
            std::cout << "Enemy heals successfully\n";
            std::cout << "Player health: " << player.get_health() << "\n";
            std::cout << "Enemy health: " << enemy.get_health() << "\n";
        }

        if (player_action == Action::HEAL && enemy_action == Action::ATTACK)
        {
            player.take_healing(50);
            player.take_damage(enemy.get_attack_strength());

            std::cout << "Player heals and enemy attacks\n";
            std::cout << "Player heals successfully and takes the hit\n";
            std::cout << "Player health: " << player.get_health() << "\n";
            std::cout << "Enemy health: " << enemy.get_health() << "\n";
        }

        if (player_action == Action::HEAL && enemy_action == Action::MAGIC)
        {
            player.take_healing(50);
            player.take_damage(enemy.get_attack_strength());

            std::cout << "Player heals and enemy uses magic\n";
            std::cout << "Player heals successfully and takes the hit\n";
            std::cout << "Player health: " << player.get_health() << "\n";
            std::cout << "Enemy health: " << enemy.get_health() << "\n";
        }

        if (player_action == Action::HEAL && enemy_action == Action::FOCUS)
        {
            player.take_healing(50);
            enemy.focused();

            std::cout << "Player heals and enemy focuses\n";
            std::cout << "Player heals successfully and enemy focuses\n";
            std::cout << "Enemy attack strength: " << enemy.get_attack_strength() << "\n";
            std::cout << "Player health: " << player.get_health() << "\n";
            std::cout << "Enemy health: " << enemy.get_health() << "\n";
        }

        if (player_action == Action::HEAL && enemy_action == Action::SHIELD)
        {
            player.take_healing(50);

            std::cout << "Player heals and enemy uses shield\n";
            std::cout << "Player heals successfully\n";
            std::cout << "Player health: " << player.get_health() << "\n";
            std::cout << "Enemy health: " << enemy.get_health() << "\n";
        }

        if (player_action == Action::HEAL && enemy_action == Action::BLOCK)
        {
            player.take_healing(50);

            std::cout << "Player heals and enemy blocks\n";
            std::cout << "Player heals successfully\n";
            std::cout << "Player health: " << player.get_health() << "\n";
            std::cout << "Enemy health: " << enemy.get_health() << "\n";
        }

        if (player_action == Action::HEAL && enemy_action == Action::HEAL)
        {
            player.take_healing(50);
            enemy.take_healing(50);

            std::cout << "Player and enemy heal\n";
            std::cout << "Player heals successfully and enemy heals successfully\n";
            std::cout << "Player health: " << player.get_health() << "\n";
            std::cout << "Enemy health: " << enemy.get_health() << "\n";
        }

        std::cout << "-----------------------------------\n";
        std::cout << "Press to continue\n";
        std::cin.get();
    }
};
