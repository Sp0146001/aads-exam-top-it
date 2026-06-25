#include "commands.hpp"

#include <iostream>

namespace
{
  void sortMeetings(petrov::Meeting* data, std::size_t size)
  {
    for (std::size_t i = 0; i < size; ++i)
    {
      for (std::size_t j = 0; j + 1 < size; ++j)
      {
        bool needSwap = false;

        if (data[j].first > data[j + 1].first)
        {
          needSwap = true;
        }
        else if (data[j].first == data[j + 1].first)
        {
          if (data[j].time > data[j + 1].time)
          {
            needSwap = true;
          }
        }
        if (needSwap)
        {
          petrov::Meeting tmp = data[j];
          data[j] = data[j + 1];
          data[j + 1] = tmp;
        }
      }
    }
  }

  bool findPersonIndex(const petrov::DataBase& db, std::size_t id, std::size_t& index)
  {
    for (std::size_t i = 0; i < db.persons.size; ++i)
    {
      if (db.persons.data[i].id == id)
      {
        index = i;
        return true;
      }
    }
    return false;
  }

  void commandDesc(petrov::DataBase& db)
  {
    std::size_t id = 0;
    if (!(std::cin >> id))
    {
      std::cout << "<INVALID COMMAND>\n";
      return;
    }
    std::size_t index = 0;
    if (!findPersonIndex(db, id, index))
    {
      std::cout << "<INVALID COMMAND>\n";
      return;
    }
    if (db.persons.data[index].hasInfo)
    {
      std::cout << db.persons.data[index].info << '\n';
    }
    else
    {
      std::cout << "<ANON>\n";
    }
  }

  void commandAnons(petrov::DataBase& db)
  {
    for (std::size_t i = 0; i < db.persons.size; ++i)
    {
      if (!db.persons.data[i].hasInfo)
      {
        std::cout << db.persons.data[i].id << '\n';
      }
    }
  }

  void commandMeets(petrov::DataBase& db)
  {
    std::size_t id = 0;
    if (!(std::cin >> id))
    {
      std::cout << "<INVALID COMMAND>\n";
      return;
    }
    bool found = false;
    for (std::size_t i = 0; i < db.meetings.size; ++i)
    {
      petrov::Meeting& m = db.meetings.data[i];

      if (m.first == id)
      {
        std::cout << m.second << ' ' << m.time << '\n';
        found = true;
      }
      else if (m.second == id)
      {
        std::cout << m.first << ' ' << m.time << '\n';
        found = true;
      }
    }
    if (!found)
    {
      std::cout << "<INVALID COMMAND>\n";
    }
  }
}

void petrov::commandLoop(DataBase& db)
{
  std::string command = "";
  while (std::cin >> command)
  {
    if (command == "desc")
    {
      commandDesc(db);
    }
    else if (command == "anons")
    {
      commandAnons(db);
    }
    else if (command == "meets")
    {
      commandMeets(db);
    }
    else
    {
      std::cout << "<INVALID COMMAND>\n";
    }
  }
}
