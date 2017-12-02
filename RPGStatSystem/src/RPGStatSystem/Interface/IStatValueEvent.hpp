//
// Created by Pierre Roy on 03/12/17.
//

#ifndef RPGSTATSYSTEM_ISTATVALUECHANGE_HPP
#define RPGSTATSYSTEM_ISTATVALUECHANGE_HPP

#include "../Event/Event.hpp"
#include "../Stat/RPGStat.hpp"

namespace RPGStatSystem
{

    class IStatValueEvent {
    protected:
        System::Event<const RPGStat&> OnValueChange;
    };

}

#endif //RPGSTATSYSTEM_ISTATVALUECHANGE_HPP
