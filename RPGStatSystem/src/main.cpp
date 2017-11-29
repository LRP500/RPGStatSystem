#include <iostream>

#include "RPGStatSystem/Collection/collections/RPGDefaultCollection.hpp"
#include "RPGStatSystem/Modifier/RPGStatModifiable.hpp"
#include "RPGStatSystem/Interface/IStatScalable.hpp"
#include "RPGStatSystem/Attribute/RPGAttribute.hpp"

using namespace RPGStatSystem;

int main()
{
    auto *defaultStats = new RPGStatSystem::RPGDefaultCollection();

    // Testing Base Stat
    std::cout << "Testing Base Stat\n=================" << std::endl;
    for (const RPGStatSystem::RPGStat::Type& type : RPGStatSystem::Stats) {
        auto stat = defaultStats->getStat<RPGStatSystem::RPGStatModifiable>(type);
        if (stat)
            std::cout << "[" << stat->getName() << "=" << stat->getBaseValue() << "]" << std::endl;
    }

    // Testing modifier
    std::cout << "\nTesting Modifier\n================" << std::endl;
    auto health = defaultStats->getStat<RPGStatModifiable>(RPGStat::Type::Health);
    health->addModifier(RPGStatModifier(RPGStat::Type::Health, RPGStatModifier::Type::BaseValueAdd, 10.0));
    health->updateModifiers();
    std::cout << "Add " << health->getModifierValue() << " to health base value" << "\n";

    auto strength = defaultStats->getStat<RPGStatModifiable>(RPGStat::Type::Strength);
    strength->addModifier(RPGStatModifier(RPGStat::Type::Strength, RPGStatModifier::Type::BaseValuePercent, 1.0));
    strength->updateModifiers();
    std::cout << "Add Percentage 1.0 (100%) to " << strength->getName() << "\n";

    std::cout << "[" << health->getName() << "=" << health->getValue() << "]" << std::endl;
    std::cout << "[" << strength->getName() << "=" << strength->getValue() << "]" << std::endl;

    // Testing scalability & interface implementation
    std::cout << "\nTesting Scalability\n===================" << std::endl;
    auto stamina = defaultStats->getStat<RPGStatSystem::RPGAttribute>(RPGStat::Type::Stamina);

    if (dynamic_cast<IStatScalable *>(stamina))
        std::cout << "IStatScalable correctly implemented" << std::endl;
    
    std::cout << "Scale stamina to level 12" << std::endl;
    stamina->scaleToLevel(12);
    std::cout << "[" << stamina->getName() << "=" << stamina->getBaseValue() << "]" << std::endl;

    return 0;
}