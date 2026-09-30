#pragma once

#include <zen/math/vec2.hpp>

#include <string>
#include <unordered_map>

namespace dull::input {

    struct InputAction final {};

    using InputActionMap = std::unordered_map<std::string, InputAction>;

    struct InputMap final {
    private:
        std::string    _name;
        InputActionMap _actionMap;

    public:

    };

} // namespace dull::input
