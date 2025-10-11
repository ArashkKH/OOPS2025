#if !defined(SENECA_TEAM_H)
#define SENECA_TEAM_H

namespace seneca {

    class Team {
        std::string m_name{};
        Character** m_members{};
        size_t m_count{};

        void clear() {
            if (m_members) {
                for (size_t i = 0; i < m_count; ++i)
                    delete m_members[i];
                delete[] m_members;
            }
            m_members = nullptr;
            m_count = 0;
        }

    public:
        // --- Constructors ---------------------------------------------
        Team() = default;

        Team(const char* name)
            : m_name(name), m_members(nullptr), m_count(0) {}

        // --- Rule of 5 ------------------------------------------------
        ~Team() { clear(); }

        Team(const Team& other) {
            *this = other;
        }

        Team& operator=(const Team& other) {
            if (this != &other) {
                clear();
                m_name = other.m_name;
                m_count = other.m_count;
                if (m_count) {
                    m_members = new Character*[m_count];
                    for (size_t i = 0; i < m_count; ++i)
                        m_members[i] = other.m_members[i]->clone();
                } else {
                    m_members = nullptr;
                }
            }
            return *this;
        }

        Team(Team&& other) noexcept {
            *this = std::move(other);
        }

        Team& operator=(Team&& other) noexcept {
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
        void addMember(const Character* c) {
            if (!c) return;

            // prevent duplicates
            for (size_t i = 0; i < m_count; ++i) {
                if (m_members[i]->getName() == c->getName())
                    return;
            }

            Character** temp = new Character*[m_count + 1];
            for (size_t i = 0; i < m_count; ++i)
                temp[i] = m_members[i];

            temp[m_count] = c->clone();

            delete[] m_members;
            m_members = temp;
            ++m_count;
        }

        void removeMember(const std::string& name) {
            for (size_t i = 0; i < m_count; ++i) {
                if (m_members[i]->getName() == name) {
                    delete m_members[i];
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
            if (m_count == 0) {
                std::cout << "No team." << std::endl;
                return;
            }

            std::cout << "[Team] " << m_name << std::endl;
            for (size_t i = 0; i < m_count; ++i) {
                std::cout << "    " << (i + 1) << ": " << *m_members[i] << std::endl;
            }
        }
    };

}


#endif // SENECA_TEAM_H
