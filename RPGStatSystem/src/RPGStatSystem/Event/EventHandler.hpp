//
// Created by Pierre Roy on 02/12/17.
//

#ifndef EVENTHANDLER_EVENTHANDLER_HPP
#define EVENTHANDLER_EVENTHANDLER_HPP

#include "Delegate.hpp"

namespace RPGStatSystem
{
    class RPGVital;
}

namespace System
{

    class EventHandler {
    public:
        EventHandler();
        void OnCurrentValueChange(const RPGStatSystem::RPGVital& eventData);
        LISTENER(EventHandler, OnCurrentValueChange, const RPGStatSystem::RPGVital&);
    };

}

#endif //EVENTHANDLER_EVENTHANDLER_HPP
