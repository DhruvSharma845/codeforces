package solutions;

import java.util.Scanner;

public class PrisonTransfer427B {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();

        int T = scanner.nextInt();

        int C = scanner.nextInt();

        int[] crimeRate = new int[N];
        for (int i = 0; i < N; i++) {
            crimeRate[i] = scanner.nextInt();
        }

        System.out.println(determineWaysToChoosePrisoners(N, T, C, crimeRate));

    }

    private static int determineWaysToChoosePrisoners(int n, int t, int c, int[] crimeRate) {
        int numOfWays = 0;
        int countOfLargerCrimeRate = 0;
        for (int i = 0; i < c; i++) {
            if(crimeRate[i] > t) {
                countOfLargerCrimeRate++;
            }
        }

        if(countOfLargerCrimeRate == 0) {
            numOfWays++;
        }

        for (int i = c; i < n; i++) {
            if(crimeRate[i - c] > t) {
                countOfLargerCrimeRate--;
            }
            if(crimeRate[i] > t) {
                countOfLargerCrimeRate++;
            }

            if(countOfLargerCrimeRate == 0) {
                numOfWays++;
            }
        }

        return numOfWays;
    }
}
