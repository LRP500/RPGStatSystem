//
// Created by Pierre Roy on 28/11/17.
//

#ifndef RPGSTATSYSTEM_RPGSTATMODIFIER_HPP
#define RPGSTATSYSTEM_RPGSTATMODIFIER_HPP

#include "../Collection/RPGStatCollection.hpp"

namespace RPGStatSystem {

    class RPGStatModifier {
    public:
        enum Type {
            None,
            BaseValuePercent,
            BaseValueAdd,
            TotalValuePercent,
            TotalValueAdd,
        };

    private:
        float m_value;
        Type m_modifierType;
        RPGStat::Type m_statType;

    public:
        RPGStatModifier();
        RPGStatModifier(RPGStat::Type statType, Type modifierType, float value);
        ~RPGStatModifier() = default;

        float getValue() const { return m_value; }
        Type getModifierType() const { return m_modifierType; }
        RPGStat::Type getStatType() const { return m_statType; }

        void setValue(float value) { m_value = value; }
        void setModifierType(Type type) { m_modifierType = type; }
        void setStatType(RPGStat::Type type) { m_statType = type; }
    };

}

#endif //RPGSTATSYSTEM_RPGSTATMODIFIER_HPP
