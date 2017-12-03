#include <iostream>

#include "RPGStatSystem/Collection/Collections/RPGDefaultCollection.hpp"
#include "RPGStatSystem/Modifier/RPGStatModifiable.hpp"
#include "RPGStatSystem/Interface/IStatScalable.hpp"
#include "RPGStatSystem/Attribute/RPGAttribute.hpp"
#include "RPGStatSystem/Vital/RPGVital.hpp"

using namespace RPGStatSystem;

int main()
{
    auto *defaultStats = new RPGStatSystem::RPGDefaultCollection();

    // Testing Base Stat
    std::cout << "Base Stats\n=================" << std::endl;
    for (const RPGStatSystem::RPGStat::Type& type : RPGStatSystem::Stats) {
        auto stat = defaultStats->getStat<RPGStatSystem::RPGStatModifiable>(type);
        if (stat)
            std::cout << "[" << stat->getName() << "=" << stat->getValue() << "]" << std::endl;
    }

    // Get all attributes
    auto health = defaultStats->getStat<RPGVital>(RPGStat::Type::Health);
    auto mana = defaultStats->getStat<RPGVital>(RPGStat::Type::Mana);
    auto stamina = defaultStats->getStat<RPGVital>(RPGStat::Type::Stamina);
    auto strength = defaultStats->getStat<RPGAttribute>(RPGStat::Type::Strength);
    auto agility = defaultStats->getStat<RPGAttribute>(RPGStat::Type::Agility);
    auto intel = defaultStats->getStat<RPGAttribute>(RPGStat::Type::Intelligence);

    // Testing modifier
    std::cout << "\nStat Modifiers\n================" << std::endl;
    agility->addModifier(RPGStatModifier(RPGStat::Type::Agility, RPGStatModifier::Type::BaseValueAdd, 100.0));
    agility->updateModifiers();
    std::cout << "Add " << agility->getModifierValue() << " to agility base value" << "\n";

    strength->addModifier(RPGStatModifier(RPGStat::Type::Strength, RPGStatModifier::Type::BaseValuePercent, 10.0));
    strength->updateModifiers();
    std::cout << "Add Percentage 10.0 (1000%) to " << strength->getName() << "\n";

    std::cout << "[" << agility->getName() << "=" << agility->getValue() << "]" << std::endl;
    std::cout << "[" << strength->getName() << "=" << strength->getValue() << "]" << std::endl;

    // Testing Linkers
    std::cout << "\nStat Linkers\n===================" << std::endl;
    std::cout << stamina->getName() << " linked to agility with ratio of 1.0f" << std::endl;
    std::cout << "[" << agility->getName() << "=" << agility->getBaseValue() << "]" << std::endl;
    std::cout << "[" << stamina->getName() << "=" << stamina->getBaseValue() << "]" << std::endl;

    // Testing scalability & interface implementation
    std::cout << "\nStat Scalables\n===================" << std::endl;

    if (dynamic_cast<IStatScalable *>(agility))
        std::cout << "IStatScalable correctly implemented" << std::endl;

    std::cout << "Scale intelligence to level 12" << std::endl;
    intel->scaleToLevel(12);
    std::cout << "[" << intel->getName() << "=" << intel->getBaseValue() << "]" << std::endl;

    return 0;
}