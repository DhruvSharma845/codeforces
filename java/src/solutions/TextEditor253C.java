import java.util.*;
import java.io.*;

public class TextEditor253C {
	public static void main(String[] args) throws FileNotFoundException, IOException {
		BufferedReader br = new BufferedReader(new FileReader("input.txt"));
		int N = Integer.parseInt(br.readLine());

		String[] nChars = br.readLine().split(" ");
		int[] numChars = Arrays.stream(nChars)
							.mapToInt(x -> Integer.parseInt(x))
							.toArray();

		String[] points = br.readLine().split(" ");
		int sRow = Integer.parseInt(points[0]);
		int sCol = Integer.parseInt(points[1]);

		int eRow = Integer.parseInt(points[2]);
		int eCol = Integer.parseInt(points[3]);

		int res =  0;
		res = minimumPushes(numChars, sRow-1, sCol-1, eRow-1, eCol-1);	
		FileWriter fileWriter = new FileWriter("output.txt");
    	PrintWriter printWriter = new PrintWriter(fileWriter);
    	printWriter.print(Integer.toString(res));
    	printWriter.close();
	}

	public static int minimumPushes(int[] numChars, int sR, int sC, int eR, int eC) {
		Queue<Pair> q = new LinkedList<>();
		int colLimit = 100001;
		boolean[][] visited = new boolean[numChars.length][colLimit];

		Pair p = new Pair();
		p.x = sR;
		p.y = sC;
		p.depth = 0;
		q.offer(p);

		while(q.size() > 0) {
			Pair pair = q.poll();
			int curX = pair.x;
			int curY = pair.y;
			int curDepth = pair.depth;
			if(curX == eR && curY == eC) {
				return curDepth;
			}
			// right
			if(curY < numChars[curX] && eC >= curY) {
				Pair nextP = new Pair();
				nextP.x = curX;
				nextP.y = curY + 1;
				if(visited[nextP.x][nextP.y] == false) {
					nextP.depth = curDepth + 1;
					q.offer(nextP);
					visited[nextP.x][nextP.y] = true;
				}
			}
			// left
			if(curY > 0 && eC <= curY) {
				Pair nextP = new Pair();
				nextP.x = curX;
				nextP.y = curY - 1;
				if(visited[nextP.x][nextP.y] == false) {
					nextP.depth = curDepth + 1;
					q.offer(nextP);
					visited[nextP.x][nextP.y] = true;
				}	
			}
			// up
			if(curX > 0) {
				Pair nextP = new Pair();
				nextP.x = curX - 1;
				nextP.y = Math.min(curY, numChars[curX-1]);
				if(visited[nextP.x][nextP.y] == false) {
					nextP.depth = curDepth + 1;
					q.offer(nextP);
					visited[nextP.x][nextP.y] = true;
				}
			}
			// down
			if(curX < numChars.length - 1) {
				Pair nextP = new Pair();
				nextP.x = curX + 1;
				nextP.y = Math.min(curY, numChars[curX+1]);
				if(visited[nextP.x][nextP.y] == false) {
					nextP.depth = curDepth + 1;
					q.offer(nextP);
					visited[nextP.x][nextP.y] = true;
				}
			}
		}
		return -1;
	}

	static class Pair {
		public int x;
		public int y;
		public int depth;
	}
}