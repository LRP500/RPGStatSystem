//
// Created by Pierre Roy on 03/12/17.
//

#ifndef RPGSTATSYSTEM_ISTATVALUECHANGE_HPP
#define RPGSTATSYSTEM_ISTATVALUECHANGE_HPP

#include "../System/Broadcaster.hpp"

namespace  RPGStatSystem
{
    class RPGStatLinker;
}

// Broadcast interface for modifiable stat (RPGStatModifiable, RPGAttribute)
namespace RPGStatSystem
{
    class IStatValueChange {
    public:
        System::Broadcaster<const RPGStat&> OnValueChange;
        System::Broadcaster<const RPGStatLinker&> OnLinkValueChange;
        std::vector<token> listenTokens;
    };
}

#endif //RPGSTATSYSTEM_ISTATVALUECHANGE_HPP
