#pragma once
#include "../state/state.hpp"


/**
 * @brief Policy class for random policy, 
 * your policy class should have get_move method
 */
class Minimax{
public:
  static Move get_move(State *state, int depth, bool isMaxPlayer);
private:
  static int miniMax(State *state, int depth, bool isMaxPlayer);
};