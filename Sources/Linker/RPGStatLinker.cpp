//
// Created by Pierre Roy on 29/11/17.
//

#include "RPGStatLinker.hpp"

RPGStatSystem::RPGStatLinker::RPGStatLinker(RPGStatSystem::RPGStat* stat) : m_linkedStat(stat)
{
    // Checks if master stat is modifiable
    auto iValueChange = dynamic_cast<IStatValueChange *>(stat);
    // If it is, then subscribe master stat to the linker callback
    if (iValueChange)
        iValueChange->listenTokens.push_back(iValueChange->OnLinkValueChange.attach([this] (const RPGStatLinker& l) {
            OnLinkedStatValueChange(l);
        }));
}

// Notifies slave stat of master stat's changes and communicates value
void RPGStatSystem::RPGStatLinker::OnLinkedStatValueChange(const RPGStatSystem::RPGStatLinker& linker)
{
    // Callback should receive value trough args
    if (!listenTokens.empty())
        OnLinkValueChange(*this);
}
