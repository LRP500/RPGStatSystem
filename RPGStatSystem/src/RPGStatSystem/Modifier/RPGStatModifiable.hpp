//
// Created by Pierre Roy on 28/11/17.
//

#ifndef RPGSTATSYSTEM_RPGSTATMODIFIABLE_HPP
#define RPGSTATSYSTEM_RPGSTATMODIFIABLE_HPP

#include <list>

#include "../Stat/RPGStat.hpp"
#include "../Interface/IStatModifiable.hpp"
#include "../Interface/IStatValueEvent.hpp"
#include "../Event/EventHandler.hpp"

namespace RPGStatSystem
{

    class RPGStatModifiable: public RPGStat, public IStatModifiable, public IStatValueEvent {
    private:
        System::EventHandler* m_eventHandler;
        std::list<RPGStatSystem::RPGStatModifier> m_mods;
        int m_modValue;

    public:
        RPGStatModifiable();

        int getValue() const override { return RPGStat::getValue() + m_modValue; }
        int getModifierValue() const override { return m_modValue; }

        // Interface Overrides
        void addModifier(const RPGStatModifier& mod) override;
        void clearModifiers() override;
        void updateModifiers() override;

        System::EventHandler* getEventHandler() const;
        void triggerValueChange();
    };

}


#endif //RPGSTATSYSTEM_RPGSTATMODIFIABLE_HPP
