//
// Created by Pierre Roy on 02/12/17.
//

#ifndef RPGSTATSYSTEM_RPGVITAL_HPP
#define RPGSTATSYSTEM_RPGVITAL_HPP

#include "../Attribute/RPGAttribute.hpp"

namespace RPGStatSystem
{

    class RPGVital : public RPGAttribute {
    private:
        int m_currentValue {0};

    public:
        RPGVital();

        void setCurrentValue(int value);
        void setToMax();

        int getCurrentValue() const;
        int getCurrentValue();
    };

}

#endif //RPGSTATSYSTEM_RPGVITAL_HPP
