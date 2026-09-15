#pragma once

// Forward Declaration
namespace dull::core { struct Engine; }
namespace dull::draw { struct DrawHandle; }

namespace dull::draw {

    struct IRenderer {
        friend core::Engine;

    public:
        virtual ~IRenderer() = default;

    protected:
        virtual void IInit() {}
        virtual void IDraw(const DrawHandle&) {}
        virtual void IShutdown() {}
    };

} // namespace dull::draw
