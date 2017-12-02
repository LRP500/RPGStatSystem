//
// Created by Pierre Roy on 02/12/17.
//

#include <iostream>

#include "EventHandler.hpp"

Signal::EventHandler::EventHandler() : LOnCurrentValueChange(this)
{}

void Signal::EventHandler::OnCurrentValueChange(const RPGStatSystem::RPGVital& sender)
{
    if (&sender)
    {
        std::cout << "Vital " << sender.getName() << "'s OnCurrentValueChange event triggered" << std::endl;
    }
}
