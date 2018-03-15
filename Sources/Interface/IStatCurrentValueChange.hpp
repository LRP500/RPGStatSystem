//
// Created by Pierre Roy on 03/12/17.
//

#ifndef RPGSTATSYSTEM_ISTATCURRENTVALUECHANGE_HPP
#define RPGSTATSYSTEM_ISTATCURRENTVALUECHANGE_HPP

#include "../Stat/RPGStat.hpp"
#include "../System/Broadcaster.hpp"

namespace RPGStatSystem
{
    class RPGVital;
}

// Broadcast interface for fluctuating stats (RPGVital)
namespace RPGStatSystem
{
    class IStatCurrentValueChange {
    public:
        System::Broadcaster<const RPGVital&> OnCurrentValueChange;
        // No need for listen tokens as IStatValueChange already implement it
    };

// TODO
}

#endif //RPGSTATSYSTEM_ISTATCURRENTVALUECHANGE_HPP
