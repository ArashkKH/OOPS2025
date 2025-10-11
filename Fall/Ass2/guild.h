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

        void clear() {
            // Guild does not own members; just clears pointers
            delete[] m_members;
            m_members = nullptr;
            m_count = 0;
        }

    public:
        // --- Constructors ---------------------------------------------
        Guild() = default;

        Guild(const char* name)
            : m_name(name), m_members(nullptr), m_count(0) {}

        // --- Rule of 5 ------------------------------------------------
        ~Guild() { clear(); }

        Guild(const Guild& other) { *this = other; }

        Guild& operator=(const Guild& other) {
            if (this != &other) {
                clear();

                // ✅ Always copy name, even if no members
                m_name = other.m_name;
                m_count = other.m_count;

                if (m_count > 0) {
                    m_members = new Character*[m_count];
                    for (size_t i = 0; i < m_count; ++i)
                        m_members[i] = other.m_members[i];
                } else {
                    m_members = nullptr;
                }
            }
            return *this;
        }

        Guild(Guild&& other) noexcept { *this = std::move(other); }

        Guild& operator=(Guild&& other) noexcept {
            if (this != &other) {
                clear();
                m_name = std::move(other.m_name);
                m_members = other.m_members;
                m_count = other.m_count;
                other.m_members = nullptr;
                other.m_count = 0;
            }
            return *this;
        }

        // --- Operations -----------------------------------------------

        void addMember(Character* c) {
            if (!c) return;

            // prevent duplicates
            for (size_t i = 0; i < m_count; ++i)
                if (m_members[i]->getName() == c->getName())
                    return;

            Character** temp = new Character*[m_count + 1];
            for (size_t i = 0; i < m_count; ++i)
                temp[i] = m_members[i];
            temp[m_count] = c;

            delete[] m_members;
            m_members = temp;
            ++m_count;

            // increase max health by 300
            c->setHealthMax(c->getHealthMax() + 300);
        }

        void removeMember(const std::string& name) {
            for (size_t i = 0; i < m_count; ++i) {
                if (m_members[i]->getName() == name) {
                    // decrease max health by 300
                    m_members[i]->setHealthMax(m_members[i]->getHealthMax() - 300);

                    // shift elements left
                    for (size_t j = i; j < m_count - 1; ++j)
                        m_members[j] = m_members[j + 1];
                    --m_count;

                    if (m_count == 0) {
                        delete[] m_members;
                        m_members = nullptr;
                    }
                    return;
                }
            }
        }

        Character* operator[](size_t idx) const {
            if (idx >= m_count)
                return nullptr;
            return m_members[idx];
        }

        void showMembers() const {
            if (m_name.empty() && m_count == 0) {
                std::cout << "No guild." << std::endl;
                return;
            }

            if (m_count == 0) {
                // ✅ even empty guild prints name
                std::cout << "[Guild] " << m_name << std::endl;
                return;
            }

            std::cout << "[Guild] " << m_name << std::endl;
            for (size_t i = 0; i < m_count; ++i)
                std::cout << "    " << (i + 1) << ": " << *m_members[i] << std::endl;
        }
    };
} 


#endif // SENECA_GUILD_H
