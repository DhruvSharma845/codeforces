package solutions;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class CrosswordSolving822B {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int M = scanner.nextInt();

        String p = scanner.next();
        String q = scanner.next();

        findMaximumOverlappingSubstring(N, M, p, q);
    }

    private static void findMaximumOverlappingSubstring(int n, int m, String p, String q) {
        int matchingChars = 0;
        int maxMatchingChars = 0;
        List<Integer> positions = new ArrayList<>();
        List<Integer> finalPositions = new ArrayList<>();
        for (int i = 0; i <= q.length() - p.length(); i++) {
            matchingChars = 0;
            int k = i;
            int mismatchChars = 0;
            positions.clear();

            for (int j = 0; j < p.length(); j++) {
                if(p.charAt(j) == q.charAt(k)) {
                    matchingChars++;
                }
                else {
                    mismatchChars++;
                    positions.add(j+1);
                    if(mismatchChars > (p.length() - maxMatchingChars)) {
                        break;
                    }
                }
                k++;
            }

            if((matchingChars > maxMatchingChars) || (maxMatchingChars == 0)) {
                finalPositions.clear();
                finalPositions.addAll(positions);
            }
            if(matchingChars > maxMatchingChars) {
                maxMatchingChars = matchingChars;
            }
        }

        System.out.println((p.length() - maxMatchingChars));
        finalPositions.stream().forEach(x -> System.out.print(x + " "));
    }
}
