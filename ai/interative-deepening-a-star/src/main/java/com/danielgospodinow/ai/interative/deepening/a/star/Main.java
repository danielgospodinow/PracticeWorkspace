package com.danielgospodinow.ai.interative.deepening.a.star;

import com.danielgospodinow.ai.interative.deepening.a.star.graph.Graph;
import com.danielgospodinow.ai.interative.deepening.a.star.graph.NodeState;
import com.danielgospodinow.ai.interative.deepening.a.star.graph.Puzzle;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.Stream;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int totalBlocks = Integer.parseInt(scanner.nextLine()) + 1;
        int zeroIndex = Integer.parseInt(scanner.nextLine());
        int fieldSize = (int) Math.round(Math.sqrt(totalBlocks));

        List<Integer> finalStateArray = Stream.iterate(1, n -> n + 1)
                .limit(totalBlocks - 1)
                .collect(Collectors.toList());
        finalStateArray.add(zeroIndex == -1 ? totalBlocks - 1 : zeroIndex, 0);
        Puzzle finalState = new Puzzle(new ArrayList<>(finalStateArray));
        Puzzle initialState = new Puzzle(parseInitialGraphState(readGraphStateLines(scanner, fieldSize)));

        Graph graph = new Graph(initialState, finalState);
        System.out.println(graph.getShortestPathToSolution());
    }

    private static List<Integer> parseInitialGraphState(List<String> lines) {
        return lines.stream()
                .map(line -> line.split(" "))
                .flatMapToInt(line -> Arrays.stream(line).mapToInt(Integer::parseInt))
                .collect(ArrayList::new, ArrayList::add, ArrayList::addAll);
    }

    private static List<String> readGraphStateLines(Scanner scanner, int linesSize) {
        List<String> lines = new ArrayList<>();
        IntStream.range(0, linesSize).forEach(i -> lines.add(scanner.nextLine()));

        return lines;
    }
}
