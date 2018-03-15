//
// Created by Pierre Roy on 28/11/17.
//

#ifndef RPGSTATSYSTEM_RPGSTATMODIFIER_HPP
#define RPGSTATSYSTEM_RPGSTATMODIFIER_HPP

#include "../System/Broadcaster.hpp"

namespace RPGStatSystem {

    class RPGStatModifier {
    public:
        // EVENT BROADCAST
        System::Broadcaster<const RPGStatModifier&> OnValueChange;
        std::vector<token> listenTokens;

    protected:
        // MEMBER VARS
        float m_value;
        bool m_stacks;
        int m_order;

    public:
        // CTORS & DTORS
        explicit RPGStatModifier(float value, bool stacks);
        ~RPGStatModifier() = default;

    public:
        // METHODS
        bool stacks() const { return m_stacks; }
        float getValue() const { return m_value; }
        void setValue(float value);
        void triggerValueChange();

        virtual int getOrder() const = 0;
        virtual int applyModifier(int statValue, float modValue) = 0;
    };

}

#endif //RPGSTATSYSTEM_RPGSTATMODIFIER_HPP
