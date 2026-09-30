#pragma once

#include <zen/log.hpp>

#include <cstdint>
#include <format>
#include <string>

namespace dull::config {

    struct Version final {
    public:
        uint8_t major; uint8_t minor;

        bool operator==(Version other) const noexcept
        {
            return this->major == other.major && this->minor == other.minor;
        }

        friend constexpr std::strong_ordering operator<=>(const Version& self, const Version& other) noexcept
        {
            const std::strong_ordering CMP = self.major <=> other.major;
            return (CMP != 0) ? CMP : (self.minor <=> other.minor);
        }
    };

    inline constexpr Version  VERSION  { 0, 1 };
    inline const zen::log_tag DULL_TAG { "DULL", zen::ansi_color::BLUE };

    [[nodiscard]] inline std::string GetConfigString() noexcept
    {
        return std::format("DullEngine {}.{}", VERSION.major, VERSION.minor);
    }

} // namespace dull::config

template <> struct std::formatter<dull::config::Version> {
    constexpr auto parse(std::format_parse_context& ctx) { return ctx.begin(); }
    auto format(const dull::config::Version& type, std::format_context& ctx) const
    {
        return std::format_to(ctx.out(), "{}.{}", type.major, type.minor);
    }
};
