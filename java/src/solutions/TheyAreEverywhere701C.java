import java.util.*;
import java.util.stream.*;

public class TheyAreEverywhere701C {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int flats = sc.nextInt();
    String pokemons = sc.next();

    System.out.println(findMinFlats(flats, pokemons));
  }

  public static int findMinFlats(int flats, String pokemons) {
    int uniquePokemons =  pokemons.chars()
                                  .mapToObj(c -> (char)c)
                                  .distinct()
                                  .collect(Collectors.toList()).size();

    Map<Character, Integer> charCount = new HashMap<>();

    int left = 0, right = 0, count = 0;
    int curMinLen = Integer.MAX_VALUE;
    while(right < flats) {
      if(count == uniquePokemons) {
        int len = right - left;
        if(len < curMinLen) {
          curMinLen = len;
        }
        char c = pokemons.charAt(left);
        charCount.put(c, charCount.get(c) - 1);
        if(charCount.get(c) == 0) {
          count--;
        }
        left++;
      }
      else {
        char c = pokemons.charAt(right);
        if(!charCount.containsKey(c) || charCount.get(c) == 0) {
          count++;
          charCount.put(c, 0);
        }
        charCount.put(c, charCount.get(c) + 1);
        right++;
      }
    }

    while(left < flats && count == uniquePokemons) {
        int len = right - left;
        if(len < curMinLen) {
          curMinLen = len;
        }
        char c = pokemons.charAt(left);
        charCount.put(c, charCount.get(c) - 1);
        if(charCount.get(c) == 0) {
          count--;
        }
        left++;
    }

    return curMinLen;
  }
}
