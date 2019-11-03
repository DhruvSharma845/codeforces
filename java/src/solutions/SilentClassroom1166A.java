package solutions;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class SilentClassroom1166A {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N;
        N = sc.nextInt();

        Map<Character, Integer> studentsCount = new HashMap<>();
        for (int i = 0; i < N; i++) {
            String studentName = sc.next();
            if(!studentsCount.containsKey(studentName.charAt(0))) {
                studentsCount.put(studentName.charAt(0), 1);
            }
            else {
                studentsCount.put(studentName.charAt(0), studentsCount.get(studentName.charAt(0)) + 1);
            }
        }

        System.out.println(findCountOfChattyPairs(N, studentsCount));

    }

    public static int findCountOfChattyPairs(int N, Map<Character, Integer> studentsCount) {
        int count = 0;
        Map<Integer, Integer> pairCountsMemoized = new HashMap<>();
        for (Map.Entry<Character, Integer> entry: studentsCount.entrySet()) {

            if(entry.getValue() > 2) {
                int halfValue = entry.getValue() / 2;
                int pairCountFromFirstHalf = getPairCount(halfValue, pairCountsMemoized);
                int pairCountFromSecondHalf = getPairCount(entry.getValue() - halfValue, pairCountsMemoized);

                count += (pairCountFromFirstHalf + pairCountFromSecondHalf);
            }
        }
        return count;
    }

    public static int getPairCount(int x, Map<Integer, Integer> pairCountsMemoized) {
        if(!pairCountsMemoized.containsKey(x)) {
            pairCountsMemoized.put(x, (x * (x - 1)) / 2);
        }
        return pairCountsMemoized.get(x);
    }
}
