#if !defined(SENECA_BARBARIAN_H)
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
                Weapon_t primary, Weapon_t secondary)
            : CharacterTpl<T>(name, healthMax),
            m_baseAttack(baseAttack),
            m_baseDefense(baseDefense) {
            m_weapon[0] = primary;
            m_weapon[1] = secondary;
        }

        // --- Overrides -------------------------------------------------
        int getAttackAmnt() const override {
            // BASE_ATTACK + (weapon1 + weapon2) / 2
            double w1 = static_cast<double>(m_weapon[0]);
            double w2 = static_cast<double>(m_weapon[1]);
            return static_cast<int>(m_baseAttack + (w1 / 2.0) + (w2 / 2.0));
        }

        int getDefenseAmnt() const override {
            return m_baseDefense;
        }

        Character* clone() const override {
            return new Barbarian<T, Ability_t, Weapon_t>(*this);
        }

        void attack(Character* enemy) override {
            std::cout << this->getName() << " is attacking " << enemy->getName() << "." << std::endl;

            // activate ability on self
            m_ability.useAbility(this);

            // get base damage
            int dmg = getAttackAmnt();

            // allow ability to modify outgoing damage
            m_ability.transformDamageDealt(dmg);

            std::cout << "    Barbarian deals " << dmg << " melee damage!" << std::endl;

            enemy->takeDamage(dmg);
        }

        void takeDamage(int dmg) override {
            std::cout << this->getName() << " is attacked for " << dmg << " damage." << std::endl;
            std::cout << "    Barbarian has a defense of " << m_baseDefense
                    << ". Reducing damage received." << std::endl;

            // reduce by defense
            dmg -= m_baseDefense;
            if (dmg < 0) dmg = 0;

            // allow ability to further reduce damage
            m_ability.transformDamageReceived(dmg);

            // update health via base
            CharacterTpl<T>::takeDamage(dmg);
        }
    };

}



#endif // SENECA_BARBARIAN_H
