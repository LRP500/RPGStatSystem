//
// Created by Pierre Roy on 28/11/17.
//

#include <iostream>

#include "RPGDefaultCollection.hpp"
#include "../../Modifier/RPGStatModifiable.hpp"
#include "../../Attribute/RPGAttribute.hpp"
#include "../../Vital/RPGVital.hpp"
#include "../../Linker/Linkers/RPGRatioLinker.hpp"

#include "../../Event/EventHandler.hpp"

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
    health->setValue(15);
    health->addLinker(new RPGRatioLinker(getOrCreate<RPGAttribute>(RPGStat::Type::Strength), 10.0f));
    health->CurrentValueChange += &m_eh.LOnCurrentValueChange;

    auto agility = getOrCreate<RPGAttribute>(RPGStat::Type::Agility);
    agility->setName("Agility");
    agility->setValue(5);
    // Link To
    auto stamina = getOrCreate<RPGAttribute>(RPGStat::Type::Stamina);
    stamina->setName("Stamina");
    stamina->setValue(10);
    stamina->addLinker(new RPGRatioLinker(getOrCreate<RPGAttribute>(RPGStat::Type::Agility), 10.0f));
    stamina->updateLinkers();

    auto intel = getOrCreate<RPGAttribute>(RPGStat::Type::Intelligence);
    intel->setName("Intelligence");
    intel->setValue(5);
    // Link To
    auto mana = getOrCreate<RPGAttribute>(RPGStat::Type::Mana);
    mana->setName("Mana");
    mana->setValue(10);
    mana->addLinker(new RPGRatioLinker(getOrCreate<RPGAttribute>(RPGStat::Type::Intelligence), 2.0f));
    mana->updateLinkers();
}