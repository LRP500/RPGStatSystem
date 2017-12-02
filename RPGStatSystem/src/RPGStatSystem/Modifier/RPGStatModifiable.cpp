//
// Created by Pierre Roy on 28/11/17.
//

#include "RPGStatModifiable.hpp"

RPGStatSystem::RPGStatModifiable::RPGStatModifiable()
        : RPGStat(), m_modValue(0)
{}

void RPGStatSystem::RPGStatModifiable::addModifier(const RPGStatModifier& mod)
{
    m_mods.emplace_back(mod);
}

void RPGStatSystem::RPGStatModifiable::clearModifiers()
{
    m_mods.clear();
}

void RPGStatSystem::RPGStatModifiable::updateModifiers()
{
    m_modValue = 0;
    float modBaseValueAdd = 0;
    float modBaseValuePercent = 0;
    float modTotalValueAdd = 0;
    float modTotalValuePercent = 0;

    for (const auto& mod : m_mods)
    {
        switch (mod.getModifierType())
        {
            case RPGStatModifier::None: break;
            case RPGStatModifier::BaseValueAdd:
                modBaseValueAdd += mod.getValue();
                break;
            case RPGStatModifier::BaseValuePercent:
                modBaseValuePercent += mod.getValue();
                break;
            case RPGStatModifier::TotalValueAdd:
                modTotalValueAdd += mod.getValue();
                break;
            case RPGStatModifier::TotalValuePercent:
                modTotalValuePercent += mod.getValue();
                break;
        }
    }
    m_modValue = static_cast<int>((getBaseValue() * modBaseValuePercent) + modBaseValueAdd);
    m_modValue += (getValue() * modTotalValuePercent) + modTotalValueAdd;
    triggerValueChange();
}

System::EventHandler* RPGStatSystem::RPGStatModifiable::getEventHandler() const
{
    return m_eventHandler;
}

void RPGStatSystem::RPGStatModifiable::triggerValueChange()
{
    // TODO check if event register to delegate
    OnValueChange(*this);
}
