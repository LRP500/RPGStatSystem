#include <iostream>

#include "RPGStatSystem/Collection/Collections/RPGDefaultCollection.hpp"
#include "RPGStatSystem/Modifier/RPGStatModifiable.hpp"
#include "RPGStatSystem/Interface/IStatScalable.hpp"
#include "RPGStatSystem/Attribute/RPGAttribute.hpp"

using namespace RPGStatSystem;

int main()
{
    auto *defaultStats = new RPGStatSystem::RPGDefaultCollection();

    // Testing Base Stat
    std::cout << "Base Stats\n=================" << std::endl;
    for (const RPGStatSystem::RPGStat::Type& type : RPGStatSystem::Stats) {
        auto stat = defaultStats->getStat<RPGStatSystem::RPGStatModifiable>(type);
        if (stat)
            std::cout << "[" << stat->getName() << "=" << stat->getBaseValue() << "]" << std::endl;
    }

    // Testing modifier
    std::cout << "\nStat Modifiers\n================" << std::endl;
    auto agility = defaultStats->getStat<RPGAttribute>(RPGStat::Type::Agility);
    agility->addModifier(RPGStatModifier(RPGStat::Type::Agility, RPGStatModifier::Type::BaseValueAdd, 100.0));
    agility->updateModifiers();
    std::cout << "Add " << agility->getModifierValue() << " to agility base value" << "\n";

    auto strength = defaultStats->getStat<RPGStatModifiable>(RPGStat::Type::Strength);
    strength->addModifier(RPGStatModifier(RPGStat::Type::Strength, RPGStatModifier::Type::BaseValuePercent, 10.0));
    strength->updateModifiers();
    std::cout << "Add Percentage 10.0 (1000%) to " << strength->getName() << "\n";

    std::cout << "[" << agility->getName() << "=" << agility->getValue() << "]" << std::endl;
    std::cout << "[" << strength->getName() << "=" << strength->getValue() << "]" << std::endl;

    // Testing scalability & interface implementation
    std::cout << "\nStat Scalables\n===================" << std::endl;

    if (dynamic_cast<IStatScalable *>(agility))
        std::cout << "IStatScalable correctly implemented" << std::endl;
    
    std::cout << "Scale agility to level 12" << std::endl;
    agility->scaleToLevel(12);
    std::cout << "[" << agility->getName() << "=" << agility->getBaseValue() << "]" << std::endl;

    // Testing Linkers
    std::cout << "\nStat Linkers\n===================" << std::endl;
    for (const RPGStatSystem::RPGStat::Type& type : RPGStatSystem::Stats) {
        auto stat = defaultStats->getStat<RPGStatSystem::RPGAttribute>(type);
        if (stat)
            std::cout << "[" << stat->getName() << "=" << stat->getBaseValue() << "]" << std::endl;
    }

    return 0;
}