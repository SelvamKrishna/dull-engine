#pragma once

// Forward Declaration
namespace dull::core { struct Engine; }

namespace dull::core {

    struct TimeSystem final {
        friend core::Engine;

    private:
        double _deltaTime;
        double _deltaTimeUnscaled;
        double _timeScale   {1.0};
        double _accumulator {0.0};
        double _gameTime    {0.0};

        double _fixedTickInterval {1.0 / 30.0}; // 30 FPS

        explicit TimeSystem() = default;
        ~TimeSystem() = default;

        void _Update(double frameTime) noexcept;
        bool _ShouldFixedUpdate() noexcept;
        void _SetTickInterval(double frameTime) noexcept { this->_fixedTickInterval = frameTime; }

    public:
        constexpr TimeSystem(TimeSystem&&)                 noexcept = delete;
        constexpr TimeSystem(const TimeSystem&)            noexcept = delete;
        constexpr TimeSystem& operator=(TimeSystem&&)      noexcept = delete;
        constexpr TimeSystem& operator=(const TimeSystem&) noexcept = delete;

        [[nodiscard]] constexpr double GetDelta() const noexcept { return this->_deltaTime; }
        [[nodiscard]] constexpr double GetUnscaledDelta() const noexcept { return this->_deltaTimeUnscaled; }
        [[nodiscard]] constexpr double GetGameTime() const noexcept { return this->_gameTime; }
        [[nodiscard]] constexpr double GetTimeScale() const noexcept { return this->_timeScale; }

        void SetTimeScale(double scale);
    };

} // namespace dull::core
