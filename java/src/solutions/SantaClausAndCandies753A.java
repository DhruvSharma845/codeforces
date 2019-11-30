package solutions;

import java.util.*;

public class SantaClausAndCandies753A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int candies = scanner.nextInt();

        List<Integer> candiesForKids = findCandiesForKids(candies);
        System.out.println(candiesForKids.size());
        candiesForKids.stream().forEach(c -> {
            System.out.print(c + " ");
        });
    }

    private static List<Integer> findCandiesForKids(int candies) {
        Set<Integer> candiesForKids = new HashSet<>();

        int num = 0;
        int sum = 0;
        while(sum < candies) {
            num++;
            candiesForKids.add(num);
            sum += num;
        }
        if(sum > candies) {
            candiesForKids.remove(sum - candies);
        }
        return new ArrayList<>(candiesForKids);
    }
}
