import java.io.*;
import java.util.*;

public class Winner2A {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		
		int N = s.nextInt();

		Map<String, Integer> scores = new HashMap<>();
		Map<Integer, Set<String>> scoresWithUsers = new TreeMap<>();
		for(int i = 0; i < N; i++) {
			String name = s.next();
			int score = s.nextInt();
			
			if(!scores.containsKey(name)) {
				scores.put(name, 0);
			}
			int finalScore = scores.get(name) + score;
			scores.put(name, finalScore);

			if(!scoresWithUsers.containsKey(finalScore)) {
				scoresWithUsers.put(finalScore, );
			}

		}
		
	}
}