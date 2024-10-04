// Pipe.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Pipe.h"

void Pipe::push(value_type&& alarm)
{
    {
        // std::unique_lock<std::mutex> lock{ mtx };  // C++14
        std::unique_lock lock{mtx};                   // C++17
        while (!buffer.add(std::move(alarm))) {
            has_space.wait(lock);
        }
    }
    has_data.notify_one();
}

auto Pipe::pull() -> value_type
{
    std::optional<value_type> alarm{};
    {
        // std::unique_lock<std::mutex> lock{ mtx };  // C++14
        std::unique_lock lock{mtx};                   // C++17
        while (!(alarm = std::move(buffer.get()))) {
            has_data.wait(lock);
        }
        has_space.notify_one();
    }
    return std::move(alarm.value());
}

bool Pipe::is_empty() const
{
    return buffer.is_empty();
}
