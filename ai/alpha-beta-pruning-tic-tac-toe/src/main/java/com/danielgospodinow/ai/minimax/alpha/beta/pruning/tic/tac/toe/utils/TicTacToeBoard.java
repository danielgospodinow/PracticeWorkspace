package com.danielgospodinow.ai.minimax.alpha.beta.pruning.tic.tac.toe.utils;

public class TicTacToeBoard {

    private static final int BOARD_SIZE = 3;

    private GameMarker[][] board;

    public TicTacToeBoard() {
        this.board = new GameMarker[BOARD_SIZE][BOARD_SIZE];
        for(int i=0; i<BOARD_SIZE; ++i) {
            this.board[i] = new GameMarker[BOARD_SIZE];
            for(int j=0; j<BOARD_SIZE; ++j) {
                this.board[i][j] = GameMarker.NONE;
            }
        }
    }

    public void addMarker(GameMarker marker, Position position) {
        board[position.getRow()][position.getCol()] = marker;
    }

    public void print() {
        for(int i=0; i<BOARD_SIZE; ++i) {
            for(int j=0; j<BOARD_SIZE; ++j) {
                System.out.print(board[i][j]);
            }
            System.out.println();
        }
        System.out.println();
    }
}
