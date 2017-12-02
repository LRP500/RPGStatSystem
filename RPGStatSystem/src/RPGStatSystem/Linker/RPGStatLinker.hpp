//
// Created by Pierre Roy on 29/11/17.
//

#ifndef RPGSTATSYSTEM_RPGSTATLINKER_HPP
#define RPGSTATSYSTEM_RPGSTATLINKER_HPP

#include "../Stat/RPGStat.hpp"

namespace RPGStatSystem {

    class RPGStatLinker {
    protected:
        RPGStat *m_stat;
        int m_value;

    public:
        explicit RPGStatLinker(RPGStat* stat);
        virtual ~RPGStatLinker() = default;

        RPGStat* getStat() const { return m_stat; }
        virtual int getValue() const { return m_value; }
    };

}

#endif //RPGSTATSYSTEM_RPGSTATLINKER_HPP