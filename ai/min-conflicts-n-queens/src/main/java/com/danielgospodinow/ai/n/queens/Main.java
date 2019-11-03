package com.danielgospodinow.ai.n.queens;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int sizeOfBoard = scanner.nextInt();

        QueensBoard queensBoard = new QueensBoard();
        long start = System.currentTimeMillis();
        queensBoard.findSolution(sizeOfBoard);
        long stop = System.currentTimeMillis();
        System.out.println("Solved in " + ((double)(stop-start))/1000 + "seconds.");
        queensBoard.printLastSolution();
    }
}
