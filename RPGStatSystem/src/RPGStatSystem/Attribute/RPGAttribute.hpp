//
// Created by Pierre Roy on 29/11/17.
//

#ifndef RPGSTATSYSTEM_RPGATTRIBUTE_HPP
#define RPGSTATSYSTEM_RPGATTRIBUTE_HPP

#include "../Interface/IStatScalable.hpp"
#include "../Modifier/RPGStatModifiable.hpp"

namespace RPGStatSystem {

    class RPGAttribute : public RPGStatModifiable, public IStatScalable {
    private:
        int m_levelValue {};

    public:
        void scaleToLevel(int level) override { m_levelValue = level; }

        int getlevelValue() const { return m_levelValue; }
        int getBaseValue() const override { return RPGStat::getBaseValue() + m_levelValue; }
    };

}

#endif //RPGSTATSYSTEM_RPGATTRIBUTE_HPP
