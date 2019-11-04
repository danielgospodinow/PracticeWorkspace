package com.danielgospodinow.ai.genetic.algorithms.travelling.salesman;

import com.danielgospodinow.ai.genetic.algorithms.travelling.salesman.utils.World;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int totalNodes = scanner.nextInt();
        World world = new World(totalNodes);
        world.findBestSolution();
    }
}
