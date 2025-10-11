#include "rogue.h"

namespace seneca {

template <typename T, typename FirstAbility_t, typename SecondAbility_t>
Rogue<T, FirstAbility_t, SecondAbility_t>::Rogue(
    const char* name, int healthMax, int baseAttack, int baseDefense)
    : CharacterTpl<T>(name, healthMax),
      m_baseAttack(baseAttack),
      m_baseDefense(baseDefense) {}

template <typename T, typename FirstAbility_t, typename SecondAbility_t>
int Rogue<T, FirstAbility_t, SecondAbility_t>::getAttackAmnt() const {
    double w = static_cast<double>(m_weapon);
    return static_cast<int>(m_baseAttack + (2 * w));
}

template <typename T, typename FirstAbility_t, typename SecondAbility_t>
int Rogue<T, FirstAbility_t, SecondAbility_t>::getDefenseAmnt() const {
    return m_baseDefense;
}

template <typename T, typename FirstAbility_t, typename SecondAbility_t>
Character* Rogue<T, FirstAbility_t, SecondAbility_t>::clone() const {
    return new Rogue<T, FirstAbility_t, SecondAbility_t>(*this);
}

template <typename T, typename FirstAbility_t, typename SecondAbility_t>
void Rogue<T, FirstAbility_t, SecondAbility_t>::attack(Character* enemy) {
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

template <typename T, typename FirstAbility_t, typename SecondAbility_t>
void Rogue<T, FirstAbility_t, SecondAbility_t>::takeDamage(int dmg) {
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

} // namespace seneca
