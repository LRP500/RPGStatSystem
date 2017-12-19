//
// Created by Pierre Roy on 19/12/17.
//

#include "RPGStatModBasePercent.hpp"

RPGStatSystem::RPGStatModBasePercent::RPGStatModBasePercent(float value, bool stack)
        : RPGStatModifier(value, stack)
{}

inline int RPGStatSystem::RPGStatModBasePercent::getOrder() const
{
    return 1;
}

inline int RPGStatSystem::RPGStatModBasePercent::applyModifier(int statValue, float modValue)
{
    return static_cast<int>(statValue * modValue);
}