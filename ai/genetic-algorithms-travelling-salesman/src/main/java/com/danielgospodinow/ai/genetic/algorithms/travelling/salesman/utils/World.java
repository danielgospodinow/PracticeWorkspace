package com.danielgospodinow.ai.genetic.algorithms.travelling.salesman.utils;

import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.stream.Stream;

public class World {

    private static final int SPACE_SIZE = 50;
    private static final int POPULATION_SIZE = 20;
    private static final int BEST_OF_POPULATION_SIZE = 10;
    private static final int TOTAL_POPULATION_ITERATIONS = 100;

    private List<City> cities;

    public World(int totalCities) {
        this.cities = City.generateRandomCities(totalCities, SPACE_SIZE);
    }

    public Route findBestSolution() {
        List<Route> routes = Route.generateRandomRoutes(POPULATION_SIZE, this.cities);
        Queue<Route> routesQueue = new PriorityQueue<>(routes);

        Stream.iterate(0, n -> n + 1)
                .limit(TOTAL_POPULATION_ITERATIONS)
                .forEach(populationIteration -> {
                    List<Route> bestForCurrentGeneration = new ArrayList<>();
                    for(int i=0; i<routesQueue.size(); ++i) {
                        bestForCurrentGeneration.add(routesQueue.poll());
                    }

                    // Cross two random best elements
                    // Mutate
                    // Add them to the population if they're good enough
                });

        return null;
    }
}
