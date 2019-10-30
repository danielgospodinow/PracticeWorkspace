package com.danielgospodinow.ai.n.queens.utils;

import javafx.util.Pair;

import java.net.Inet4Address;
import java.util.*;
import java.util.function.ToIntFunction;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class QueensBoard {

    private int[] board;

    /**
     * Constructs a board of queens.
     *
     * @param board one dimensional array which contains queens' column position for each row [7, 1, 5, 3, 4, ...]
     */
    public QueensBoard(int[] board) {
        this.board = board;
    }

    public int[] getSolution() {
        int maxIterations = board.length * 3;
        int queensShufflesCount = 0;

        List<Integer> worstQueens = new ArrayList<>(board.length);

        while(true) {
            worstQueens.clear();
            int maxQueenConflicts = 0;
            for(int row=0; row<board.length; ++row) {
                int currentQueenConflicts = getConflicts(row, board[row]);

                if(currentQueenConflicts > maxQueenConflicts) {
                    maxQueenConflicts = currentQueenConflicts;
                    worstQueens.clear();
                    worstQueens.add(currentQueenConflicts);
                } else if(currentQueenConflicts == maxQueenConflicts) {
                    worstQueens.add(currentQueenConflicts);
                }
            }

            if(maxQueenConflicts == 0) {
                return board;
            } else {

            }

            if(++queensShufflesCount > maxIterations) {
                List<Integer> boardList = Arrays.stream(board).boxed().collect(Collectors.toList());
                Collections.shuffle(boardList);
                board = boardList.stream().mapToInt(i -> i).toArray();

                queensShufflesCount = 0;
            }
        }
    }

    private int getConflicts(int row, int col) {
        return Arrays.stream(board)
                .filter(currentRow -> currentRow != row)
                .map(currentRow -> {
                    int currentCol = board[currentRow];
                    return (Math.abs(row - currentRow) == Math.abs(col - currentCol)) ? 1 : 0;
                })
                .reduce(0, Integer::sum);
    }
}
