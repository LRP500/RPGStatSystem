//
// Created by Pierre Roy on 28/11/17.
//

#include "RPGDefaultCollection.hpp"
#include "../RPGStatModifiable.hpp"

RPGStatSystem::RPGDefaultCollection::RPGDefaultCollection()
{
    configureStats();
}

void RPGStatSystem::RPGDefaultCollection::configureStats()
{
    RPGStatCollection::configureStats();

    auto health = getOrCreate<RPGStatModifiable>(RPGStat::Type::Health);
    health->setName("Health");
    health->setValue(15);

    auto strength = getOrCreate<RPGStatModifiable>(RPGStat::Type::Strength);
    strength->setName("Strength");
    strength->setValue(5);

    auto agility = getOrCreate<RPGStatModifiable>(RPGStat::Type::Agility);
    agility->setName("Agility");
    agility->setValue(5);
}