#ifndef SENECA_BARBARIAN_H
#define SENECA_BARBARIAN_H

#include <iostream>
#include "character.h"
#include "characterTpl.h"

namespace seneca {

template <typename T, typename Ability_t, typename Weapon_t>
class Barbarian : public CharacterTpl<T> {
    int m_baseAttack{};
    int m_baseDefense{};
    Ability_t m_ability{};
    Weapon_t m_weapon[2]{};

public:
    Barbarian(const char* name, int healthMax, int baseAttack, int baseDefense,
              Weapon_t primary, Weapon_t secondary);

    int getAttackAmnt() const override;
    int getDefenseAmnt() const override;
    Character* clone() const override;
    void attack(Character* enemy) override;
    void takeDamage(int dmg) override;
};

} // namespace seneca

#include "barbarian.cpp"

#endif // SENECA_BARBARIAN_H
