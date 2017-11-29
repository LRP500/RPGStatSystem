//
// Created by Pierre Roy on 28/11/17.
//

#ifndef RPGSTATSYSTEM_RPGSTATCOLLECTION_HPP
#define RPGSTATSYSTEM_RPGSTATCOLLECTION_HPP

#include <unordered_map>

#include "RPGStat.hpp"

namespace RPGStatSystem {

    class RPGStatCollection {
    private:
        std::unordered_map<RPGStat::Type, RPGStat*> m_stats;

    public:
        RPGStatCollection();
        virtual ~RPGStatCollection() = default;

        bool contains(RPGStat::Type type) const;

        virtual void configureStats();

        template <typename T>
        T* getStat(RPGStat::Type type);

        template <typename T>
        T* createStat(RPGStat::Type type);

        template <typename T>
        T* getOrCreate(RPGStat::Type type);
    };

}

#endif //RPGSTATSYSTEM_RPGSTATCOLLECTION_HPP
