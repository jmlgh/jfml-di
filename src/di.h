//
// Created by jml on 1/6/25.
//

#pragma once

#include <stdexcept>
#include <unordered_map>
#include <memory>
#include <typeindex>
#include <functional>

class DependencyContainer {
public:
    // Register a type T and its constructor with the given args
    template <typename T, typename... Args>
    void registerType() {
        // typeid - retrieves a unique runtime identifier for type T
        registry[typeid(T)] = []() -> std::shared_ptr<void> {
            return std::make_shared<T>();
        };
    }

    // Resolves a registered type and returns an instance
    template <typename T>
    std::shared_ptr<T> resolve() {
        auto it = registry.find(typeid(T));
        if (it == registry.end()) {
            throw std::runtime_error("Type not registered.");
        }
        // Call the constructor and cast the result to the desired type
        return std::static_pointer_cast<T>(it->second());
    }
private:
    // Maps a type's unique runtime identifier (std::type_index) to a constructor (stgit push -u origin maind::function)
    std::unordered_map<std::type_index, std::function<std::shared_ptr<void>()>> registry;
};