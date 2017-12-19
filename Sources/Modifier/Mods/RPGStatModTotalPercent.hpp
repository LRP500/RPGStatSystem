//
// Created by Pierre Roy on 19/12/17.
//

#ifndef RPGSTATSYSTEM_RPGSTATMODTOTALPERCENT_HPP
#define RPGSTATSYSTEM_RPGSTATMODTOTALPERCENT_HPP

#include "../RPGStatModifier.hpp"

namespace RPGStatSystem
{
    class RPGStatModTotalPercent : public RPGStatModifier {
    public:
        explicit RPGStatModTotalPercent(float value = 0, bool stack = true);

        int getOrder() const override;
        int applyModifier(int statValue, float modValue) override;

    };

}


#endif //RPGSTATSYSTEM_RPGSTATMODTOTALPERCENT_HPP
