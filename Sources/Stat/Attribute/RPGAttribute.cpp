//
// Created by Pierre Roy on 29/11/17.
//

#include "RPGAttribute.hpp"

RPGStatSystem::RPGAttribute::RPGAttribute()
//        : LOnLinkerValueChange(this)
{}

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
    for (const auto& linker : m_linkers)
    {
//        linker->OnValueChange -= &LOnLinkerValueChange;
    }
    m_linkers.clear();
}

void RPGStatSystem::RPGAttribute::updateLinkers()
{
    m_linkerValue = 0;
    for (const auto& link : m_linkers)
    {
        m_linkerValue += link->getValue();
    }
    triggerValueChange();
}

void RPGStatSystem::RPGAttribute::scaleToLevel(int level)
{
    m_levelValue = level;
    triggerValueChange();
}

void RPGStatSystem::RPGAttribute::removeLinker(RPGStatSystem::RPGStatLinker *linker)
{
    m_linkers.remove(linker);
//    linker->OnValueChange -= &LOnLinkerValueChange;
}

void RPGStatSystem::RPGAttribute::OnLinkerValueChange(const RPGStatSystem::RPGStat& sender)
{
    updateLinkers();
}
