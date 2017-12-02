//
// Created by Pierre Roy on 03/12/17.
//

#ifndef RPGSTATSYSTEM_ISTATVALUECHANGE_HPP
#define RPGSTATSYSTEM_ISTATVALUECHANGE_HPP

#include "../Event/Event.hpp"
#include "../Event/EventHandler.hpp"

namespace RPGStatSystem
{

    class IStatValueEvent {
    public:
        System::EventHandler* m_eventHandler;
        System::Event<const RPGStat&> OnValueChange;

    public:
        IStatValueEvent() : m_eventHandler(new System::EventHandler()) {}
        virtual System::EventHandler* getEventHandler() const = 0;
    };

}

#endif //RPGSTATSYSTEM_ISTATVALUECHANGE_HPP
