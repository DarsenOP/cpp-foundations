//
// Created by arsen on 2/8/25.
//

#ifndef OBSERVER_H
#define OBSERVER_H

#include "Event.h"
#include <functional>
#include <typeindex>
#include <unordered_map>
#include <vector>

class Observer
{
    using Callback = std::function<void(const Event&)>;

    std::unordered_map<std::type_index, std::vector<Callback>> map;
public:
    void subscribe(std::type_index evt_type, Callback &&callback)
    {
        map[evt_type].push_back(callback);
    }

    void notify(const Event &evt)
    {
        if (map.find(typeid(evt)) == map.end()) return;

        auto callbacks = map[typeid(evt)];
        for (const auto &callback : callbacks) {
            callback(evt);
        }
    }
};

#endif //OBSERVER_H
