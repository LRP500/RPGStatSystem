//
// Created by Pierre Roy on 19/12/17.
//

#ifndef RPGSTATSYSTEM_OPTIMIZED_INSERTER_H
#define RPGSTATSYSTEM_OPTIMIZED_INSERTER_H

#include <vector>
#include <unordered_map>

namespace System
{
    template <typename T>
    class optimized_inserter {
    public:
        typedef std::unordered_map<int, std::vector<T>> map_type;

        explicit optimized_inserter(map_type & map) : map(&map), it(map.end()) {}

        void operator()(const T& obj);

    private:
        map_type          *map;
        typename  map_type::iterator it;
        int                last_order;
    };

    template<typename T>
    void optimized_inserter<T>::operator()(const T &obj)
    {
        typedef typename map_type::value_type value_type;
        if (it != map->end() && last_order == obj->getOrder())
        {
            it->second.push_back(obj);
            return;
        }
        last_order = obj->getOrder();
        it = map->insert(value_type(obj->getOrder(), std::vector<T>({obj}))).first;
    }

}

#endif //RPGSTATSYSTEM_OPTIMIZED_INSERTER_H
