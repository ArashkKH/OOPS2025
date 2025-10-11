#include "archer.h"

namespace seneca {

    template <typename Weapon_t>
    Archer<Weapon_t>::Archer(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t weapon)
        : CharacterTpl<seneca::SuperHealth>(name, healthMax),
        m_baseAttack(baseAttack),
        m_baseDefense(baseDefense),
        m_weapon(weapon) {}

    template <typename Weapon_t>
    int Archer<Weapon_t>::getAttackAmnt() const {
        return static_cast<int>(1.3 * m_baseAttack);
    }

    template <typename Weapon_t>
    int Archer<Weapon_t>::getDefenseAmnt() const {
        return static_cast<int>(1.2 * m_baseDefense);
    }

    template <typename Weapon_t>
    Character* Archer<Weapon_t>::clone() const {
        return new Archer<Weapon_t>(*this);
    }

    template <typename Weapon_t>
    void Archer<Weapon_t>::attack(Character* enemy) {
        std::cout << this->getName() << " is attacking " << enemy->getName() << "." << std::endl;
        int dmg = getAttackAmnt();
        std::cout << "    Archer deals " << dmg << " ranged damage!" << std::endl;
        enemy->takeDamage(dmg);
    }

    template <typename Weapon_t>
    void Archer<Weapon_t>::takeDamage(int dmg) {
        std::cout << this->getName() << " is attacked for " << dmg << " damage." << std::endl;
        std::cout << "    Archer has a defense of " << getDefenseAmnt()
                << ". Reducing damage received." << std::endl;

        dmg -= getDefenseAmnt();
        if (dmg < 0) dmg = 0;

        CharacterTpl<seneca::SuperHealth>::takeDamage(dmg);
    }

}
