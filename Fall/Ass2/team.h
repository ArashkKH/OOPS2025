#ifndef SENECA_TEAM_H
#define SENECA_TEAM_H

#include <iostream>
#include <string>
#include "character.h"
#include "characterTpl.h"

namespace seneca {

class Team {
    std::string m_name{};
    Character** m_members{};
    size_t m_count{};

    void clear();

public:
    // --- Constructors ---------------------------------------------
    Team();
    Team(const char* name);

    // --- Rule of 5 ------------------------------------------------
    ~Team();
    Team(const Team& other);
    Team& operator=(const Team& other);
    Team(Team&& other) noexcept;
    Team& operator=(Team&& other) noexcept;

    // --- Operations -----------------------------------------------
    void addMember(const Character* c);
    void removeMember(const std::string& name);
    Character* operator[](size_t idx) const;
    void showMembers() const;
};
}

#endif // SENECA_TEAM_H
