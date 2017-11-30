//
// Created by Pierre Roy on 29/11/17.
//

#include "RPGAttribute.hpp"

int RPGStatSystem::RPGAttribute::getBaseValue() const
{
    return RPGStat::getBaseValue() + m_levelValue + m_linkerValue;
}

void RPGStatSystem::RPGAttribute::addLinker(RPGStatSystem::RPGStatLinker* linker)
{
    m_linkers.emplace_back(linker);
}

void RPGStatSystem::RPGAttribute::clearLinkers()
{
    m_linkers.clear();
}

void RPGStatSystem::RPGAttribute::updateLinkers()
{
    m_linkerValue = 0;
    for (const auto& link : m_linkers)
    {
        m_linkerValue += link->getValue();
    }
}
