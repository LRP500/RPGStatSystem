//
// Created by Pierre Roy on 19/12/17.
//

#include "RPGStatModTotalPercent.hpp"

RPGStatSystem::RPGStatModTotalPercent::RPGStatModTotalPercent(float value, bool stack)
        : RPGStatModifier(value, stack)
{}

inline int RPGStatSystem::RPGStatModTotalPercent::getOrder() const
{
    return 3;
}

inline int RPGStatSystem::RPGStatModTotalPercent::applyModifier(int statValue, float modValue)
{
    return static_cast<int>(statValue * modValue);
}
