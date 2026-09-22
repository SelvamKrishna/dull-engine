#pragma once

#include "engine/util/adapter.hpp"
#include "engine/util/rect.hpp"

#include <zen/math/vec2.hpp>
#include <raylib.h>

namespace dull::util {

    struct Camera2D {
        zen::vec2 offset   {0.0f};
        zen::vec2 target   {0.0f};
        float     rotation {0.0f};
        float     zoom     {1.0f};

        Camera2D() noexcept = default;

        Camera2D(zen::vec2 offset, zen::vec2 target, float rotation, float zoom) noexcept
            : offset {offset}, target {target}, rotation {rotation}, zoom {zoom} {}

        Camera2D(const rl::Camera2D& rlCamera) noexcept
            : offset   {rl_cast(rlCamera.offset)}
            , target   {rl_cast(rlCamera.target)}
            , rotation {rlCamera.rotation}
            , zoom     {rlCamera.zoom}
        {}

        operator rl::Camera2D() const noexcept
        {
            return rl::Camera2D {rl_cast(this->offset), rl_cast(this->target), this->rotation, this->zoom};
        }

        [[nodiscard]] zen::vec2 GetWorldToScreen(zen::vec2 position) const noexcept;
        [[nodiscard]] zen::vec2 GetScreenToWorld(zen::vec2 position) const noexcept;
        [[nodiscard]] Rect GetScreenRect() const noexcept;
    };

} // namespace dull::util
