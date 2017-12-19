//
// Created by Pierre Roy on 29/11/17.
//

#include "RPGStatLinker.hpp"

RPGStatSystem::RPGStatLinker::RPGStatLinker(RPGStatSystem::RPGStat* stat)
        : m_linkedStat(stat)
{
    IStatValueChange* iValueChange = dynamic_cast<IStatValueChange *>(stat);
    if (iValueChange)
        ; // TODO fix
        //iValueChange->OnValueChange += &m_eventHandler->LOnLinkedStatValueChange;
}