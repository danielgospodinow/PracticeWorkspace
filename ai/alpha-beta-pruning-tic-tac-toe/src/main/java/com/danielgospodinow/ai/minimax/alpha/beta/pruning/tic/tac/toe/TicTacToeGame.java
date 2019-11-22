package com.danielgospodinow.ai.minimax.alpha.beta.pruning.tic.tac.toe;

import com.danielgospodinow.ai.minimax.alpha.beta.pruning.tic.tac.toe.utils.*;

import java.util.Scanner;

public class TicTacToeGame {

    private TicTacToeBoard board = new TicTacToeBoard();

    public TicTacToeGame() {

    }

    public void start() {
        Scanner scanner = new Scanner(System.in);

        while(TicTacToe.getGameStateFromBoard(board) == GameState.UNFINISHED) {
            String[] position = scanner.nextLine().split(",");
            Position inputPosition = new Position(Integer.parseInt(position[0]), Integer.parseInt(position[1]));

            board.addMarker(GameMarker.X, inputPosition);
        }
    }
}
