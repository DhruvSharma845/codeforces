package solutions;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class DominatedSubarray1257C {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();

        for (int i = 0; i < T; i++) {
            int N = scanner.nextInt();
            int[] arr = new int[N];
            for (int j = 0; j < N; j++) {
                arr[j] = scanner.nextInt();
            }

            System.out.println(findLengthOfShortestDominatedSubArray(N, arr));
        }
    }

    private static int findLengthOfShortestDominatedSubArray(int n, int[] arr) {
        if(n == 1) {
            return -1;
        }

        Map<Integer, Integer> lastPositions = new HashMap<>();
        int minLength = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            if(lastPositions.containsKey(arr[i])) {
                minLength = Math.min(minLength, i - lastPositions.get(arr[i]) + 1);
            }
            lastPositions.put(arr[i], i);
        }

        return (minLength == Integer.MAX_VALUE) ? -1 : minLength;
    }
}
