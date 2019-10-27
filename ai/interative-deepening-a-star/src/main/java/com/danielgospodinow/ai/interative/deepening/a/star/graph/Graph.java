package com.danielgospodinow.ai.interative.deepening.a.star.graph;

import java.util.ArrayList;
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
            visited.add(currentNode);
            printSteps(visited);
            return totalMoves;
        }

        visited.add(currentNode);

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
                    .orElse(Integer.MAX_VALUE);
        }
    }

    private static void printSteps(List<NodeState> path) {
        for (int i = 0; i < path.size() - 1; ++i) {
            System.out.println(getMove(path.get(i), path.get(i + 1)));
        }
    }

    private static String getMove(NodeState initial, NodeState goal) {
        Position zeroPositionOfInitialMatrix = initial.getPuzzle().getMatrixNumberPosition(0);
        Position zeroPositionOfGoalMatrix = goal.getPuzzle().getMatrixNumberPosition(0);

        if (new Position(zeroPositionOfInitialMatrix.getX() + 1, zeroPositionOfInitialMatrix.getY()).equals(zeroPositionOfGoalMatrix)) {
            return "up";
        } else if (new Position(zeroPositionOfInitialMatrix.getX() - 1, zeroPositionOfInitialMatrix.getY()).equals(zeroPositionOfGoalMatrix)) {
            return "down";
        } else if (new Position(zeroPositionOfInitialMatrix.getX(), zeroPositionOfInitialMatrix.getY() + 1).equals(zeroPositionOfGoalMatrix)) {
            return "left";
        } else if (new Position(zeroPositionOfInitialMatrix.getX(), zeroPositionOfInitialMatrix.getY() - 1).equals(zeroPositionOfGoalMatrix)) {
            return "right";
        } else {
            return "invalid";
        }
    }

    private Graph() {

    }
}
