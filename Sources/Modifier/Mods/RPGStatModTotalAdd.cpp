//
// Created by Pierre Roy on 19/12/17.
//

#include "RPGStatModTotalAdd.hpp"

RPGStatSystem::RPGStatModTotalAdd::RPGStatModTotalAdd(float value, bool stack)
        : RPGStatModifier(value, stack)
{}

inline int RPGStatSystem::RPGStatModTotalAdd::getOrder() const
{
    return 4;
}

inline int RPGStatSystem::RPGStatModTotalAdd::applyModifier(int statValue, float modValue)
{
    return static_cast<int>(modValue);
}
