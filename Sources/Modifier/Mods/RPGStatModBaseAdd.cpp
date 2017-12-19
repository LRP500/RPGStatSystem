//
// Created by Pierre Roy on 19/12/17.
//

#include "RPGStatModBaseAdd.hpp"

RPGStatSystem::RPGStatModBaseAdd::RPGStatModBaseAdd(float value, bool stack)
        : RPGStatModifier(value, stack)
{}

inline int RPGStatSystem::RPGStatModBaseAdd::getOrder() const
{
    return 2;
}

inline int RPGStatSystem::RPGStatModBaseAdd::applyModifier(int statValue, float modValue)
{
    return static_cast<int>(modValue);
}
