import java.util.*;
import java.io.*;
public class BearAndTwoPaths643B {
	public static void main(String[] args) {
		FastReader fr = new FastReader();
		int N = fr.nextInt();
		int K = fr.nextInt();

		if(K <= N || N == 4) {
			System.out.println("-1");
			return;
		}

		int a = fr.nextInt();
		int b = fr.nextInt();
		int c = fr.nextInt();
		int d = fr.nextInt();

		List<Integer> firstPath = new ArrayList<>();
		firstPath.add(a);
		firstPath.add(c);
		for(int i = 1; i <= N; ++i) {
			if(i != a && i != b && i != c && i != d) {
				firstPath.add(i);
			}
		}		
		firstPath.add(d);
		firstPath.add(b);

		firstPath.stream()
			.forEach(x -> System.out.print(x + " "));

		System.out.print("\n" + c + " " + a + " ");
		for(int i = 2; i < firstPath.size() - 2; ++i) {
			System.out.print(firstPath.get(i) + " ");
		}
		System.out.print(b + " " + d + "\n");
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