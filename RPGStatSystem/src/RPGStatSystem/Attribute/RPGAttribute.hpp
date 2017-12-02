//
// Created by Pierre Roy on 29/11/17.
//

#ifndef RPGSTATSYSTEM_RPGATTRIBUTE_HPP
#define RPGSTATSYSTEM_RPGATTRIBUTE_HPP

#include <list>

#include "../Interface/IStatScalable.hpp"
#include "../Interface/IStatLinkable.hpp"
#include "../Modifier/RPGStatModifiable.hpp"

namespace RPGStatSystem {

    class RPGAttribute : public RPGStatModifiable, public IStatScalable, public IStatLinkable {
    private:
        int m_levelValue {};
        int m_linkerValue {};
        std::list<RPGStatLinker*> m_linkers;

    public:
        RPGAttribute();

        int getlevelValue() const { return m_levelValue; }

        // Base RPGStat Overrides
        int getBaseValue() const override;

        // Interface IStatScalabler Overrides
        void scaleToLevel(int level) override;

        // Interface IStatLinkable Overrides
        void addLinker(RPGStatLinker* linker) override;
        void clearLinkers() override;
        void updateLinkers() override;

        void removeLinker(RPGStatLinker* linker);
        void addLiner(RPGStatLinker* linker);

        int getLinkerValue() const { return m_linkerValue; }
        int getLinkerValue() override // Effective C++ style const/non-const getter
        {
            RPGStatModifiable::updateModifiers();
            return const_cast<const RPGAttribute*>(this)->getLinkerValue();
        }
    };

}

#endif //RPGSTATSYSTEM_RPGATTRIBUTE_HPP
