import java.util.*;
import java.io.*;

public class EvenPath1252C {
	public static void main(String[] args) {
		FastReader fr = new FastReader();
		int N = fr.nextInt();
		int Q = fr.nextInt();

		int[] R = new int[N];
		int[] C = new int[N];

		for(int i = 0; i < N; ++i) {
			R[i] = fr.nextInt();
		}
		for(int i = 0; i < N; ++i) {
			C[i] = fr.nextInt();
		}

		Map<String, Set<String>> reachable = new HashMap<>();
		for(int j = 0; j < Q; ++j) {
			int ra = fr.nextInt();
			int ca = fr.nextInt();
			int rb = fr.nextInt();
			int cb = fr.nextInt();
			ra--;
			ca--;
			rb--;
			cb--;
			if(!reachable.containsKey(ra + "|" + ca)) {
				reachable.put(ra + "|" + ca, new HashSet<>());
			}
			isReachable(R, C, ra, ca, rb, cb, reachable);
			if(reachable.containsKey(ra + "|" + ca)) {
				Set<String> dest = reachable.get(ra + "|" + ca);
				if(dest.contains(rb + "|" + cb)) {
					System.out.println("YES");	
				}
				else {
					System.out.println("NO");
				}
			}
			else {
				System.out.println("NO");
			}
		}
	}

	static class Pair {
		public int a;
		public int b;
	}

	public static void isReachable(int[] R, int[] C, int ra, int ca, int rb, int cb, Map<String, Set<String>> reachable) {
		boolean[][] visited = new boolean[R.length][C.length];
		int[] rowInc = {0, -1, 0, 1};
		int[] colInc = {1, 0, -1, 0};

		int srcV = R[ra] + C[ca];
		int destV = R[rb] + C[cb];

		Set<String> reachVer = reachable.get(ra + "|" + ca);
		if(reachVer.contains(rb + "|" + cb)) {
			return;
		}

		Queue<Pair> queue = new LinkedList<>();
		
		Pair p = new Pair();
		p.a = ra;
		p.b = ca;

		queue.add(p);
		visited[ra][ca] = true;

		while(queue.size() > 0) {
			Pair curP = queue.poll();

			for(int i = 0; i < 4; ++i) {
				int nextR = curP.a + rowInc[i];
				int nextC = curP.b + colInc[i];

				if(nextR < 0 || nextR > R.length - 1 || nextC < 0 || nextC > C.length - 1 || visited[nextR][nextC] == true) {
					continue;
				}

				int val = R[nextR] + C[nextC];
				if(val % 2 == 0) {
					Pair nextP = new Pair();
					nextP.a = nextR;
					nextP.b = nextC;
					queue.add(nextP);

					reachVer.add(nextR + "|" + nextC);
					visited[nextR][nextC] = true;

					if(!reachable.containsKey(nextR + "|" + nextC)) {
						reachable.put(nextR + "|" + nextC, new HashSet<>());
					}
					Set<String> rV = reachable.get(nextR + "|" + nextC);
					rV.add(ra + "|" + ca);
					if(rV.contains(rb + "|" + cb)) {
						reachVer.addAll(rV);
						return;
					}
				}
				if(nextR == rb && nextC == cb) {
					return;
				}
			}
		}
	}

	static class FastReader { 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastReader() { 
            br = new BufferedReader(new InputStreamReader(System.in)); 
        } 
  
        String next() { 
            while (st == null || !st.hasMoreElements()) { 
                try { 
                    st = new StringTokenizer(br.readLine()); 
                } catch (IOException  e) { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 
  
        int nextInt() { 
            return Integer.parseInt(next()); 
        } 
  
        long nextLong() { 
            return Long.parseLong(next()); 
        } 
  
        double nextDouble() { 
            return Double.parseDouble(next()); 
        } 
  
        String nextLine() { 
            String str = ""; 
            try { 
                str = br.readLine(); 
            } catch (IOException e) { 
                e.printStackTrace(); 
            } 
            return str; 
        } 
    }
}