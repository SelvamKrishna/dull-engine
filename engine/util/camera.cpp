#include "engine/util/camera.hpp"

namespace dull::util {

    zen::vec2 Camera2D::GetWorldToScreen(zen::vec2 position) const noexcept
    {
        return rl_cast(rl::GetWorldToScreen2D(rl_cast(position), *this));
    }

    zen::vec2 Camera2D::GetScreenToWorld(zen::vec2 position) const noexcept
    {
        return rl_cast(rl::GetScreenToWorld2D(rl_cast(position), *this));
    }

    Rect Camera2D::GetScreenRect() const noexcept
    {
        const float ZOOM {(this->zoom > 0.0f) ? this->zoom : 1.0f};

        return Rect {
            this->target.x - this->offset.x / ZOOM,
            this->target.y - this->offset.y / ZOOM,
            rl::GetScreenWidth() / ZOOM,
            rl::GetScreenHeight() / ZOOM
        };
    }

} // namespace dull::util
