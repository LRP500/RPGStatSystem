//
// Created by Pierre Roy on 28/11/17.
//

#ifndef RPGSTATSYSTEM_ISTATMODIFIABLE_HPP
#define RPGSTATSYSTEM_ISTATMODIFIABLE_HPP

#include "../Modifier/RPGStatModifier.hpp"

namespace RPGStatSystem {

    class IStatModifiable {
    public:
        virtual void addModifier(RPGStatModifier mod) = 0;
        virtual void clearModifiers() = 0;
        virtual void updateModifiers() = 0;
        virtual int getModifierValue() const = 0;
    };

}

#endif //RPGSTATSYSTEM_ISTATMODIFIABLE_HPP
