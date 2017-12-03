//
// Created by Pierre Roy on 29/11/17.
//

#include "RPGStatLinker.hpp"

RPGStatSystem::RPGStatLinker::RPGStatLinker(RPGStatSystem::RPGStat* stat)
        : m_linkedStat(stat)
{
    IStatValueEvent* iValueChange = dynamic_cast<IStatValueEvent *>(stat);
    if (iValueChange)
        iValueChange->OnValueChange += &m_eventHandler->LOnLinkedStatValueChange;
}

System::EventHandler *RPGStatSystem::RPGStatLinker::getEventHandler() const
{
    return m_eventHandler;
}
