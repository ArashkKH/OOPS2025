#ifndef SENECA_ARCHER_H
#define SENECA_ARCHER_H

#include <iostream>
#include "character.h"
#include "characterTpl.h"
#include "health.h"

namespace seneca {

    template <typename Weapon_t>
    class Archer : public CharacterTpl<seneca::SuperHealth> {
        int m_baseAttack{};
        int m_baseDefense{};
        Weapon_t m_weapon{};

    public:
        Archer(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t weapon);

        int getAttackAmnt() const override;
        int getDefenseAmnt() const override;
        Character* clone() const override;
        void attack(Character* enemy) override;
        void takeDamage(int dmg) override;
    };

}


#include "archer.cpp"

#endif // SENECA_ARCHER_H
