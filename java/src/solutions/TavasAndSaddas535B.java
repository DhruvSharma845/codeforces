package solutions;

import java.util.Scanner;

public class TavasAndSaddas535B {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int num = scanner.nextInt();

        System.out.println(findPositionOfNum(num));
    }

    private static Integer findPositionOfNum(int num) {
        Integer position = 0;
        if(num % 10 == 4) {
            position += 1;
        }
        else if(num % 10 == 7) {
            position += 2;
        }
        num /= 10;

        int index = 1;

        while(num != 0) {
            int dig = num % 10;
            position += (int)Math.pow(2, index);
            if(dig == 7) {
                position += (int)Math.pow(2, index);
            }
            index++;
            num /= 10;
        }

        return position;
    }
}