//
// Created by Pierre Roy on 02/12/17.
//

#ifndef EVENTHANDLER_EVENT_HPP
#define EVENTHANDLER_EVENT_HPP

#include <vector>
#include <algorithm>

#include "Delegate.hpp"

namespace Signal
{

    template <typename T>
    class Event {
    private:
        std::vector<Signal::Delegate<T>*> m_delegates;

    public:
        void operator+=(Delegate<T>* delegate);
        void operator-=(Delegate<T>* delegate);
        void operator()(T param);

    };

    // Operator Overload Definitions

    // C# Style Register Event
    template<typename T>
    void Event<T>::operator+=(Delegate<T> *delegate)
    {
        if (std::find(m_delegates.begin(), m_delegates.end(), delegate) == m_delegates.end())
        {
            m_delegates.emplace_back(delegate);
        }
    }

    // C# Style Unregister Event
    template<typename T>
    void Event<T>::operator-=(Delegate<T> *delegate)
    {
        typedef typename std::vector<Delegate<T>*>::iterator iter;
        iter i = m_delegates.begin();
        while (i != m_delegates.end())
        {
            if (*i == delegate)
            {
                i = m_delegates.erase(i);
            }
            else
            {
                ++i;
            }
        }
    }

    template<typename T>
    void Event<T>::operator()(T param)
    {
        typedef typename std::vector<Delegate<T>*>::iterator iter;
        for (iter i = m_delegates.begin(); i != m_delegates.end(); ++i)
        {
            (*i)->operator()(param);
        }
    }

}

#endif //EVENTHANDLER_EVENT_HPP
