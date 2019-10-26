package com.danielgospodinow.ai.interative.deepening.a.star.graph;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.stream.IntStream;

public class Puzzle {

    private List<Integer> puzzleNumbers;
    private List<List<Integer>> puzzleMatrix;

    public Puzzle(List<Integer> puzzleNumbers) {
        this.puzzleNumbers = puzzleNumbers;
        this.puzzleMatrix = new ArrayList<>();

        int matrixSize = (int) Math.sqrt(puzzleNumbers.size());
        IntStream.range(0, matrixSize)
                .forEach(i -> puzzleMatrix.add(new ArrayList<>()));

        for (int row = 0; row < matrixSize; ++row) {
            for (int col = 0; col < matrixSize; ++col) {
                puzzleMatrix.get(row).add(col, puzzleNumbers.get((matrixSize * row) + col));
            }
        }
    }

    public int getDifference(Puzzle referencePuzzle) {
        int error = 0;

        for (int i = 0; i < puzzleMatrix.size(); ++i) {
            for (int j = 0; j < puzzleMatrix.size(); ++j) {
                error += getIndividualCellDifference(new Position(i, j), referencePuzzle.getMatrixNumberPosition(puzzleMatrix.get(i).get(j)));
            }
        }

        return error;
    }

    public Position getMatrixNumberPosition(int number) {
        int matrixSize = puzzleMatrix.size();
        int puzzleNumberPosition = puzzleNumbers.indexOf(number);

        return new Position(puzzleNumberPosition / matrixSize, puzzleNumberPosition % matrixSize);
    }

    public List<NodeState> generateZeroItemPosibilities() {
        List<NodeState> children = new ArrayList<>();
        Position positionOfZero = getMatrixNumberPosition(0);

        if (isInBound(positionOfZero.getX() + 1, puzzleMatrix.size()) &&
                isInBound(positionOfZero.getY(), puzzleMatrix.size())) {
            List<Integer> newNumbers = new ArrayList<>(puzzleNumbers);
            Collections.swap(newNumbers,
                    (positionOfZero.getX() + 1) * puzzleMatrix.size() + positionOfZero.getY(),
                    positionOfZero.getX() * puzzleMatrix.size() + positionOfZero.getY());

            children.add(new NodeState(new Puzzle(newNumbers)));
        }

        if (isInBound(positionOfZero.getX() - 1, puzzleMatrix.size()) &&
                isInBound(positionOfZero.getY(), puzzleMatrix.size())) {
            List<Integer> newNumbers = new ArrayList<>(puzzleNumbers);
            Collections.swap(newNumbers,
                    (positionOfZero.getX() - 1) * puzzleMatrix.size() + positionOfZero.getY(),
                    positionOfZero.getX() * puzzleMatrix.size() + positionOfZero.getY());

            children.add(new NodeState(new Puzzle(newNumbers)));
        }

        if (isInBound(positionOfZero.getX(), puzzleMatrix.size()) &&
                isInBound(positionOfZero.getY() + 1, puzzleMatrix.size())) {
            List<Integer> newNumbers = new ArrayList<>(puzzleNumbers);
            Collections.swap(newNumbers,
                    positionOfZero.getX() * puzzleMatrix.size() + (positionOfZero.getY() + 1),
                    positionOfZero.getX() * puzzleMatrix.size() + (positionOfZero.getY()));

            children.add(new NodeState(new Puzzle(newNumbers)));
        }

        if (isInBound(positionOfZero.getX(), puzzleMatrix.size()) &&
                isInBound(positionOfZero.getY() - 1, puzzleMatrix.size())) {
            List<Integer> newNumbers = new ArrayList<>(puzzleNumbers);
            Collections.swap(newNumbers,
                    positionOfZero.getX() * puzzleMatrix.size() + (positionOfZero.getY() - 1),
                    positionOfZero.getX() * puzzleMatrix.size() + (positionOfZero.getY()));

            children.add(new NodeState(new Puzzle(newNumbers)));
        }

        return children;
    }

    public List<Integer> getPuzzleNumbers() {
        return puzzleNumbers;
    }

    public List<List<Integer>> getPuzzleMatrix() {
        return puzzleMatrix;
    }

    private int getIndividualCellDifference(Position currentPosition, Position goalPoint) {
        return Math.abs(currentPosition.getX() - goalPoint.getX()) + Math.abs(currentPosition.getY() - goalPoint.getY());
    }

    private boolean isInBound(int number, int bound) {
        return (number >= 0 && number < bound);
    }
}
