// Pipe.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Pipe.h"

bool Pipe::push(value_type alarm)
{
    return buffer.add(std::move(alarm));
}

Pipe::value_type Pipe::pull()
{
    value_type alarm;
    if (buffer.get(alarm)) {
        return alarm;
    }
    return nullptr;
}

bool Pipe::is_empty() const
{
    return buffer.is_empty();
}
