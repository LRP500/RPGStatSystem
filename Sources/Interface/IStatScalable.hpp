//
// Created by Pierre Roy on 29/11/17.
//

#ifndef RPGSTATSYSTEM_ISTATSCALABLE_HPP
#define RPGSTATSYSTEM_ISTATSCALABLE_HPP

namespace RPGStatSystem
{

    class IStatScalable {
    private:
        virtual void scaleToLevel(int level) = 0;
    };

}

#endif //RPGSTATSYSTEM_ISTATSCALABLE_HPP
