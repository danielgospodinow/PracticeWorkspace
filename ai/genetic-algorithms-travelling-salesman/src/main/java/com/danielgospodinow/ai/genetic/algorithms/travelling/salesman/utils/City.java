package com.danielgospodinow.ai.genetic.algorithms.travelling.salesman.utils;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class City {

    public static int getDistanceBetweenCities(City firstCity, City secondCity) {
        return (int) Math.round(Position.getDistance(firstCity.getPosition(), secondCity.getPosition()));
    }

    public static List<City> generateRandomCities(int totalCities, int spaceSize) {
        return Stream.iterate(0, n -> n + 1)
                .limit(totalCities)
                .map(iteration -> {
                    Position randomPosition = Position.getRandomPosition(spaceSize);

                    System.out.println(String.format("Creating a random city at (%d,%d)",
                            randomPosition.getX(),
                            randomPosition.getY()));

                    return new City(String.valueOf(iteration), randomPosition);
                })
                .collect(Collectors.toCollection(ArrayList::new));
    }

    private String id;
    private Position position;

    public City(String id, Position position) {
        this.id = id;
        this.position = position;
    }

    public String getId() {
        return id;
    }

    public Position getPosition() {
        return position;
    }
}
