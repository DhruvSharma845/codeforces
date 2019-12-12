package solutions;

import java.util.*;
import java.util.stream.Collectors;

public class Vitamins1042B {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();

        Map<String, Integer> juiceCostMap = new HashMap<>();
        for (int i = 0; i < N; i++) {
            int cost = scanner.nextInt();

            String vitamins = scanner.next();

            char[] arr = vitamins.toCharArray();
            Arrays.sort(arr);
            vitamins = new String(arr);

            if(juiceCostMap.containsKey(vitamins)) {
                if(juiceCostMap.get(vitamins) < cost) {
                    continue;
                }
            }
            juiceCostMap.put(vitamins, cost);
        }

        List<String> vitaminsList = juiceCostMap.keySet().stream().collect(Collectors.toList());
        List<Integer> costList = juiceCostMap.values().stream().collect(Collectors.toList());

        int cost = getMinimumCostForAllVitamins(N, vitaminsList, costList);
        System.out.println(cost);
    }

    private static int getMinimumCostForAllVitamins(int n, List<String> vitaminsList, List<Integer> costList) {
        int res = getMinimumCostUtil(n, vitaminsList, costList, 0, "");
        if(res >= 300001) {
            return -1;
        }
        return res;
    }

    private static int getMinimumCostUtil(int n, List<String> vitaminsList, List<Integer> costList, int i, String currentVitamins) {
        if(i == vitaminsList.size()) {
            return 300001;
        }
        int res1 = -1;
        String concatenatedString = currentVitamins + vitaminsList.get(i);
        if(concatenatedString.indexOf('A') != -1
                && concatenatedString.indexOf('B') != -1
                && concatenatedString.indexOf('C') != -1) {
            res1 = costList.get(i);
        }
        else {
            res1 = getMinimumCostUtil(n, vitaminsList, costList, i + 1, currentVitamins + vitaminsList.get(i)) + costList.get(i);
        }
        int res2 = getMinimumCostUtil(n, vitaminsList, costList, i+1, currentVitamins);
        return Math.min(res1, res2);
    }


}
