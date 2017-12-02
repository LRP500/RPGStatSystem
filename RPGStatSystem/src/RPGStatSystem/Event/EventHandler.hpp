//
// Created by Pierre Roy on 02/12/17.
//

#ifndef EVENTHANDLER_EVENTHANDLER_HPP
#define EVENTHANDLER_EVENTHANDLER_HPP

#include "Delegate.hpp"

namespace RPGStatSystem
{
    class RPGVital;
    class RPGStat;
    class RPGAttribute;
}

namespace System
{

    class EventHandler {
    public:
        EventHandler();
        void OnCurrentValueChange(const RPGStatSystem::RPGVital& sender);
        void OnLinkedStatValueChange(const RPGStatSystem::RPGStat& sender);
        void OnLinkerValueChange(const RPGStatSystem::RPGStat& sender);
        LISTENER(EventHandler, OnCurrentValueChange, const RPGStatSystem::RPGVital&);
        LISTENER(EventHandler, OnLinkedStatValueChange, const RPGStatSystem::RPGStat&);
        LISTENER(EventHandler, OnLinkerValueChange, const RPGStatSystem::RPGStat&);
    };

}

#endif //EVENTHANDLER_EVENTHANDLER_HPP
