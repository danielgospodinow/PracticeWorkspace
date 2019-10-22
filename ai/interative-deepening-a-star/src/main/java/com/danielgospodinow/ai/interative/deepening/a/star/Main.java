package com.danielgospodinow.ai.interative.deepening.a.star;

import com.danielgospodinow.ai.interative.deepening.a.star.graph.NodeState;
import com.danielgospodinow.ai.interative.deepening.a.star.graph.Puzzle;

import java.util.*;
import java.util.stream.IntStream;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int totalBlocks = Integer.parseInt(scanner.nextLine()) + 1;
        int zeroIndex = Integer.parseInt(scanner.nextLine());
        int fieldSize = (int) Math.round(Math.sqrt(totalBlocks));

        List<String> lines = readGraphStateLines(scanner, fieldSize);
        Puzzle initialGraphStateInput = parseInitialGraphState(lines);

        NodeState initialNodeState = new NodeState(initialGraphStateInput, zeroIndex, 0);

    }

    private static Puzzle parseInitialGraphState(List<String> lines) {
        List<Integer> inputNumbers = lines.stream()
                .map(line -> line.split(" "))
                .flatMapToInt(line -> Arrays.stream(line).mapToInt(Integer::parseInt))
                .collect(ArrayList::new, ArrayList::add, ArrayList::addAll);

        return new Puzzle(inputNumbers);
    }

    private static List<String> readGraphStateLines(Scanner scanner, int linesSize) {
        List<String> lines = new ArrayList<>();
        IntStream.range(0, linesSize).forEach(i -> lines.add(scanner.nextLine()));

        return lines;
    }
}
