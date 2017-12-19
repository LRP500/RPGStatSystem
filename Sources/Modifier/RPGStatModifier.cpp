//
// Created by Pierre Roy on 28/11/17.
//

#include "RPGStatModifier.hpp"

using RPGStatSystem::RPGStatModifier;

RPGStatModifier::RPGStatModifier(float value, bool stacks)
        : m_value(value), m_stacks(stacks)
{}

void RPGStatSystem::RPGStatModifier::setValue(float value)
{
    if (value != m_value)
    {
        m_value = value;
        triggerValueChange();
    }
}

void RPGStatSystem::RPGStatModifier::triggerValueChange()
{
    // TODO check if event register to delegate
    OnValueChange(*this);
}