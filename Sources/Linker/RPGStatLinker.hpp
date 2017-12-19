//
// Created by Pierre Roy on 29/11/17.
//

#ifndef RPGSTATSYSTEM_RPGSTATLINKER_HPP
#define RPGSTATSYSTEM_RPGSTATLINKER_HPP

#include "../Stat/RPGStat.hpp"
#include "../System/Event/Event.hpp"
#include "../Interface/IStatValueChange.hpp"

namespace RPGStatSystem {

    class RPGStatLinker : public IStatValueChange {
    protected:
        RPGStat *m_linkedStat;
        int m_value;

    public:
        explicit RPGStatLinker(RPGStat* stat);
        virtual ~RPGStatLinker() = default;

        RPGStat* getStat() const { return m_linkedStat; }
        virtual int getValue() const { return m_value; }
    };

}

#endif //RPGSTATSYSTEM_RPGSTATLINKER_HPP
