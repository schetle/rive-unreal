#ifndef _RIVE_DRAWABLE_FLAGS_HPP_
#define _RIVE_DRAWABLE_FLAGS_HPP_

#include "rive/enum_bitset.hpp"

namespace rive
{
enum class DrawableFlag : unsigned short
{
    None = 0,

    /// Whether the component should be drawn
    Hidden = 1 << 0,

    /// Editor only
    Locked = 1 << 1,

    /// Editor only
    Disconnected = 1 << 2,

    /// Whether this Component lets hit events pass through to components behind it
    Opaque = 1 << 3,
};
RIVE_MAKE_ENUM_BITSET(DrawableFlag)
} // namespace rive
#endif
