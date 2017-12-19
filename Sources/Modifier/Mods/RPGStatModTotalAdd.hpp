//
// Created by Pierre Roy on 19/12/17.
//

#ifndef RPGSTATSYSTEM_RPGSTATMODTOTALADD_HPP
#define RPGSTATSYSTEM_RPGSTATMODTOTALADD_HPP

#include "../RPGStatModifier.hpp"

namespace RPGStatSystem
{
    class RPGStatModTotalAdd : public RPGStatModifier {
    public:
        explicit RPGStatModTotalAdd(float value = 0.0, bool stack = true);

        int getOrder() const override;
        int applyModifier(int statValue, float modValue) override;

    };

}

#endif //RPGSTATSYSTEM_RPGSTATMODTOTALADD_HPP
