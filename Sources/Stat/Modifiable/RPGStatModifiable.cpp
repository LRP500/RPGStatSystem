//
// Created by Pierre Roy on 28/11/17.
//

#include "RPGStatModifiable.hpp"
#include "../../System/optimized_inserter.h"

//using std::min;

RPGStatSystem::RPGStatModifiable::RPGStatModifiable() : RPGStat(), m_modValue{0}
{}

void RPGStatSystem::RPGStatModifiable::addModifier(RPGStatModifier* mod)
{
    m_mods.emplace_back(mod);
    mod->listenTokens.push_back(mod->OnValueChange.attach([this] (const RPGStatModifier& sender) {
        OnModValueChange(sender);
    }));
}

void RPGStatSystem::RPGStatModifiable::removeModifier(RPGStatModifier* mod)
{
    m_mods.remove(mod);
}

void RPGStatSystem::RPGStatModifiable::clearModifiers()
{
    m_mods.clear();
}

void RPGStatSystem::RPGStatModifiable::updateModifiers()
{
    float sum, max;
    m_modValue = 0;
    std::unordered_map<int, std::vector<RPGStatSystem::RPGStatModifier*>> groupOrder;
    m_mods.sort([](const RPGStatModifier* lhs, const RPGStatModifier* rhs) { return lhs->getOrder() < rhs->getOrder(); });
    std::for_each(m_mods.begin(), m_mods.end(), System::optimized_inserter<RPGStatModifier*>(groupOrder));

    for (auto& group : groupOrder) {
        sum = max = 0;
        for (auto& mod : group.second) {
            if (!mod->stacks()) {
                if(mod->getValue() > max) {
                    max = mod->getValue();
                }
            } else {
                sum += mod->getValue();
            }
        }
        m_modValue += group.second[0]->applyModifier(getBaseValue() + getModifierValue(), sum > max ? sum : max);
    }
    triggerValueChange();
}

// Broadcast changes to linker (linker will notify slave stat)
void RPGStatSystem::RPGStatModifiable::triggerValueChange()
{
    if (!listenTokens.empty())
        OnValueChange(*this);
}

// Callback triggered by modifiers & linkers when recalculating is needed
void RPGStatSystem::RPGStatModifiable::OnModValueChange(const RPGStatSystem::RPGStatModifier& sender)
{
    updateModifiers();
}
