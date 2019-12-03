package solutions;

import java.util.Scanner;

public class RestrictedRPS1245B {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();

        for (int i = 0; i < T; i++) {
            int N = scanner.nextInt();

            int R = scanner.nextInt();
            int P = scanner.nextInt();
            int S = scanner.nextInt();

            String seq = scanner.next();

            String winningSeq = findWinningSequence(N, seq, R, P, S);
            if(winningSeq == null) {
                System.out.println("NO");
            }
            else {
                System.out.println("YES");
                System.out.println(winningSeq);
            }
        }
    }

    private static String findWinningSequence(int n, String seq, int r, int p, int s) {
        int half = (int) Math.ceil((double) n / 2);

        char[] finalStr = new char[n];
        for (int i = 0; i < n; i++) {
            finalStr[i] = '-';
        }

        int rCount = r, pCount = p, sCount = s;
        int totalCount = 0;

        for (int i = 0; i < n; i++) {
            switch (seq.charAt(i)) {
                case 'R':
                    if(pCount > 0) {
                        finalStr[i] = 'P';
                        pCount--;
                        totalCount++;
                    }
                    break;
                case 'P':
                    if(sCount > 0) {
                        finalStr[i] = 'S';
                        sCount--;
                        totalCount++;
                    }
                    break;
                case 'S':
                    if(rCount > 0) {
                        finalStr[i] = 'R';
                        rCount--;
                        totalCount++;
                    }
                    break;
            }
        }

        if(totalCount < half) {
            return null;
        }

        for (int i = 0; i < n; i++) {
            if(finalStr[i] == '-') {
                if(pCount > 0) {
                    finalStr[i] = 'P';
                    pCount--;
                    continue;
                }
                if(sCount > 0) {
                    finalStr[i] = 'S';
                    sCount--;
                    continue;
                }
                if(rCount > 0) {
                    finalStr[i] = 'R';
                    rCount--;
                    continue;
                }
            }
        }

        return new String(finalStr);
    }
}
