package com.danielgospodinow.ai.interative.deepening.a.star.graph;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.IntStream;

public class Puzzle {

    private List<List<Integer>> matrix;
    private int error;

    public Puzzle(List<Integer> numbers) {
        int matrixSize = (int) Math.sqrt(numbers.size());
        this.matrix = new ArrayList<>();

        IntStream.range(0, matrixSize)
                .forEach(i -> matrix.add(new ArrayList<>()));

        int totalError = 0;
        for (int row = 0; row < matrixSize; ++row) {
            for (int col = 0; col < matrixSize; ++col) {
                int currentNumber = numbers.get((matrixSize * row) + col);

                matrix.get(row).add(col, currentNumber);
                totalError += getErrorForIndividualCell(row, col, currentNumber);
            }
        }

        this.error = totalError;
    }

    public int getError() {
        return this.error;
    }

    private int getErrorForIndividualCell(int row, int col, int number) {
        int realRow = (number - 1) / matrix.size();
        int realCol = (number - 1) % matrix.size();

        return Math.abs(row - realRow) + Math.abs(col - realCol);
    }
}
