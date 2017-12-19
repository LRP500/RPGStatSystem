//
// Created by Pierre Roy on 19/12/17.
//

#ifndef RPGSTATSYSTEM_RPGSTATMODBASEADD_HPP
#define RPGSTATSYSTEM_RPGSTATMODBASEADD_HPP

#include "../RPGStatModifier.hpp"

namespace RPGStatSystem
{
    class RPGStatModBaseAdd : public RPGStatModifier {
    public:
        explicit RPGStatModBaseAdd(float value = 0, bool stack = true);

        int getOrder() const override;
        int applyModifier(int statValue, float modValue) override;

    };

}

#endif //RPGSTATSYSTEM_RPGSTATMODBASEADD_HPP
