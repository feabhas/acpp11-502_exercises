// Pipe.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Pipe.h"

bool Pipe::push(std::unique_ptr<Alarm> alarm)
{
    return buffer.add(std::move(alarm));
}

std::unique_ptr<Alarm>  Pipe::pull()
{
    std::unique_ptr<Alarm> alarm{};
    if (buffer.get(alarm)) {
        return alarm;
    }
    return nullptr;
}

bool Pipe::is_empty() const
{
    return buffer.is_empty();
}
