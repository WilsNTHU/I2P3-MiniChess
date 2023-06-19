#include <cstdlib>
#include <algorithm>

#include "../state/state.hpp"
#include "./minimax.hpp"


/**
 * @brief Randomly get a legal action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */


int Minimax::miniMax(State *state, int depth, int isMinPlayer){
    if (depth == 0) {
        return -state->evaluate();
    }

    auto actions = state->legal_actions;

    if (isMinPlayer) {
        int bestMove = 9999;
        for(auto it = actions.begin(); it != actions.end(); it++) {
            State *new_state = state->next_state(*it);
            bestMove = std::min(bestMove, miniMax(new_state, depth - 1, 1 - isMinPlayer));
        }
        return bestMove;
        
    } else {
        int bestMove = -9999;
        for (auto it = actions.begin(); it != actions.end(); it++) {
            State *new_state = state->next_state(*it);
            bestMove = std::max(bestMove, miniMax(new_state, depth - 1, 1 - isMinPlayer));
        }
        return bestMove;
    }
}

Move Minimax::get_move(State *state, int depth){
    if(!state->legal_actions.size())
        state->get_legal_actions();
  
    Move bestMoveFound;
    int bestMove = -9999;
    auto actions = state->legal_actions;

    for(auto it = actions.begin(); it != actions.end(); it++) {
        State *new_state = state->next_state(*it);
        int value = miniMax(new_state, depth - 1, 1 - state->player);
        if(value >= bestMove) {
            bestMove = value;
            bestMoveFound = *it;
        }
    }

    return bestMoveFound;
}

