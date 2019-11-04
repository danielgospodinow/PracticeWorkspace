package com.danielgospodinow.ai.genetic.algorithms.travelling.salesman.utils;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Route implements Comparable<Route> {

    public static List<Route> generateRandomRoutes(int amountOfRoutes, List<City> cities) {
        List<Route> routes = new ArrayList<>();

        Stream.iterate(0, n -> n + 1)
                .limit(amountOfRoutes)
                .forEach(iteration -> {
                    Collections.shuffle(cities);
                    routes.add(new Route(new ArrayList<>(cities)));
                });

        return routes;
    }

    private List<City> route;

    public Route(List<City> cities) {
        cities.add(cities.get(0));
        this.route = cities;
    }

    public int getTotalTravelDistance() {
        return Stream.iterate(0, n -> n + 1)
                .limit(route.size() - 1)
                .map(iteration -> City.getDistanceBetweenCities(route.get(iteration), route.get(iteration + 1)))
                .reduce(0, Integer::sum);
    }

    @Override
    public String toString() {
        return String.format("Route [%s]: %d travel distance",
                route.stream().map(City::getId).collect(Collectors.joining(",")),
                getTotalTravelDistance());
    }

    @Override
    public int compareTo(Route route) {
        return this.getTotalTravelDistance() - route.getTotalTravelDistance();
    }
}
