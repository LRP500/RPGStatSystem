//
// Created by Pierre Roy on 02/12/17.
//

#ifndef RPGSTATSYSTEM_RPGVITAL_HPP
#define RPGSTATSYSTEM_RPGVITAL_HPP

#include "../../Stat/Attribute/RPGAttribute.hpp"
#include "../../Interface/IStatCurrentValueChange.hpp"
//#include "../../System/Event/Event.hpp"

namespace RPGStatSystem
{

    class RPGVital : public RPGAttribute, public IStatCurrentValueChange {
    private:
        int m_currentValue {0};

    public:
        RPGVital();

        void setCurrentValue(int value);
        void setToMax();

        int getCurrentValue() const;
        int getCurrentValue();

        void triggerCurrentValueChange();
    };

}

#endif //RPGSTATSYSTEM_RPGVITAL_HPP
