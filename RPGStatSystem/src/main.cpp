#include <iostream>

#include "RPGStatSystem/Collections/RPGDefaultCollection.hpp"
#include "RPGStatSystem/RPGStatModifiable.hpp"

using namespace RPGStatSystem;

int main()
{
    auto *defaultStats = new RPGStatSystem::RPGDefaultCollection();

    for (const RPGStatSystem::RPGStat::Type& type : RPGStatSystem::Stats) {
        auto stat = defaultStats->getStat<RPGStatSystem::RPGStatModifiable>(type);
        std::cout << "[" <<stat->getName() << "] = " << stat->getBaseValue() << std::endl;
    }

    auto health = defaultStats->getStat<RPGStatModifiable>(RPGStat::Type::Health);
    health->addModifier(RPGStatModifier(RPGStat::Type::Health, RPGStatModifier::Type::BaseValueAdd, 10.0));
    health->updateModifiers();

    for (const RPGStatSystem::RPGStat::Type& type : RPGStatSystem::Stats) {
        auto stat = defaultStats->getStat<RPGStatSystem::RPGStatModifiable>(type);
        std::cout << "[" << stat->getName() << "] = " << stat->getValue() << std::endl;
    }

    return 0;
}