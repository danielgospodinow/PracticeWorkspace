package com.danielgospodinow.ai.genetic.algorithms.travelling.salesman.utils;

import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.Stream;

public class World {

    private static final Random random = new Random();

    private static final int SPACE_SIZE = 50;
    private static final int POPULATION_SIZE = 100;
    private static final int BEST_OF_POPULATION_SIZE = 10;
    private static final int TOTAL_POPULATION_ITERATIONS = 100;

    private List<City> cities;

    public World(int totalCities) {
        this.cities = City.generateRandomCities(totalCities, SPACE_SIZE);
    }

    public Route findBestSolution() {
        List<Route> routes = Route.generateRandomRoutes(POPULATION_SIZE, this.cities);
        Queue<Route> routesQueue = new PriorityQueue<>(routes);

        System.out.println();
        System.out.println(String.format("First %d routes from the initial population:", 4));
        routes.stream()
                .limit(4)
                .sorted()
                .forEach(System.out::println);
        System.out.println();

        Stream.iterate(0, n -> n + 1)
                .limit(TOTAL_POPULATION_ITERATIONS)
                .forEach(populationIteration -> {
                    if(populationIteration == 10) {
                        System.out.println("Best route on iteration 10:");
                        System.out.println(routesQueue.peek());
                        System.out.println();
                    }

                    List<Route> bestForCurrentGeneration = new ArrayList<>();
                    for (int i = 0; i < BEST_OF_POPULATION_SIZE; ++i) {
                        bestForCurrentGeneration.add(routesQueue.remove());
                    }

                    int iterations = bestForCurrentGeneration.size();
                    IntStream.range(0, iterations)
                            .forEach(routeIndex -> {
                                int firstParent = random.nextInt(BEST_OF_POPULATION_SIZE);
                                int secondParent = random.nextInt(BEST_OF_POPULATION_SIZE);

                                Route firstRoute = bestForCurrentGeneration.get(firstParent);
                                Route secondRoute = bestForCurrentGeneration.get(secondParent);

                                Route child = routeCrossover(firstRoute, secondRoute);
                                routeMutate(child);
                                bestForCurrentGeneration.add(child);
                            });

                    bestForCurrentGeneration.stream()
                            .sorted()
                            .limit(iterations)
                            .forEach(routesQueue::add);
                });


        System.out.println("Best route on last iteration:");
        System.out.println(routesQueue.peek());

        return routesQueue.peek();
    }

    private void routeMutate(Route route) {
        int firstCityIndex = random.nextInt(route.getRouteCities().size());
        int secondCityIndex = random.nextInt(route.getRouteCities().size());

        Collections.swap(route.getRouteCities(), firstCityIndex, secondCityIndex);
    }

    private Route routeCrossover(Route firstRoute, Route secondRoute) {
        List<City> firstCityCollection = new ArrayList<>(firstRoute.getRouteCities());
        List<City> secondCityCollection = new ArrayList<>(secondRoute.getRouteCities());

        int sectionStart = random.nextInt(firstCityCollection.size());
        int sectionLength = random.nextInt(firstCityCollection.size() - sectionStart);

        City[] newRoute = new City[firstCityCollection.size()];

        for(int i=sectionStart; i<sectionStart + sectionLength; ++i) {
            newRoute[i] = firstCityCollection.get(i);
        }

        secondCityCollection.removeAll(Arrays.asList(newRoute));

        while(!secondCityCollection.isEmpty()) {
            for(int i=0; i<newRoute.length; ++i) {
                if(newRoute[i] == null) {
                    newRoute[i] = secondCityCollection.remove(0);
                    break;
                }
            }
        }

        return new Route(Arrays.asList(newRoute));
    }
}
