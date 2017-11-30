//
// Created by Pierre Roy on 28/11/17.
//

#ifndef RPGSTATSYSTEM_RPGSTAT_HPP
#define RPGSTATSYSTEM_RPGSTAT_HPP

#include <string>

namespace RPGStatSystem {

    class RPGStat {
    public:
        enum Type {
            None = 0,
            Health = 1,
            Strength = 2,
            Agility = 3,
            Stamina = 4,
            Intelligence = 5,
            Mana = 6,
            Count = Mana
        };

    protected:
        std::string m_name;
        int m_baseValue;

    public:
        RPGStat();
        virtual ~RPGStat() = default;

    public:
        const std::string& getName() const { return m_name; }
        void setName(const std::string& name) { m_name = name; }
        virtual int getValue() const { return m_baseValue; }
        virtual int getBaseValue() const { return m_baseValue; }
        void setValue(int value) { m_baseValue = value; }
    };

    auto const STAT_TYPE_COUNT = RPGStat::Type::Count;
    static const RPGStat::Type Stats[STAT_TYPE_COUNT] = {
            RPGStat::Type::Health,
            RPGStat::Type::Strength,
            RPGStat::Type::Agility,
            RPGStat::Type::Stamina,
            RPGStat::Type::Intelligence,
            RPGStat::Type::Mana
    };

}

#endif //RPGSTATSYSTEM_RPGSTAT_HPP
