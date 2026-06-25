#include "person.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <new>

namespace petrov
{
  const size_t INITIAL_CAPACITY = 16;
  static bool parseArgs(int argc, char* argv[], std::string& inFile, std::string& outFile);

}

int main(int argc, char* argv[])
{
  
}

static bool petrov::parseArgs(int argc, char* argv[], std::string& inFile, std::string& outFile)
{
  bool hasIn = false;
  bool hasOut = false;
  for (int i = 1; i < argc; ++i)
  {
    std::string arg = argv[i];
    if (arg.substr(0, 3) == "in:")
    {
      if (hasIn)
      {
        return false;
      }
      hasIn = true;
      inFile = arg.substr(3);
    }
    else if (arg.substr(0, 4) == "out:")
    {
      if (hasOut)
      {
        return false;
      }
      hasOut = true;
      outFile = arg.substr(4);
    }
    else
    {
      return false;
    }
  }
  return true;
}

