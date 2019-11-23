package com.danielgospodinow.ai.minimax.alpha.beta.pruning.tic.tac.toe;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        TicTacToeGame ticTacToeGame = new TicTacToeGame();

        Scanner scanner = new Scanner(System.in);
        System.out.println("Do you want to start first? Or you'll be a gentleman and let the AI go first?");
        boolean humanFirst = scanner.nextLine().contains("y");

        ticTacToeGame.start(humanFirst);
    }
}
