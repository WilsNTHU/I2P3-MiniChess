NTHU I2P3   MiniChess AI

This project implements an Chess AI with Minimax and AlphaBeta algorithm respectively.

In chess evaluation, I assign each kind of chess different points respectively :
(positive value for player, negative value for opponent)

pawn : 10 points
knight : 30 points
bishop : 30 points
rook : 50 points
queen : 90 points
king : 900 points

There are three types of players in the project, player_minimax for minimax algorithm, player_alphaBeta and player_submission for minimax algorithm with alphaBeta pruning.

minimax algorithm first call the player himself as the maximizing player and latet call the opponent as the minimizing player, and repeat this process until the depth equals 0,
this algorithm explores every possibility in the next move and choose the best move based on the total sum up of chess points by evaluating the current state.

alphaBeta pruning uses the same technique but with a more efficient way by reducing worst case that the algorithm doesn't need to explore which can save the computation power that the machine can explore the same depth with less operation, leading to a potetial with calculating with higher depth in a more efficient manner.
