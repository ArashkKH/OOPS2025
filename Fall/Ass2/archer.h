#if !defined(SENECA_ARCHER_H)
#define SENECA_ARCHER_H

#include <iostream>
#include "character.h"
#include "health.h"

namespace seneca {

template <typename Weapon_t>
    class Archer : public CharacterTpl<seneca::SuperHealth> {
        int m_baseAttack{};
        int m_baseDefense{};
        Weapon_t m_weapon{};

    public:
        Archer(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t weapon)
            : CharacterTpl<seneca::SuperHealth>(name, healthMax),
            m_baseAttack(baseAttack),
            m_baseDefense(baseDefense),
            m_weapon(weapon) {}

            
        // --- Overrides -------------------------------------------------
        int getAttackAmnt() const override {
            // 1.3 × base attack (weapon ignored)
            return static_cast<int>(1.3 * m_baseAttack);
        }

        int getDefenseAmnt() const override {
            // 1.2 × base defense
            return static_cast<int>(1.2 * m_baseDefense);
        }

        Character* clone() const override {
            return new Archer<Weapon_t>(*this);
        }

        void attack(Character* enemy) override {
            std::cout << this->getName() << " is attacking " << enemy->getName() << "." << std::endl;

            int dmg = getAttackAmnt();

            std::cout << "    Archer deals " << dmg << " ranged damage!" << std::endl;

            enemy->takeDamage(dmg);
        }

        void takeDamage(int dmg) override {
            std::cout << this->getName() << " is attacked for " << dmg << " damage." << std::endl;
            std::cout << "    Archer has a defense of " << getDefenseAmnt()
                    << ". Reducing damage received." << std::endl;

            dmg -= getDefenseAmnt();
            if (dmg < 0) dmg = 0;

            CharacterTpl<seneca::SuperHealth>::takeDamage(dmg);
        }
    };

}

#endif // SENECA_ARCHER_H
