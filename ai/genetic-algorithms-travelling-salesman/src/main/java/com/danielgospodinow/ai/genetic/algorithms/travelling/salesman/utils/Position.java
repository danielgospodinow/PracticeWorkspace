package com.danielgospodinow.ai.genetic.algorithms.travelling.salesman.utils;

import java.util.Random;

public class Position {

    public static Position getRandomPosition(int xMin, int xMax, int yMin, int yMax) {
        Random random = new Random();

        int randomX = random.nextInt(xMax - xMin) + xMin;
        int randomY = random.nextInt(yMax - yMin) + yMin;

        return new Position(randomX, randomY);
    }

    public static Position getRandomPosition(int distanceFromZeroBound) {
        Random random = new Random();

        int randomX = random.nextInt(distanceFromZeroBound * 2) - distanceFromZeroBound;
        int randomY = random.nextInt(distanceFromZeroBound * 2) - distanceFromZeroBound;

        return new Position(randomX, randomY);
    }

    public static double getDistance(Position positionOne, Position positionTwo) {
        int xDifference = Math.abs(positionOne.getX() - positionTwo.getX());
        int yDifference = Math.abs(positionOne.getY() - positionTwo.getY());

        return Math.sqrt(Math.pow(xDifference, 2) + Math.pow(yDifference, 2));
    }

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
}
