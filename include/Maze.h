/*
 * File:   Maze.h
 * Author: floran
 *
 * Created on 30 avril 2013, 19:19
 * Prend en paramètre la taille du labyrinthe
 */

#ifndef MAZE_H
#define	MAZE_H

class Maze {
public:
    Maze(int width, int height);
    virtual ~Maze();

    int getWidth() const;
    int getHeight() const;

private:
    int _width;
    int _height;

};

#endif	/* MAZE_H */