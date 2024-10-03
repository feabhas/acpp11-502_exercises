// Buffer.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Buffer.h"

Buffer::Buffer(Buffer const& rhs)
{
  for(auto& alarm: rhs.elems) {
    if (alarm) {
      add(std::make_unique<Alarm>(alarm->type()));
    }
  }
}

Buffer& Buffer::operator=(Buffer const& rhs)
{
  Buffer temp{rhs};
  swap(*this, temp);
  return *this;
}

void swap(Buffer& lhs, Buffer& rhs) {
  using std::swap;
  // swap all member variables
  swap(lhs.elems, rhs.elems);
  swap(lhs.num_elems, rhs.num_elems);
  auto rhs_read = std::distance(rhs.read_pos, std::begin(rhs.elems));
  rhs.read_pos = std::begin(rhs.elems) 
               + std::distance(lhs.read_pos, std::begin(lhs.elems));
  lhs.read_pos = std::begin(lhs.elems) + rhs_read;
  auto rhs_write = std::distance(rhs.write_pos, std::begin(rhs.elems));
  rhs.write_pos = std::begin(rhs.elems) 
               + std::distance(lhs.write_pos, std::begin(lhs.elems));
  lhs.write_pos = std::begin(lhs.elems) + rhs_write;
}


bool Buffer::add(std::unique_ptr<Alarm> in)
{
  if (num_elems == sz) return false;

  *write_pos = std::move(in);
  ++num_elems;
  ++write_pos;
  if (write_pos == std::end(elems)) write_pos = std::begin(elems);

  return true;
}

bool Buffer::get(std::unique_ptr<Alarm>&  out)
{
  if (num_elems == 0) return false;

  out = std::move(*read_pos);
  --num_elems;
  ++read_pos;
  if (read_pos == std::end(elems)) read_pos = std::begin(elems);

  return true;
}

bool Buffer::is_empty() const
{
  return (num_elems == 0);
}
