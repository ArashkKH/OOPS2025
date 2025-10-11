#include "barbarian.h"

namespace seneca {

template <typename T, typename Ability_t, typename Weapon_t>
Barbarian<T, Ability_t, Weapon_t>::Barbarian(
    const char* name, int healthMax, int baseAttack, int baseDefense,
    Weapon_t primary, Weapon_t secondary)
    : CharacterTpl<T>(name, healthMax),
      m_baseAttack(baseAttack),
      m_baseDefense(baseDefense) {
    m_weapon[0] = primary;
    m_weapon[1] = secondary;
}

template <typename T, typename Ability_t, typename Weapon_t>
int Barbarian<T, Ability_t, Weapon_t>::getAttackAmnt() const {
    double w1 = static_cast<double>(m_weapon[0]);
    double w2 = static_cast<double>(m_weapon[1]);
    return static_cast<int>(m_baseAttack + (w1 / 2.0) + (w2 / 2.0));
}

template <typename T, typename Ability_t, typename Weapon_t>
int Barbarian<T, Ability_t, Weapon_t>::getDefenseAmnt() const {
    return m_baseDefense;
}

template <typename T, typename Ability_t, typename Weapon_t>
Character* Barbarian<T, Ability_t, Weapon_t>::clone() const {
    return new Barbarian<T, Ability_t, Weapon_t>(*this);
}

template <typename T, typename Ability_t, typename Weapon_t>
void Barbarian<T, Ability_t, Weapon_t>::attack(Character* enemy) {
    std::cout << this->getName() << " is attacking " << enemy->getName() << "." << std::endl;

    m_ability.useAbility(this);

    int dmg = getAttackAmnt();
    m_ability.transformDamageDealt(dmg);

    std::cout << "    Barbarian deals " << dmg << " melee damage!" << std::endl;
    enemy->takeDamage(dmg);
}

template <typename T, typename Ability_t, typename Weapon_t>
void Barbarian<T, Ability_t, Weapon_t>::takeDamage(int dmg) {
    std::cout << this->getName() << " is attacked for " << dmg << " damage." << std::endl;
    std::cout << "    Barbarian has a defense of " << m_baseDefense
              << ". Reducing damage received." << std::endl;

    dmg -= m_baseDefense;
    if (dmg < 0) dmg = 0;

    m_ability.transformDamageReceived(dmg);
    CharacterTpl<T>::takeDamage(dmg);
}

} // namespace seneca
