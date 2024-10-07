// Buffer.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Buffer.h"

bool Buffer::add(Alarm const& in)
{
  if (num_elems == sz) return false;

  *write_pos = in;
  ++num_elems;
  ++write_pos;
  if (write_pos == std::end(elems)) write_pos = std::begin(elems);

  return true;
}

bool Buffer::get(Alarm&  out)
{
  if (num_elems == 0) return false;

  out = *read_pos;
  --num_elems;
  ++read_pos;
  if (read_pos == std::end(elems)) read_pos = std::begin(elems);

  return true;
}

bool Buffer::is_empty() const
{
  return (num_elems == 0);
}

bool Buffer::is_full() const
{
  return (num_elems == sz);
}