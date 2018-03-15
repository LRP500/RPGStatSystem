//
// Created by Pierre Roy on 29/11/17.
//

#include "RPGAttribute.hpp"

RPGStatSystem::RPGAttribute::RPGAttribute()
{}

int RPGStatSystem::RPGAttribute::getBaseValue() const
{
    return RPGStat::getBaseValue() + m_levelValue + m_linkerValue;
}

void RPGStatSystem::RPGAttribute::addLinker(RPGStatSystem::RPGStatLinker* linker)
{
    m_linkers.emplace_back(linker);
    // Subscribe to linker callback. Any change on master stat will trigger a
    // recalculation of linkers value and trigger slave stat update
    linker->listenTokens.push_back(linker->OnLinkValueChange.attach([this] (const RPGStatLinker& l) {
        OnLinkerValueChange(l);
    }));
}

void RPGStatSystem::RPGAttribute::clearLinkers()
{
    m_linkers.clear();
}

void RPGStatSystem::RPGAttribute::updateLinkers()
{
    int newLinkerValue = 0;
    for (const auto& link : m_linkers)
    {
        newLinkerValue += link->getValue();
    }
    if (newLinkerValue != m_linkerValue)
        triggerValueChange(); // Will notify slave stat
}

void RPGStatSystem::RPGAttribute::scaleToLevel(int level)
{
    m_levelValue = level;
    triggerValueChange();
}

void RPGStatSystem::RPGAttribute::removeLinker(RPGStatSystem::RPGStatLinker *linker)
{
    m_linkers.remove(linker);
}

void RPGStatSystem::RPGAttribute::OnLinkerValueChange(const RPGStatSystem::RPGStatLinker& sender)
{
    updateLinkers();
}
