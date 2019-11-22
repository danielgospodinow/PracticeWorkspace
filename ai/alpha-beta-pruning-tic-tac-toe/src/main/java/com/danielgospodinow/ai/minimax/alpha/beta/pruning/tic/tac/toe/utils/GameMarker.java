package com.danielgospodinow.ai.minimax.alpha.beta.pruning.tic.tac.toe.utils;

public enum GameMarker {

    NONE("_"),
    X("X"),
    O("O");

    private String markerString;

    GameMarker(String markerString) {
        this.markerString = markerString;
    }

    @Override
    public String toString() {
        return markerString;
    }
}
