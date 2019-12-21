package solutions;

import java.util.*;

public class Megacity424B {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numOfCities = scanner.nextInt();
        int population = scanner.nextInt();
        if(population >= 1000000) {
            System.out.println("0");
            return;
        }

        Map<Double, List<Integer>> distancePopulationMap = new TreeMap<>();
        for (int i = 0; i < numOfCities; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            int cityPopulation = scanner.nextInt();
            double distance = calculateDistance(0, 0, x, y);
            if(!distancePopulationMap.containsKey(distance)) {
                distancePopulationMap.put(distance, new ArrayList<>());
            }
            distancePopulationMap.get(distance).add(cityPopulation);
        }

        long currentPopulation = population;
        double radius = -1.0f;
        for (Map.Entry<Double, List<Integer>> entry: distancePopulationMap.entrySet()) {
            for (Integer x: entry.getValue()) {
                currentPopulation += x;
            }
            if(currentPopulation >= 1000000L) {
                radius = entry.getKey();
                break;
            }
        }
        if(radius > 0) {
            System.out.println(radius);
        }
        else {
            System.out.println("-1");
        }
    }

    private static double calculateDistance(int srcX, int srcY, int destX, int destY) {
        return Math.sqrt(Math.pow((destX - srcX), 2) + Math.pow((destY - srcY), 2));
    }
}