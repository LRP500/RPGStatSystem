//
// Created by Pierre Roy on 28/11/17.
//

#include "RPGStatModifiable.hpp"
#include "../../System/optimized_inserter.h"

using std::min;

RPGStatSystem::RPGStatModifiable::RPGStatModifiable()
        : RPGStat(), m_modValue{0}, LOnModValueChange(this)
{}

void RPGStatSystem::RPGStatModifiable::addModifier(RPGStatModifier* mod)
{
    m_mods.emplace_back(mod);
    mod->OnValueChange += &LOnModValueChange;
}

void RPGStatSystem::RPGStatModifiable::removeModifier(RPGStatModifier* mod)
{
    mod->OnValueChange -= &LOnModValueChange;
    m_mods.remove(mod);
}

void RPGStatSystem::RPGStatModifiable::clearModifiers()
{
    for (auto& mod : m_mods)
    {
        mod->OnValueChange -= &LOnModValueChange;
    }
    m_mods.clear();
}

void RPGStatSystem::RPGStatModifiable::updateModifiers()
{
    float sum, max;
    m_modValue = 0;
    std::unordered_map<int, std::vector<RPGStatSystem::RPGStatModifier*>> groupOrder;
    m_mods.sort([](const RPGStatModifier* lhs, const RPGStatModifier* rhs) { return lhs->getOrder() < rhs->getOrder(); });
    std::for_each(m_mods.begin(), m_mods.end(), System::optimized_inserter<RPGStatModifier*>(groupOrder));

    for (auto& group : groupOrder)
    {
        sum = max = 0;
        for (auto& mod : group.second)
        {
            if (!mod->stacks())
            {
                if(mod->getValue() > max)
                {
                    max = mod->getValue();
                }
            }
            else
            {
                sum += mod->getValue();
            }
        }
        m_modValue += group.second[0]->applyModifier(getBaseValue() + getModifierValue(), sum > max ? sum : max);
    }

    triggerValueChange();
}

void RPGStatSystem::RPGStatModifiable::triggerValueChange()
{
    // TODO check if event registered to delegate
    OnValueChange(*this);
}

void RPGStatSystem::RPGStatModifiable::OnModValueChange(const RPGStatSystem::RPGStatModifier& sender)
{
    updateModifiers();
}
