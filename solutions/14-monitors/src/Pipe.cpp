// Pipe.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Pipe.h"

void Pipe::push(value_type&& alarm)
{
    buffer.add(std::move(alarm));
}

auto Pipe::pull() -> value_type
{
    return buffer.get();
}

bool Pipe::is_empty() const
{
    return buffer.is_empty();
}
