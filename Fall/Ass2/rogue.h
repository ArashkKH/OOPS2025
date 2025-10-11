#if !defined(SENECA_ROGUE_H)
#define SENECA_ROGUE_H
#include <iostream>
#include "character.h"
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
        Rogue(const char* name, int healthMax, int baseAttack, int baseDefense)
            : CharacterTpl<T>(name, healthMax),
            m_baseAttack(baseAttack),
            m_baseDefense(baseDefense) {}

            
        // --- Overrides -------------------------------------------------
        int getAttackAmnt() const override {
            // BASE_ATTACK + 2 × WEAPON_DAMAGE
            double w = static_cast<double>(m_weapon);
            return static_cast<int>(m_baseAttack + (2 * w));
        }

        int getDefenseAmnt() const override {
            return m_baseDefense;
        }

        Character* clone() const override {
            return new Rogue<T, FirstAbility_t, SecondAbility_t>(*this);
        }

        void attack(Character* enemy) override {
            std::cout << this->getName() << " is attacking " << enemy->getName() << "." << std::endl;

            // activate both abilities on self
            m_firstAbility.useAbility(this);
            m_secondAbility.useAbility(this);

            // get base damage
            int dmg = getAttackAmnt();

            // modify damage using both abilities
            m_firstAbility.transformDamageDealt(dmg);
            m_secondAbility.transformDamageDealt(dmg);

            std::cout << "    Rogue deals " << dmg << " melee damage!" << std::endl;

            enemy->takeDamage(dmg);
        }

        void takeDamage(int dmg) override {
            std::cout << this->getName() << " is attacked for " << dmg << " damage." << std::endl;
            std::cout << "    Rogue has a defense of " << m_baseDefense
                    << ". Reducing damage received." << std::endl;

            dmg -= m_baseDefense;
            if (dmg < 0) dmg = 0;

            // allow both abilities to reduce damage further
            m_firstAbility.transformDamageReceived(dmg);
            m_secondAbility.transformDamageReceived(dmg);

            CharacterTpl<T>::takeDamage(dmg);
        }
    };

}

#endif // SENECA_ROGUE_H
