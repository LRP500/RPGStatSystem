//
// Created by Pierre Roy on 28/11/17.
//

#ifndef RPGSTATSYSTEM_RPGDEFAULTCOLLECTION_HPP
#define RPGSTATSYSTEM_RPGDEFAULTCOLLECTION_HPP

#include "../RPGStatCollection.hpp"

namespace RPGStatSystem {

    class RPGDefaultCollection : public RPGStatCollection {
    public:
        RPGDefaultCollection();

    private:
        void configureStats() override;
    };

}

#endif //RPGSTATSYSTEM_RPGDEFAULTCOLLECTION_HPP
