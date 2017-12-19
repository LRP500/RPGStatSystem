//
// Created by Pierre Roy on 28/11/17.
//

#include <iostream>

#include "RPGStatCollection.hpp"
#include "../Stat/Modifiable/RPGStatModifiable.hpp"
#include "../Stat/Attribute/RPGAttribute.hpp"
#include "../Stat/Vital/RPGVital.hpp"

using RPGStatSystem::RPGStat;
using RPGStatSystem::RPGVital;
using RPGStatSystem::RPGAttribute;
using RPGStatSystem::RPGStatModifiable;
using RPGStatSystem::RPGStatCollection;

RPGStatCollection::RPGStatCollection()
{
    m_stats.reserve(STAT_TYPE_COUNT);
}

template <typename T>
T* RPGStatCollection::getStat(RPGStat::Type type)
{
    return (contains(type)) ? dynamic_cast<T*>(m_stats[type]) : nullptr;
}

template <typename T>
T* RPGStatCollection::createStat(RPGStat::Type type)
{
    m_stats.insert(std::make_pair(type, new T()));
    return getStat<T>(type);
}

template <typename T>
T* RPGStatCollection::getOrCreate(RPGStat::Type type)
{
    return (contains(type)) ? getStat<T>(type) : createStat<T>(type);
}

void RPGStatCollection::configureStats()
{}

bool RPGStatCollection::contains(RPGStat::Type type) const
{
    return static_cast<bool>(m_stats.count(type));
}

void RPGStatCollection::addStatModifier(RPGStat::Type target, RPGStatModifier* mod, bool update)
{
    if (contains(target))
    {
        auto modStat = dynamic_cast<IStatModifiable*>(getStat<RPGStat>(target));
        if (modStat)
        {
            modStat->addModifier(mod);
            if (update)
            {
                modStat->updateModifiers();
            }
        }
    }
}

void RPGStatSystem::RPGStatCollection::clearStatModifiers(RPGStat::Type type, bool update)
{
    if (contains(type))
    {
        auto modStat = dynamic_cast<IStatModifiable*>(getStat(type));
        if (modStat)
        {
            modStat->clearModifiers();
            if (update)
            {
                modStat->updateModifiers();
            }
        }
    }
}

void RPGStatCollection::clearAllStatModifiers(bool update)
{
    for (const auto& stat : m_stats)
    {
        clearStatModifiers(stat.first, update);
    }
}

void RPGStatCollection::updateStatModifier(RPGStat::Type type)
{
    if (contains(type))
    {
        auto modStat = dynamic_cast<IStatModifiable*>(getStat(type));
        if (modStat)
        {
            modStat->updateModifiers();
        }
    }
}

void RPGStatCollection::updateAllStatModifiers()
{
    for (const auto& stat : m_stats)
    {
        updateStatModifier(stat.first);
    }
}

template RPGStat* RPGStatCollection::getStat<RPGStat>(RPGStat::Type type);
template RPGStatModifiable* RPGStatCollection::getStat<RPGStatModifiable>(RPGStat::Type type);
template RPGAttribute* RPGStatCollection::getStat<RPGAttribute>(RPGStat::Type type);
template RPGVital* RPGStatCollection::getStat<RPGVital>(RPGStat::Type type);

template RPGStat* RPGStatCollection::createStat<RPGStat>(RPGStat::Type type);
template RPGStatModifiable* RPGStatCollection::createStat<RPGStatModifiable>(RPGStat::Type type);
template RPGAttribute* RPGStatCollection::createStat<RPGAttribute>(RPGStat::Type type);
template RPGVital* RPGStatCollection::createStat<RPGVital>(RPGStat::Type type);

template RPGStat* RPGStatCollection::getOrCreate<RPGStat>(RPGStat::Type type);
template RPGStatModifiable* RPGStatCollection::getOrCreate<RPGStatModifiable>(RPGStat::Type type);
template RPGAttribute* RPGStatCollection::getOrCreate<RPGAttribute>(RPGStat::Type type);
template RPGVital* RPGStatCollection::getOrCreate<RPGVital>(RPGStat::Type type);