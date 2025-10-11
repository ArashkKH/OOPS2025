#ifndef SENECA_ROGUE_H
#define SENECA_ROGUE_H

#include <iostream>
#include "character.h"
#include "characterTpl.h"
#include "weapons.h"

namespace seneca {

template <typename T, typename FirstAbility_t, typename SecondAbility_t>
class Rogue : public CharacterTpl<T> {
    int m_baseAttack{};
    int m_baseDefense{};
    FirstAbility_t m_firstAbility{};
    SecondAbility_t m_secondAbility{};
    seneca::Dagger m_weapon{}; // always a dagger

public:
    Rogue(const char* name, int healthMax, int baseAttack, int baseDefense);

    int getAttackAmnt() const override;
    int getDefenseAmnt() const override;
    Character* clone() const override;
    void attack(Character* enemy) override;
    void takeDamage(int dmg) override;
};

} // namespace seneca

#include "rogue.cpp"

#endif // SENECA_ROGUE_H
