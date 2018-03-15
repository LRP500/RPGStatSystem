//
// Created by Pierre Roy on 09/03/18.
//

#ifndef RPGSTATSYSTEM_BROADCASTER_HPP
#define RPGSTATSYSTEM_BROADCASTER_HPP

#include <iostream>
#include <vector>

using token = std::shared_ptr<void>;

namespace System
{
    template<class...Ts>
    struct Broadcaster
    {
    public:
        using listen = std::function<void(Ts...)>;
        using sp_listen = std::shared_ptr<listen>;
        using wp_listen = std::weak_ptr<listen>;

        token attach(listen l)
        {
            return attach(std::make_shared<listen>(std::move(l)));
        }

        token attach(sp_listen sp)
        {
            listeners.push_back(sp);
            return sp;
        }

        void operator()(Ts...ts) const
        {
            listeners.erase(std::remove_if(begin(listeners), end(listeners),
                                           [](auto &&wp) { return !(bool) wp.lock(); }),
                            end(listeners));
            auto tmp = listeners;
            for (auto &&l : tmp)
            {
                if (auto pf = l.lock())
                {
                    (*pf)(ts...);
                }
            }
        }

    private:
        mutable std::vector<wp_listen> listeners;

    };
}

#endif //RPGSTATSYSTEM_BROADCASTER_HPP
