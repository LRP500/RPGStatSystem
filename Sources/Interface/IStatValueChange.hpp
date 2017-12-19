//
// Created by Pierre Roy on 03/12/17.
//

#ifndef RPGSTATSYSTEM_ISTATVALUECHANGE_HPP
#define RPGSTATSYSTEM_ISTATVALUECHANGE_HPP

#include "../System/Event/Event.hpp"
#include "../System/Event/Delegate.hpp"

namespace RPGStatSystem
{

    class IStatValueChange {
    public:
        System::Event<const RPGStat&> OnValueChange;
    };

}

#endif //RPGSTATSYSTEM_ISTATVALUECHANGE_HPP
