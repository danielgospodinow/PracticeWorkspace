package com.danielgospodinow.ai.minimax.alpha.beta.pruning.tic.tac.toe;

import com.danielgospodinow.ai.minimax.alpha.beta.pruning.tic.tac.toe.utils.*;

import java.util.Scanner;

public class TicTacToeGame {

    private TicTacToeBoard board = new TicTacToeBoard();

    public TicTacToeGame() {

    }

    public void start(boolean humanFirst) {
        Scanner scanner = new Scanner(System.in);

        if(humanFirst) {
            while (board.getState() == GameState.UNFINISHED) {
                System.out.println("Enter position: ");
                String[] position = scanner.nextLine().split(",");
                Position inputPosition = new Position(Integer.parseInt(position[0]) - 1,
                        Integer.parseInt(position[1]) - 1);
                board.setMarker(GameMarker.X, inputPosition);

                board.print();
                System.out.println();

                if (board.getState() == GameState.UNFINISHED) {
                    Position aiPosition = TicTacToe.getNextMoveFromAI(board, GameMarker.O);
                    board.setMarker(GameMarker.O, aiPosition);

                    System.out.println("AI moves:");
                    board.print();
                    System.out.println();
                } else {
                    break;
                }
            }
        } else {
            while (board.getState() == GameState.UNFINISHED) {
                Position aiPosition = TicTacToe.getNextMoveFromAI(board, GameMarker.X);
                board.setMarker(GameMarker.X, aiPosition);

                System.out.println("AI moves:");
                board.print();
                System.out.println();

                if (board.getState() == GameState.UNFINISHED) {
                    System.out.println("Enter position: ");
                    String[] position = scanner.nextLine().split(",");
                    Position inputPosition = new Position(Integer.parseInt(position[0]) - 1,
                            Integer.parseInt(position[1]) - 1);
                    board.setMarker(GameMarker.O, inputPosition);

                    board.print();
                    System.out.println();
                } else {
                    break;
                }
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
                System.out.println("X won!");
                break;
            case O_WIN:
                System.out.println("O won!");
                break;
            default: throw new RuntimeException("Something odd happened");
        }
    }
}
