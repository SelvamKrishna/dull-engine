#pragma once

#include <cstdint>

namespace dull::input {

enum class KeyboardCode : int32_t {
    Unknown = 0,

    A, B, C, D, E, F, G, H, I, J, K, L, M,
    N, O, P, Q, R, S, T, U, V, W, X, Y, Z,

    Num0, Num1, Num2, Num3, Num4, Num5, Num6, Num7, Num8, Num9,

    F1 , F2 , F3 , F4 , F5 , F6 , F7 , F8 , F9 , F10, F11, F12,
    F13, F14, F15, F16, F17, F18, F19, F20, F21, F22, F23, F24,

    Escape, Enter, Tab, Backspace, Space, Delete, Insert,
    Home, End, PageUp, PageDown,

    Left, Right, Up, Down,

    LeftShift, RightShift,
    LeftCtrl , RightCtrl,
    LeftAlt  , RightAlt,
    LeftSuper, RightSuper,

    CapsLock, NumLock, ScrollLock,

    Minus,
    Equal,
    LeftBracket,
    RightBracket,
    Backslash,
    Semicolon,
    Apostrophe,
    Grave,
    Comma,
    Period,
    Slash,

    NumPad0, NumPad1, NumPad2, NumPad3, NumPad4,
    NumPad5, NumPad6, NumPad7, NumPad8, NumPad9,

    NumPadDecimal, NumPadDivide, NumPadMultiply,
    NumPadSubtract, NumPadAdd, NumPadEnter,
    NumPadEqual,

    PrintScreen, Pause, Menu,
    VolumeUp, VolumeDown, VolumeMute,
    MediaNext, MediaPrev, MediaStop, MediaPlay,
};

enum class MouseCode : int32_t {
    Unknown = 0,

    Left, Right, Middle,
    X1, X2,
    WheelUp, WheelDown,
};

enum class GamepadCode : int32_t {
    Unknown = 0,

    A, B, X, Y,
    LeftBumper, RightBumper,
    Back, Start,
    Guide,
    LeftThumb, RightThumb,
    DPadUp, DPadRight, DPadDown, DPadLeft,
};

} // namespace dull::input
