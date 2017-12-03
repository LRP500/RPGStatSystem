//
// Created by Pierre Roy on 29/11/17.
//

#ifndef RPGSTATSYSTEM_RPGRATIOSTATLINKER_HPP
#define RPGSTATSYSTEM_RPGRATIOSTATLINKER_HPP

#include "RPGStatLinker.hpp"

namespace RPGStatSystem {

    class RPGRatioLinker : public RPGStatLinker {
    private:
        float m_ratio;

    public:
        RPGRatioLinker(RPGStat* stat, float ratio);

        int getValue() const override { return static_cast<int>(m_linkedStat->getBaseValue() * m_ratio); }
    };

}

#endif //RPGSTATSYSTEM_RPGRATIOSTATLINKER_HPP
