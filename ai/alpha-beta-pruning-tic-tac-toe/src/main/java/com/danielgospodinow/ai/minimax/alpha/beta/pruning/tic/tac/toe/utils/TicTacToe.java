package com.danielgospodinow.ai.minimax.alpha.beta.pruning.tic.tac.toe.utils;

import java.util.List;
import java.util.TreeMap;

public class TicTacToe {

    public static Position getNextMoveFromAI(TicTacToeBoard board, GameMarker aiMarker) {
        TreeMap<Integer, Position> possibleMoves = new TreeMap<>();
        board.getFreeSpaces().forEach(freeSpace -> {
            board.setMarker(aiMarker, freeSpace);
            int score = minimax(board, getOppositeMarker(aiMarker), 0, Integer.MIN_VALUE, Integer.MAX_VALUE);
            board.setMarker(GameMarker.NONE, freeSpace);

            possibleMoves.put(score, freeSpace);
        });

        if (aiMarker == GameMarker.X) {
            return possibleMoves.lastEntry().getValue();
        } else if (aiMarker == GameMarker.O) {
            return possibleMoves.firstEntry().getValue();
        } else {
            throw new IllegalStateException("Invalid game marker!");
        }
    }

    private static int minimax(TicTacToeBoard board, GameMarker marker, int depth, int alpha, int beta) {
        if (board.getState() != GameState.UNFINISHED) {
            GameState gameState = board.getState();
            if (gameState == GameState.X_WIN) {
                return (10 - depth);
            } else if (gameState == GameState.O_WIN) {
                return -(10 - depth);
            } else {
                return 0;
            }
        } else {
            if (marker == GameMarker.X) {
                // Maximizing
                int bestScore = Integer.MIN_VALUE;

                List<Position> freeSpaces = board.getFreeSpaces();
                for (Position freeSpace : freeSpaces) {
                    board.setMarker(GameMarker.X, freeSpace);
                    int score = minimax(board, getOppositeMarker(GameMarker.X), depth + 1, alpha, beta);
                    board.setMarker(GameMarker.NONE, freeSpace);

                    bestScore = Math.max(bestScore, score);
                    alpha = Math.max(alpha, bestScore);

                    if (beta <= alpha) {
                        break;
                    }
                }

                return bestScore;
            } else if (marker == GameMarker.O) {
                // Minimizing
                int bestScore = Integer.MAX_VALUE;

                List<Position> freeSpaces = board.getFreeSpaces();
                for (Position freeSpace : freeSpaces) {
                    board.setMarker(GameMarker.O, freeSpace);
                    int score = minimax(board, getOppositeMarker(GameMarker.O), depth + 1, alpha, beta);
                    board.setMarker(GameMarker.NONE, freeSpace);

                    bestScore = Math.min(bestScore, score);
                    beta = Math.min(beta, bestScore);

                    if (beta <= alpha) {
                        break;
                    }
                }

                return bestScore;
            } else {
                throw new RuntimeException("Something odd happened");
            }
        }
    }

    private static GameMarker getOppositeMarker(GameMarker marker) {
        if (marker == GameMarker.X) {
            return GameMarker.O;
        } else if (marker == GameMarker.O) {
            return GameMarker.X;
        } else {
            throw new IllegalArgumentException("This marker doesn't have an opposite!");
        }
    }
}
