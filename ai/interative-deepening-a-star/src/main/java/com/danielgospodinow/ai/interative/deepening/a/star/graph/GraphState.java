package com.danielgospodinow.ai.interative.deepening.a.star.graph;

import java.util.List;

public class GraphState implements Comparable {

    private int error;

    public GraphState(List<Integer> state) {
        this.error = calculateError(state);
    }

    public int getError() {
        return error;
    }

    @Override
    public int compareTo(Object o) {
        //TODO: Implement
        return 0;
    }

    private int calculateError(List<Integer> state) {
        //TODO: Implement
        return 0;
    }
}
