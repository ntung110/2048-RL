#include "board.h"
#include "constants.h"

#include <cstdint>

Board::Board(uint64_t board) : score{0}, board{board} {}

uint16_t Board::getRow(int i) {
  int shift = (ROW_SIZE - 1 - i) * BOARD_SIZE;
  return (board >> shift) & 0xFFFF;
}

int Board::getTile(int i, int j) {
  uint16_t row = getRow(i);
  int shift = (ROW_SIZE - 1 - j) * BITS_PER_TILE;
  return (row >> shift) & 0xF;
}

uint16_t Board::getCol(int j) {
  uint16_t col = 0;
  for (int i = 0; i < ROW_SIZE; ++i) {
    int val = getTile(i,j);
    int shift = (ROW_SIZE - 1 - i) * BITS_PER_TILE;
    col |= val << shift;
  }
}