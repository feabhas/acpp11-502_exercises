// Pipe.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Pipe.h"

bool Pipe::push(Alarm const& alarm)
{
    return buffer.add(alarm);
}

std::optional<Alarm> Pipe::pull()
{
    Alarm alarm{};
    if (buffer.get(alarm)) {
        return alarm;
    }
    return std::nullopt;
}

bool Pipe::is_empty() const
{
    return buffer.is_empty();
}
