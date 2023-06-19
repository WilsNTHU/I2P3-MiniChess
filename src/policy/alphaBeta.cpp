#include <cstdlib>
#include <algorithm>

#include "../state/state.hpp"
#include "./alphaBeta.hpp"


/**
 * @brief Randomly get a legal action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */


int AlphaBeta::miniMax(State *state, int depth, int alpha, int beta, bool isMaxPlayer){
    if (depth == 0) {
        return -state->evaluate();
    }

    auto actions = state->legal_actions;

    if (isMaxPlayer) {
        int bestMove = -9999;
        for (auto it = actions.begin(); it != actions.end(); it++) {
            State *new_state = state->next_state(*it);
            bestMove = std::max(bestMove, miniMax(new_state, depth - 1, alpha, beta, !isMaxPlayer));
            alpha = std::max(alpha, bestMove);
            if (beta <= alpha) {
                return bestMove;
            }
        }
        return bestMove;
    } else {
        int bestMove = 9999;
        for(auto it = actions.begin(); it != actions.end(); it++) {
            State *new_state = state->next_state(*it);
            bestMove = std::min(bestMove, miniMax(new_state, depth - 1, alpha, beta, !isMaxPlayer));
            beta = std::min(beta, bestMove);
            if (beta <= alpha) {
                return bestMove;
            }
        }
        return bestMove;
    }
}

Move AlphaBeta::get_move(State *state, int depth, bool isMaxPlayer){
    if(!state->legal_actions.size())
        state->get_legal_actions();
  
    Move bestMoveFound;
    int bestMove = -9999;

    for(auto it = state->legal_actions.begin(); it != state->legal_actions.end(); it++) {
        State *new_state = state->next_state(*it);
        int value = miniMax(new_state, depth - 1, -15000, 15000, !isMaxPlayer);
        if(value >= bestMove) {
            bestMove = value;
            bestMoveFound = *it;
        }
    }

    return bestMoveFound;
}

