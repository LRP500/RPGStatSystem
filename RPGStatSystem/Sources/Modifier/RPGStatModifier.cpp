//
// Created by Pierre Roy on 28/11/17.
//

#include "RPGStatModifier.hpp"

using RPGStatSystem::RPGStatModifier;

RPGStatModifier::RPGStatModifier()
        : m_statType(RPGStat::Type::None),
          m_modifierType(RPGStatModifier::Type::None),
          m_value(0)
{}

RPGStatModifier::RPGStatModifier(RPGStat::Type statType,
                                 RPGStatModifier::Type modifierType,
                                 float value)
        : m_statType(statType),
          m_modifierType(modifierType),
          m_value(value)
{}
