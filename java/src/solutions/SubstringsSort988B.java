package solutions;

import javafx.util.Pair;

import java.util.*;

public class SubstringsSort988B {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();

        Map<Integer, Map<String, Integer>> strMap = new TreeMap<>();
        for (int i = 0; i < N; i++) {
            String s = scanner.next();
            strMap.putIfAbsent(s.length(), new HashMap<>());

            Map<String, Integer> strSet = strMap.get(s.length());
            strSet.putIfAbsent(s, 0);
            strSet.put(s, strSet.get(s) + 1);
            strMap.put(s.length(), strSet);
        }

        orderStringsInSortedSubstrings(N, strMap);
    }

    private static void orderStringsInSortedSubstrings(int n, Map<Integer, Map<String, Integer>> strArr) {

        List<Pair<String, Integer>> orderedStr = new ArrayList<>();

        String previous = "";
        for (Map.Entry<Integer, Map<String, Integer>> entry: strArr.entrySet()) {
            if(entry.getValue().keySet().size() > 1) {
                System.out.println("NO");
                return;
            }
            String curStr = "";
            int countStr = 0;
            for (Map.Entry<String, Integer> e: entry.getValue().entrySet()) {
                curStr = e.getKey();
                countStr = e.getValue();
            }
            if(curStr.indexOf(previous) == -1) {
                System.out.println("NO");
                return;
            }
            previous = curStr;
            orderedStr.add(new Pair<>(curStr, countStr));
        }

        System.out.println("YES");
        for (Pair<String, Integer> strDetails: orderedStr) {
            for (int i = 0; i < strDetails.getValue(); i++) {
                System.out.println(strDetails.getKey());
            }
        }
    }

}
