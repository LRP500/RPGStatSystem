//
// Created by Pierre Roy on 29/11/17.
//

#ifndef RPGSTATSYSTEM_RPGSTATLINKER_HPP
#define RPGSTATSYSTEM_RPGSTATLINKER_HPP

#include "../Stat/RPGStat.hpp"
#include "../Interface/IStatValueChange.hpp"

namespace RPGStatSystem
{
    // Linker is attached to SLAVE stat and listening to MASTER stat.
    // MASTER stat modified => broadcast to LINKER  => broadcast to SLAVE
    class RPGStatLinker : public IStatValueChange {
    public:
        std::vector<token> listenTokens;

    protected:
        RPGStat *m_linkedStat; // Pointer to MASTER class
        int m_value;

    public:
        explicit RPGStatLinker(RPGStat* stat);
        virtual ~RPGStatLinker() = default;

        RPGStat* getStat() const { return m_linkedStat; }
        virtual int getValue() const { return m_value; }

        void OnLinkedStatValueChange(const RPGStatLinker&);
    };
}

#endif //RPGSTATSYSTEM_RPGSTATLINKER_HPP
