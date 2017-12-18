//
// Created by Pierre Roy on 28/11/17.
//

#include <iostream>

#include "RPGDefaultCollection.hpp"
#include "../Stat/Modifiable/RPGStatModifiable.hpp"
#include "../Stat/Attribute/RPGAttribute.hpp"
#include "../Stat/Vital/RPGVital.hpp"
#include "../Linker/RPGRatioLinker.hpp"

RPGStatSystem::RPGDefaultCollection::RPGDefaultCollection()
{
    configureStats();
}

void RPGStatSystem::RPGDefaultCollection::configureStats()
{
    RPGStatCollection::configureStats();

    auto strength = getOrCreate<RPGAttribute>(RPGStat::Type::Strength);
    strength->setName("Strength");
    strength->setValue(5);
    // Link To
    auto health = getOrCreate<RPGVital>(RPGStat::Type::Health);
    health->setName("Health");
    health->setValue(10);
    health->addLinker(new RPGRatioLinker(getOrCreate<RPGAttribute>(RPGStat::Type::Strength), 1.0f));
    health->OnCurrentValueChange += &health->getEventHandler()->LOnCurrentValueChange;

    auto agility = getOrCreate<RPGAttribute>(RPGStat::Type::Agility);
    agility->setName("Agility");
    agility->setValue(5);
    // Link To
    auto stamina = getOrCreate<RPGVital>(RPGStat::Type::Stamina);
    stamina->setName("Stamina");
    stamina->setValue(10);
    stamina->addLinker(new RPGRatioLinker(getOrCreate<RPGAttribute>(RPGStat::Type::Agility), 1.0f));
    stamina->updateLinkers();

    auto intel = getOrCreate<RPGAttribute>(RPGStat::Type::Intelligence);
    intel->setName("Intelligence");
    intel->setValue(5);
    // Link To
    auto mana = getOrCreate<RPGVital>(RPGStat::Type::Mana);
    mana->setName("Mana");
    mana->setValue(10);
    mana->addLinker(new RPGRatioLinker(getOrCreate<RPGAttribute>(RPGStat::Type::Intelligence), 1.0f));
    mana->updateLinkers();
}