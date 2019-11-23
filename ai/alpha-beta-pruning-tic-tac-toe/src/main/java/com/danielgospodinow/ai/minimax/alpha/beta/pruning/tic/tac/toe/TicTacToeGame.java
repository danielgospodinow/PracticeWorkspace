package com.danielgospodinow.ai.minimax.alpha.beta.pruning.tic.tac.toe;

import com.danielgospodinow.ai.minimax.alpha.beta.pruning.tic.tac.toe.utils.*;

import java.util.Scanner;

public class TicTacToeGame {

    private TicTacToeBoard board = new TicTacToeBoard();

    public TicTacToeGame() {

    }

    public void start() {
        Scanner scanner = new Scanner(System.in);

        while(board.getState() == GameState.UNFINISHED) {
            String[] position = scanner.nextLine().split(",");
            Position inputPosition = new Position(Integer.parseInt(position[0]), Integer.parseInt(position[1]));
            board.setMarker(GameMarker.X, inputPosition);

            if(board.getState() == GameState.UNFINISHED) {
                Position aiPosition = TicTacToe.getNextMoveFromAI(board, GameMarker.O);
                board.setMarker(GameMarker.O, aiPosition);
            } else {
                break;
            }
        }

        printResults();
    }

    private void printResults() {
        System.out.println("Final state: ");
        board.print();

        switch (board.getState()) {
            case EVEN:
                System.out.println("Even!");
                break;
            case X_WIN:
                System.out.println("Player1 won!");
                break;
            case O_WIN:
                System.out.println("Player2 won!");
                break;
            default: throw new RuntimeException("Something odd happened");
        }
    }
}
