#include <cstdlib>
#include <algorithm>

#include "../state/state.hpp"
#include "./submission.hpp"


/**
 * @brief Randomly get a legal action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */


int Submission::miniMax(State *state, int depth, int alpha, int beta, bool isMaxPlayer){
    if (depth == 0) {
        return -state->evaluate();
    }

    auto actions = state->legal_actions;

    if (isMaxPlayer) {
        int maxEval = -9999;
        for (auto it = actions.begin(); it != actions.end(); it++) {
            State *new_state = state->next_state(*it);
            maxEval = std::max(maxEval, miniMax(new_state, depth - 1, alpha, beta, false));
            alpha = std::max(alpha, maxEval);
            if (beta <= alpha) {
                return maxEval;
            }
        }
        return maxEval;
    } else {
        int minEval = 9999;
        for(auto it = actions.begin(); it != actions.end(); it++) {
            State *new_state = state->next_state(*it);
            minEval = std::min(minEval, miniMax(new_state, depth - 1, alpha, beta, true));
            beta = std::min(beta, minEval);
            if (beta <= alpha) {
                return minEval;
            }
        }
        return minEval;
    }
}

Move Submission::get_move(State *state, int depth, bool isMaxPlayer){
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

