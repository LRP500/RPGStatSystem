//
// Created by Pierre Roy on 28/11/17.
//

#ifndef RPGSTATSYSTEM_RPGSTATMODIFIABLE_HPP
#define RPGSTATSYSTEM_RPGSTATMODIFIABLE_HPP

#include <list>

#include "../RPGStat.hpp"
#include "../../Interface/IStatModifiable.hpp"
#include "../../Interface/IStatValueChange.hpp"

namespace RPGStatSystem
{
    class RPGStatModifiable: public RPGStat, public IStatModifiable, public IStatValueChange {
    private:
        std::list<RPGStatSystem::RPGStatModifier*> m_mods;
        int m_modValue;

    public:
        RPGStatModifiable();

        int getValue() const override { return RPGStat::getValue() + m_modValue; }
        int getModifierValue() const override { return m_modValue; }

        // Interface Overrides
        void addModifier(RPGStatModifier* mod) override;
        void removeModifier(RPGStatModifier* mod) override;
        void clearModifiers() override;
        void updateModifiers() override;

        void triggerValueChange();

        // Implement IStatValueChange Interface
        void OnModValueChange(const RPGStatModifier& sender);
    };

}


#endif //RPGSTATSYSTEM_RPGSTATMODIFIABLE_HPP
