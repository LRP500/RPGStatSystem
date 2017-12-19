//
// Created by Pierre Roy on 19/12/17.
//

#ifndef RPGSTATSYSTEM_RPGSTATMODBASEPERCENT_HPP
#define RPGSTATSYSTEM_RPGSTATMODBASEPERCENT_HPP

#include "../RPGStatModifier.hpp"

namespace RPGStatSystem
{
    class RPGStatModBasePercent : public RPGStatModifier {
    public:
        explicit RPGStatModBasePercent(float value = 0, bool stack = true);

        int getOrder() const override;
        int applyModifier(int statValue, float modValue) override;
    };

}


#endif //RPGSTATSYSTEM_RPGSTATMODBASEPERCENT_HPP
