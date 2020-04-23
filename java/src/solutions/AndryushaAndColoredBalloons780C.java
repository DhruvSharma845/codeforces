import java.util.*;
public class AndryushaAndColoredBalloons780C {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int nSq = scanner.nextInt();

    Map<Integer, List<Integer>> graph = new HashMap<>();
    for(int i = 0; i < nSq - 1; i++) {
      int x = scanner.nextInt();
      int y = scanner.nextInt();

      if(!graph.containsKey(x)) {
        graph.put(x, new ArrayList<>());
      }
      graph.get(x).add(y);

      if(!graph.containsKey(y)) {
        graph.put(y, new ArrayList<>());
      }
      graph.get(y).add(x);
    }

    int[] colors = new int[nSq];
    findMinColors(nSq, graph, colors, 1);
    int cMax = Integer.MIN_VALUE;
    for(int i = 0; i < colors.length; i++) {
      if(colors[i] > cMax) {
        cMax = colors[i];
      }
    }
    System.out.println(cMax);
    Arrays.stream(colors)
      .forEach(e -> System.out.print(e + " "));
  }

  public static boolean findMinColors(int n, Map<Integer, List<Integer>> graph, int[] colors, int v) {
    boolean result = false;
    for(int i = 1; i <= n; i++) {
      if(validColor(graph, colors, v, i) == true) {
        // assign a valid color
        colors[v-1] = i;

        // recurse on neighbors
        boolean allColored = true;
        boolean res = true;
        if(graph.containsKey(v)) {
          for(Integer e: graph.get(v)) {
            if(colors[e-1] == 0) {
              allColored = false;
              if(findMinColors(n, graph, colors, e) == false) {
                res = false;
              }
            }
          }
        }
        if(allColored == true || res == true) {
          return true;
        }
      }
    }
    return result;
  }

  public static boolean validColor(Map<Integer, List<Integer>> graph, int[] colors, int v, int i) {
    if(graph.containsKey(v)) {

      //check on immediate neighbors
      for(Integer e: graph.get(v)) {
        if(colors[e-1] == i) {
          return false;
        }
        if(graph.containsKey(e)) {
          // checkn on neighbors at distance = 2
          for(Integer f: graph.get(e)) {
            if(colors[f-1] == i) {
              return false;
            }
          }
        }
      }
    }
    return true;
  }
}
