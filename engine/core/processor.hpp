#pragma once

// Forward Declaration
namespace dull::util   { struct GlobalAccessor; }
namespace dull::core   { struct Engine; }
namespace dull::render { struct DrawHandle; }

namespace dull::core {

    struct IProcessor {
        friend core::Engine;

    public:
        virtual ~IProcessor() = default;

    protected:
        virtual void IInit() {}
        virtual void IUpdate(const util::GlobalAccessor&) {}
        virtual void IFixedUpdate(const util::GlobalAccessor&) {}
        virtual void IDraw(const render::DrawHandle&) {}
        virtual void IShutdown() {}
    };

} // namespace dull::core
