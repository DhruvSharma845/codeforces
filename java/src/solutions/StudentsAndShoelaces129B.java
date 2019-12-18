package solutions;

import java.util.*;

public class StudentsAndShoelaces129B {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int students = scanner.nextInt();
        int laces = scanner.nextInt();

        int groups = processStudentsAndLaces(students, laces, scanner);
        System.out.println(groups);
    }

    private static int processStudentsAndLaces(int students, int laces, Scanner scanner) {
        Map<Integer, Set<Integer>> graph = new HashMap<>();

        int[] numOfLacesTiedToStudent = new int[students+1];
        for (int i = 0; i < laces; i++) {
            int src = scanner.nextInt();
            int dest = scanner.nextInt();

            if(!graph.containsKey(src)) {
                graph.put(src, new HashSet<>());
            }
            graph.get(src).add(dest);
            if(!graph.containsKey(dest)) {
                graph.put(dest, new HashSet<>());
            }
            graph.get(dest).add(src);

            numOfLacesTiedToStudent[src]++;
            numOfLacesTiedToStudent[dest]++;
        }

        Queue<Integer> q = new LinkedList<>();
        for (int i = 1; i <= students; i++) {
            if(numOfLacesTiedToStudent[i] == 1) {
                q.add(i);
                numOfLacesTiedToStudent[i] = -1;
            }
        }
        int numGroups = 0;
        while(!q.isEmpty()) {
            numGroups++;
            Queue<Integer> nextLevelQ = new LinkedList<>();
            while(!q.isEmpty()) {
                int student = q.poll();
                if(graph.containsKey(student)) {
                    for(Integer neighbor: graph.get(student)) {
                        numOfLacesTiedToStudent[neighbor]--;
                    }
                }
            }
            for (int i = 1; i <= students; i++) {
                if(numOfLacesTiedToStudent[i] == 1) {
                    nextLevelQ.add(i);
                    numOfLacesTiedToStudent[i] = -1;
                }
            }
            q = nextLevelQ;
        }
        return numGroups;
    }
}
