package com.danielgospodinow.ai.interative.deepening.a.star.graph;

public class Position {

    private int x;
    private int y;

    public Position(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }

        if (!(obj instanceof Position)) {
            return false;
        }

        Position other = (Position) obj;
        return this.x == other.x &&
                this.y == other.y;
    }
}
