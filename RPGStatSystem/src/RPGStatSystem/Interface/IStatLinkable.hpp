//
// Created by Pierre Roy on 29/11/17.
//

#ifndef RPGSTATSYSTEM_ISTATLINKABLE_HPP
#define RPGSTATSYSTEM_ISTATLINKABLE_HPP

#include "../Linker/RPGStatLinker.hpp"

namespace RPGStatSystem {

    class IStatLinkable {
    private:
        virtual void addLinker(RPGStatLinker* linker) = 0;
        virtual void clearLinkers() = 0;
        virtual void updateLinkers() = 0;
        virtual int getLinkerValue() = 0;
    };
}

#endif //RPGSTATSYSTEM_ISTATLINKABLE_HPP
