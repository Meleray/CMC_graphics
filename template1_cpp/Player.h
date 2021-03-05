#ifndef MAIN_PLAYER_H
#define MAIN_PLAYER_H

#include "Image.h"
#include <vector>
#include <string>
#include <iostream>

struct Point
{
  int x;
  int y;
};

enum class MovementDir
{
  UP,
  DOWN,
  LEFT,
  RIGHT
};

const int LAB_Y = 5;
const int LAB_X = 7;
const int LEVEL_Y = 14;
const int LEVEL_X = 17;
const int WINDOW_WIDTH = 1024, WINDOW_HEIGHT = 1024;

struct Labirynth
{

  Labirynth() {}
  Labirynth(const std::string &a_path, Image *screen, Image *background);
  int draw_level(int x, int y);
  std::pair<int, int> get_tile_coords(int x, int y);
  Image *background;
  Image *screen;
  int x_offs = 0;
  std::vector<std::string> lab;
  std::vector<std::string> level;
  std::vector<std::vector<bool>> used;
};

struct Player
{
  Player(Labirynth *lb, Point pos = {.x = 10, .y = 10})
  {
      coords = pos;
      old_coords = pos;
      lab = lb;
  }

  bool Moved() const;
  int ProcessInput(MovementDir dir);
  void Draw(Image &screen);

private:
  Point coords {.x = 10, .y = 10};
  Point old_coords {.x = 10, .y = 10};
  Pixel color {.r = 255, .g = 255, .b = 0, .a = 255};
  int move_speed = 2;
  int x_global = 0, y_global = 0;
  int counter = 0;
  Labirynth *lab;
};

#endif //MAIN_PLAYER_H
