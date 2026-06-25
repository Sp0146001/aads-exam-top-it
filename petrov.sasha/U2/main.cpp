#include "domain.hpp"
#include <iostream>

int main()
{
  petrov::DataBase db =
  {
    { nullptr, 0, 0 },
    { nullptr, 0, 0 }
  };
  petrov::initDataBase(db);
  petrov::destroyDataBase(db);

  return 0;
}
