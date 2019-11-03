package solutions;

import java.util.Scanner;

public class MakeProductEqualOne1206B {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int N;
        N = sc.nextInt();

        long[] numbers = new long[N];
        for(int i = 0; i < N; i++) {
            numbers[i] = sc.nextLong();
        }

        System.out.println(findMinimumCoinsToMakeProductOne(numbers, N));
    }

    public static long findMinimumCoinsToMakeProductOne(long[] numbers, int size) {
        long count = 0;

        int negCount = 0;

        long minDistance = Long.MAX_VALUE;
        int closestIndex = -1;


        // count the number of negative numbers
        for(int i = 0; i < size; i++) {
            if(numbers[i] < 0) {
                negCount++;
                long currentValue = Math.abs(1 - numbers[i]);
                if(currentValue < minDistance) {
                    minDistance = currentValue;
                    closestIndex = i;
                }
            }
            else {
                long currentValue = Math.abs(numbers[i] + 1);
                if(currentValue < minDistance) {
                    minDistance = currentValue;
                    closestIndex = i;
                }
            }
        }

        // the # of negative numbers is even
        if(negCount % 2 == 0) {
            for(int i = 0; i < size; i++) {
                if(numbers[i] < 0) {
                    count += Math.abs(-1 - (numbers[i]));
                }
                else {
                    count += Math.abs(numbers[i] - 1);
                }
            }
        }
        else {
            for (int i = 0; i < size; i++) {
                if(i != closestIndex) {
                    if(numbers[i] < 0) {
                        count += Math.abs(-1 - (numbers[i]));
                    }
                    else {
                        count += Math.abs(numbers[i] - 1);
                    }
                }
                else {
                    count += minDistance;
                }
            }

        }

        return count;
    }
}
