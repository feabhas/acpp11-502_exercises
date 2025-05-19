// Buffer.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Buffer.h"

bool Buffer::add(Alarm const& in)
{
  if (num_elems == sz) return false;

  *write_pos = in;
  ++num_elems;
  inc_iterator(write_pos); // Use inc_iterator here

  return true;
}

bool Buffer::get(Alarm&  out)
{
  if (num_elems == 0) return false;

  out = *read_pos;
  --num_elems;
  inc_iterator(read_pos); // Use inc_iterator here

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

void Buffer::inc_iterator(Container::iterator& it)
{
  ++it;
  if (it == std::end(elems)) it = std::begin(elems);  
}