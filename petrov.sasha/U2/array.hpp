#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <stdexcept>

namespace petrov
{
  namespace detail
  {
    template< class T >
    struct array_t
    {
      T * data;
      std::size_t size;
      std::size_t capacity;
    };

    template< class T >
    void initArray(array_t< T >& array);
    template< class T >
    void destroyArray(array_t< T >& array) noexcept;
    template< class T >
    void pushBackArray(array_t< T >& array, const T& value);
  }
}

#endif
