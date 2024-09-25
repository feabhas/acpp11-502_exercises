// Pipe.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Pipe.h"

bool Pipe::push(value_type&& alarm)
{
    return buffer.add(std::move(alarm));
}

auto Pipe::pull() -> std::optional<value_type> 
{
    std::unique_ptr<Alarm> alarm{};
    if (buffer.get(alarm)) {
        return alarm;
    }
    return std::nullopt;
}

bool Pipe::is_empty() const
{
    return buffer.is_empty();
}
