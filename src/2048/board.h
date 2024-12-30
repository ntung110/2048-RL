#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <cstdint>

class Board {
  int score;
  uint64_t board;

  public:
    Board(uint64_t board);
    int getTile(int i, int j);
    uint16_t getRow(int i);
    uint16_t getCol(int i);
};


#endif