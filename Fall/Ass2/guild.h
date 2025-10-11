#if !defined(SENECA_GUILD_H)
#define SENECA_GUILD_H
#include <iostream>
#include <string>
#include "character.h"


namespace seneca {

    class Guild {
        std::string m_name{};
        Character** m_members{};
        size_t m_count{};

        void clear();

    public:
        // --- Constructors ---------------------------------------------
        Guild() = default;

        Guild(const char* name)
            : m_name(name), m_members(nullptr), m_count(0) {}

        // --- Rule of 5 ------------------------------------------------
        ~Guild();

        Guild(const Guild& other);

        Guild& operator=(const Guild& other);

        Guild(Guild&& other) noexcept;

        Guild& operator=(Guild&& other) noexcept;

        // --- Operations -----------------------------------------------

        void addMember(Character* c);

        void removeMember(const std::string& name);

        Character* operator[](size_t idx) const;

        void showMembers() const;
    };
} 


#endif // SENECA_GUILD_H
