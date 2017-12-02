//
// Created by Pierre Roy on 28/11/17.
//

#ifndef RPGSTATSYSTEM_RPGDEFAULTCOLLECTION_HPP
#define RPGSTATSYSTEM_RPGDEFAULTCOLLECTION_HPP

#include "../RPGStatCollection.hpp"

#include "../../Event/EventHandler.hpp" // TODO Delete

namespace RPGStatSystem {

    class RPGDefaultCollection : public RPGStatCollection {
    private:
        Signal::EventHandler m_eh;

    public:
        RPGDefaultCollection();

    private:
        void configureStats() override;

    };

}

#endif //RPGSTATSYSTEM_RPGDEFAULTCOLLECTION_HPP
