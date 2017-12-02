//
// Created by Pierre Roy on 02/12/17.
//

#include <iostream>

#include "EventHandler.hpp"
#include "../Vital/RPGVital.hpp"

System::EventHandler::EventHandler() : LOnCurrentValueChange(this)
{}

void System::EventHandler::OnCurrentValueChange(const RPGStatSystem::RPGVital& sender)
{
    if (&sender)
    {
        std::cout << "Vital " << sender.getName() << "'s OnCurrentValueChange event triggered" << std::endl;
    }
}
