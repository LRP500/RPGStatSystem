//
// Created by Pierre Roy on 29/11/17.
//

#include "RPGStatLinker.hpp"

RPGStatSystem::RPGStatLinker::RPGStatLinker(RPGStatSystem::RPGStat* stat)
        : m_linkedStat(stat), LOnLinkedStatValueChange(this)
{
    auto iValueChange = dynamic_cast<IStatValueChange *>(stat);
    if (iValueChange)
        iValueChange->OnValueChange += &LOnLinkedStatValueChange;
}

void RPGStatSystem::RPGStatLinker::OnLinkedStatValueChange(const RPGStatSystem::RPGStat &sender)
{
    // TODO Variadic templates support for Event
    // this won't work cause OnValueChange currently take RPGStat as 1st argument
    //OnValueChange(*this);
}
