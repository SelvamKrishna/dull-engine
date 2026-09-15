#include "engine/render/draw_handle.hpp"
#include "engine/util/adapter.hpp"

#include <zen/log.hpp>
#include <zen/math/vec2.hpp>

#include <vendor/raylib.h>

namespace dull::render {

    DrawHandle::DrawHandle(IRenderer& refRenderer) : _refRenderer {refRenderer}
    { rl::BeginDrawing(); rl::ClearBackground(color::BLACK); }

    DrawHandle::~DrawHandle() { rl::EndDrawing(); }

    void DrawHandle::DrawRectangle(
        const util::Rect& rectangle,
        const util::Transform2D& transform,
        const ShapeContext& ctxShape
    ) const {
        util::Rect rectangleModified {rectangle};
        rectangleModified.Move(transform.position);
        rectangleModified.Scale(transform.scale);

        rl::DrawRectanglePro(
            rectangleModified,
            rl_cast(rectangleModified.GetDimension() * 0.5f),
            transform.rotation.as_deg(),
            ctxShape.fillColor
        );

        if (ctxShape.HasOutline()) rl::DrawRectangleLinesEx(
            rectangleModified, ctxShape.outlineThinkness, ctxShape.outlineColor
        );
    }

    void DrawHandle::DrawCircle(
        const util::Transform2D& transform,
        const ShapeContext& ctxShape
    ) const
    {
        if (ctxShape.HasOutline()) rl::DrawCircleV(
            rl_cast(transform.position),
            transform.GetScaleUnit() + ctxShape.outlineThinkness,
            ctxShape.outlineColor
        );

        rl::DrawCircleV(rl_cast(transform.position), transform.GetScaleUnit(), ctxShape.fillColor);
    }

    void DrawHandle::DrawLine(
        const zen::vec2& pointA,
        const zen::vec2& pointB,
        const ShapeContext& ctxShape
    ) const
    {
        rl::DrawLineEx(
            rl_cast(pointA), rl_cast(pointB),
            ctxShape.outlineThinkness, ctxShape.fillColor
        );
    }

    void DrawHandle::DrawText(std::string_view text, const util::Transform2D& transform, const TextContext& ctxText) const
    {
        thread_local std::string buffer {text};
        buffer.assign(text.data(), text.size());

        rl::DrawTextPro(
            ctxText.font,
            buffer.c_str(),
            rl_cast(transform.position),
            rl_cast(ctxText.origin),
            transform.rotation.as_rad(),
            transform.GetScaleUnit(),
            ctxText.spacing,
            ctxText.fillColor
        );
    }

    void DrawHandle::DrawFPS(int posX, int posY) const { rl::DrawFPS(posX, posY); }

} // namespace dull::render
