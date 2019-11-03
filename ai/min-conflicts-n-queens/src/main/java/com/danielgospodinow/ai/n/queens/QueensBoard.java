package com.danielgospodinow.ai.n.queens;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;

public class QueensBoard {

    private Random random;

    private int[] board;
    private int[] queensInRow;
    private int[] queensInRightDiagonal;
    private int[] queensInOppositeDiagonal;
    private int boardSize;

    public QueensBoard() {

    }

    public void findSolution(int boardSize) {
        initializeBoard(boardSize);

        int steps = 0;
        List<Integer> worstQueens = new ArrayList<>();

        while (true) {
            int maxConflicts = calculateMaxConflicts(worstQueens);

            if (maxConflicts == 0) {
                return;
            }

            int worstQueenCol = worstQueens.get(random.nextInt(worstQueens.size()));
            List<Integer> bestRows = generateBestPossibleRows(worstQueenCol);
            if (!bestRows.isEmpty()) {
                moveWorstQueenToBestRow(bestRows, worstQueenCol);
            }

            ++steps;
            if (steps == board.length * 2) {
                generateRandomSolution();
                steps = 0;
            }
        }
    }

    private void moveWorstQueenToBestRow(List<Integer> bestRows, int worstQueenCol) {
        removeFromMainDiagonal(board[worstQueenCol], worstQueenCol);
        removeFromOppositeDiagonal(board[worstQueenCol], worstQueenCol);
        this.queensInRow[board[worstQueenCol]] -= 1;

        int newRow = bestRows.get(random.nextInt(bestRows.size()));
        board[worstQueenCol] = newRow;

        this.queensInRow[newRow] += 1;
        addToMainDiagonal(newRow, worstQueenCol);
        addToOppositeDiagonal(newRow, worstQueenCol);
    }

    private List<Integer> generateBestPossibleRows(int worstQueenColumn) {
        int minConflicts = boardSize;
        List<Integer> bestRows = new ArrayList<>();

        for (int row = 0; row < boardSize; ++row) {
            int conflicts = getConflictsOfCoordinate(row, worstQueenColumn);
            if (conflicts == minConflicts) {
                bestRows.add(row);
            } else if (conflicts < minConflicts) {
                minConflicts = conflicts;
                bestRows.clear();
                bestRows.add(row);
            }
        }

        return bestRows;
    }

    private int calculateMaxConflicts(List<Integer> worstQueens) {
        worstQueens.clear();
        int maxConflicts = 0;

        for (int col = 0; col < board.length; ++col) {
            int conflicts = getConflictsOfCoordinate(board[col], col);
            if (conflicts == maxConflicts) {
                worstQueens.add(col);
            } else if (conflicts > maxConflicts) {
                maxConflicts = conflicts;
                worstQueens.clear();
                worstQueens.add(col);
            }
        }

        return maxConflicts;
    }

    private int getConflictsOfCoordinate(int row, int col) {
        int mainDiagonalIndex = this.board.length - 1 - Math.abs(row - col);
        if (col < row) {
            mainDiagonalIndex = this.board.length - 1 + Math.abs(row - col);
        }

        return queensInRow[row] +
                queensInRightDiagonal[row + col] +
                queensInOppositeDiagonal[mainDiagonalIndex] +
                ((board[col] == row) ? -3 : 0);
    }

    private void generateRandomSolution() {
        Arrays.fill(queensInRightDiagonal, 0);
        Arrays.fill(queensInOppositeDiagonal, 0);
        Arrays.fill(queensInRow, 0);

        for (int row = 0; row < boardSize; ++row) {
            board[row] = random.nextInt(boardSize);
            queensInRow[board[row]] += 1;
            addToOppositeDiagonal(board[row], row);
            addToMainDiagonal(board[row], row);
        }
    }

    private void addToOppositeDiagonal(int i, int j) {
        this.queensInRightDiagonal[i + j] += 1;
    }

    private void addToMainDiagonal(int i, int j) {
        int mainDiagonalIndex = (i <= j) ?
                (boardSize - 1) - Math.abs(i - j) :
                (boardSize - 1) + Math.abs(i - j);

        this.queensInOppositeDiagonal[mainDiagonalIndex] += 1;
    }

    private void removeFromOppositeDiagonal(int i, int j) {
        this.queensInRightDiagonal[i + j] -= 1;
    }

    private void removeFromMainDiagonal(int i, int j) {
        int mainDiagonalIndex = (i <= j) ?
                (boardSize - 1) - Math.abs(i - j) :
                (boardSize - 1) + Math.abs(i - j);

        this.queensInOppositeDiagonal[mainDiagonalIndex] -= 1;
    }

    private void initializeBoard(int boardSize) {
        this.random = new Random();

        this.boardSize = boardSize;
        this.board = new int[boardSize];
        this.queensInRow = new int[boardSize];
        this.queensInRightDiagonal = new int[2 * boardSize - 1];
        this.queensInOppositeDiagonal = new int[2 * boardSize - 1];

        generateRandomSolution();
    }

    public void printLastSolution() {
        for (int r = 0; r < board.length; ++r) {
            for (int row : board) {
                System.out.print(row == r ? " *" : " _");
            }
            System.out.println();
        }
    }
}
