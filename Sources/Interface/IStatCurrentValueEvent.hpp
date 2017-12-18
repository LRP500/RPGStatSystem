//
// Created by Pierre Roy on 03/12/17.
//

#ifndef RPGSTATSYSTEM_ISTATCURRENTVALUECHANGE_HPP
#define RPGSTATSYSTEM_ISTATCURRENTVALUECHANGE_HPP

#include "../Event/Event.hpp"
#include "../Stat/RPGStat.hpp"

namespace RPGStatSystem
{

    class IStatCurrentValueEvent {
    public:
        System::Event<const RPGVital&> OnCurrentValueChange;
    };

}

#endif //RPGSTATSYSTEM_ISTATCURRENTVALUECHANGE_HPP
