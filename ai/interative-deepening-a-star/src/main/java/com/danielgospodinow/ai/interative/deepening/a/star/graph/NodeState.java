package com.danielgospodinow.ai.interative.deepening.a.star.graph;

import java.util.List;

public class NodeState {

    private Puzzle puzzle;
    private int indexOfZero;
    private int distance;

    public NodeState(Puzzle puzzle, int indexOfZero, int distance) {
        this.puzzle = puzzle;
        this.indexOfZero = indexOfZero;
        this.distance = distance;
    }

    public List<NodeState> getNeighbours() {


        return null;
    }

    public int getError() {
        return puzzle.getError() + distance;
    }
}
