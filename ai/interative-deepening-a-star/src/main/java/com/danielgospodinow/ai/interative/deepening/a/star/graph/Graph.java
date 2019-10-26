package com.danielgospodinow.ai.interative.deepening.a.star.graph;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

public class Graph {

    public static int getShortestPathToSolution(Puzzle initialState, Puzzle finalState) {
        NodeState initialNodeState = new NodeState(initialState);
        NodeState finalNodeState = new NodeState(finalState);

        int errorLimit = initialNodeState.getError(finalState, 0);
        while (true) {
            List<NodeState> visited = new ArrayList<>();
            int result = iterativeDeepeningAStar(initialNodeState, finalNodeState, 0, errorLimit, visited);

            if (result < 0) {
                errorLimit = Math.abs(result);
            } else {
                return result;
            }
        }
    }

    private static int iterativeDeepeningAStar(NodeState currentNode, NodeState goalNode, int totalMoves, int errorLimit, List<NodeState> visited) {
        if (visited.contains(currentNode)) {
            return Integer.MAX_VALUE;
        }

        int currentNodeError = currentNode.getError(goalNode.getPuzzle(), totalMoves);

        if (currentNodeError > errorLimit) {
            return -currentNodeError;
        }

        if (currentNode.equals(goalNode)) {
            System.out.println(Arrays.toString(currentNode.getPuzzle().getPuzzleNumbers().toArray()));
            return totalMoves + 1;
        }

        visited.add(currentNode);
        System.out.println(Arrays.toString(currentNode.getPuzzle().getPuzzleNumbers().toArray()));

        List<NodeState> children = currentNode.getNeighbours();
        List<Integer> childrenResults = new ArrayList<>();

        for (NodeState child : children) {
            if (!visited.contains(child)) {
                childrenResults.add(iterativeDeepeningAStar(child, goalNode, totalMoves + 1, errorLimit, visited));
            }
        }

        visited.remove(currentNode);

        List<Integer> positiveAnswers = childrenResults.stream().filter(answer -> answer > 0).collect(Collectors.toList());
        if (positiveAnswers.size() > 0) {
            return positiveAnswers.stream()
                    .min(Comparator.naturalOrder())
                    .get();
        } else {
            return childrenResults.stream()
                    .filter(answer -> answer < 0)
                    .max(Comparator.naturalOrder())
                    .get();
        }
    }

    private Graph() {

    }
}
