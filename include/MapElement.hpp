//
// MapElement.hpp for __MAPELEMENT_HPP__ in /home/cayrel_l//tek2/projet/Bomberman/include
// 
// Made by lambert cayrel
// Login   <cayrel_l@epitech.net>
// 
// Started on  Wed May 22 17:35:49 2013 lambert cayrel
// Last update Wed May 22 17:47:32 2013 lambert cayrel
//

#ifndef __MAPELEMENT_HPP__
#define __MAPELEMENT_HPP__

class	MapElement
{
public:
  virtual  int	getWalkable() = 0;
  virtual  void	setWalkable() = 0;
protected:
  int	walkable;
};

class	Crate : public MapElement
{

};

class	Wall : public MapElement
{

};

class	Ground : public MapElement
{

};
