package com.danielgospodinow.ai.interative.deepening.a.star.graph;

import java.util.List;

public class NodeState {

    private Puzzle puzzle;

    public NodeState(Puzzle puzzle) {
        this.puzzle = puzzle;
    }

    public List<NodeState> getNeighbours() {
        return puzzle.generateZeroItemPosibilities();
    }

    public int getError(Puzzle referencePuzzle, int distance) {
        return puzzle.getDifference(referencePuzzle) + distance;
    }

    public Puzzle getPuzzle() {
        return puzzle;
    }

    @Override
    public boolean equals(Object obj) {
        if(obj == null) {
            return false;
        } else if(!(obj instanceof NodeState)) {
            return false;
        } else {
            return puzzle.getPuzzleNumbers().equals(((NodeState) obj).getPuzzle().getPuzzleNumbers());
        }
    }
}
