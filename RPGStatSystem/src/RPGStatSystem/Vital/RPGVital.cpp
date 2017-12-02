//
// Created by Pierre Roy on 02/12/17.
//

#include "RPGVital.hpp"

RPGStatSystem::RPGVital::RPGVital()
{

}

void RPGStatSystem::RPGVital::setCurrentValue(int value)
{
    m_currentValue = value;
}

int RPGStatSystem::RPGVital::getCurrentValue() const
{
    return m_currentValue;
}

int RPGStatSystem::RPGVital::getCurrentValue()
{
    if (m_currentValue > getValue())
    {
        m_currentValue = getValue();
    }
    else if (m_currentValue < 0)
    {
        m_currentValue = 0;
    }
    return static_cast<const RPGVital*>(this)->getCurrentValue();
}

void RPGStatSystem::RPGVital::setToMax()
{
    m_currentValue = getValue();
}


