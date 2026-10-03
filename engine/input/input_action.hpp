#pragma once

#include "engine/input/input_keys.hpp"

#include <zen/math/vec2.hpp>
#include <zen/log/core.hpp>

#include <array>
#include <cstdint>

namespace dull::input {

    union InputValue final {
    private:
        bool      _button { false };
        float     _axis1D;
        zen::vec2 _axis2D;

    public:
        constexpr InputValue() noexcept = default;
        constexpr InputValue(bool      value) noexcept : _button { value } {}
        constexpr InputValue(float     value) noexcept : _axis1D { value } {}
        constexpr InputValue(zen::vec2 value) noexcept : _axis2D { value } {}
    };

    enum class InputType   : uint8_t { Button, Axis1D, Axis2D, };
    enum class InputState  : uint8_t { Waiting, Pressed, Held, Released, };
    enum class InputDevice : uint8_t { Keyboard, Mouse, Gamepad, };

    struct InputCode {
    private:
        InputDevice _device { InputDevice::Keyboard };
        int32_t     _code   { 0 };

    public:
        constexpr InputCode() noexcept = default;

        constexpr InputCode(KeyboardCode code) noexcept
            : _device { InputDevice::Keyboard }, _code { static_cast<int32_t>(code) } {}

        constexpr InputCode(MouseCode code) noexcept
            : _device { InputDevice::Mouse }, _code { static_cast<int32_t>(code) } {}

        constexpr InputCode(GamepadCode code) noexcept
            : _device { InputDevice::Gamepad }, _code { static_cast<int32_t>(code) } {}
    };

    #pragma warning "TODO: Implement EventSystem logic to dispatch events."
    struct InputAction final {
    private:
        static constexpr size_t MAX_BINDINGS { 3 };

        InputType  _type  { InputType::Button };
        InputState _state { InputState::Waiting };
        InputValue _value { false };
        std::array<InputCode, MAX_BINDINGS> _bindings;

    public:
        explicit InputAction(InputType type) noexcept : _type { type } {}

        [[nodiscard]] constexpr InputType  GetType()  const noexcept { return this->_type; }
        [[nodiscard]] constexpr InputState GetState() const noexcept { return this->_state; }
    };

} // namespace dull::input
