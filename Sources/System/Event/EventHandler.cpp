//
// Created by Pierre Roy on 02/12/17.
//

#include <iostream>

#include "EventHandler.hpp"
#include "../../Stat/Vital/RPGVital.hpp"

System::EventHandler::EventHandler()
        : LOnCurrentValueChange(this),
          LOnLinkedStatValueChange(this),
          LOnLinkerValueChange(this),
          LOnModifierValueChange(this)
{}

void System::EventHandler::OnCurrentValueChange(const RPGStatSystem::RPGVital& sender)
{
    if (&sender)
    {
        std::cout << "Vital " << sender.getName() << "'s OnCurrentValueChange event triggered" << std::endl;
    }
}

void System::EventHandler::OnLinkedStatValueChange(const RPGStatSystem::RPGStat& sender)
{
    if (&sender)
    {
        std::cout << sender.getName() << "'s OnLinkedStatValueChange event triggered" << std::endl;
    }
}

void System::EventHandler::OnLinkerValueChange(const RPGStatSystem::RPGStat& sender)
{
    dynamic_cast<RPGStatSystem::RPGAttribute&>(const_cast<RPGStatSystem::RPGStat&>(sender)).updateLinkers();
}

void System::EventHandler::OnModifierValueChange(const RPGStatSystem::RPGStatModifier& sender)
{
    if (&sender)
    {
        //const_cast<RPGStatSystem::RPGStatModifiable>(sender).updateModifiers();
    }
}
