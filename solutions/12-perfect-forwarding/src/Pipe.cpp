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
    return buffer.get();
}

bool Pipe::is_empty() const
{
    return buffer.is_empty();
}
