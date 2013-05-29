//
// Parser.cpp for Parser.cpp in /home/cayrel_l//tek2/projet/bomber/Bomberman/src
// 
// Made by lambert cayrel
// Login   <cayrel_l@epitech.net>
// 
// Started on  Fri May 24 16:54:35 2013 lambert cayrel
// Last update Mon May 27 16:45:36 2013 lambert cayrel
//

#include <iostream>
#include <fstream>
#include "Parser.hpp"
#include "AObject.hpp"
#include "Model.hpp"
#include "GameClock.hpp"
#include "Input.hpp"
#include "MapElement.hpp"

void	DisplayLine(std::string str, int line)
{
  int			pos = 0;
  std::string::iterator it = str.begin();

  while (it != str.end())
    {
      if (*it == '1' || *it == '7')
	{
	  std::cout << "Sol|";
	}
      else if (*it == '2')
	{
	  std::cout << "Wall|";
	}
      else if (*it == '3')
	{
	  std::cout << "Crate|";
	}
      pos++;
      it++;
    }
  std::cout << std::endl;
}

void		Parser(const char *name)
{
  std::ifstream	file(name, std::ios::in);
  std::string	str;
  int		line = 0;

  if (file)
    {
      while (getline(file, str))
	{
	  DisplayLine(str, line);
	  line++;
	}
      file.close();
    }
  else
    std::cout << "Bad Map File" << std::endl;
}
