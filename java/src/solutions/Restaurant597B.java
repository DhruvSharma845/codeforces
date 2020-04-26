import java.util.*;
import java.io.*;

public class Restaurant597B {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int N = scanner.nextInt();

		Pair[] times = new Pair[N];
		for (int i = 0; i < N; ++i) {
			Pair p = new Pair();
			p.l = scanner.nextInt();
			p.r = scanner.nextInt();
			times[i] = p;
		}

		Arrays.sort(times, (a, b) -> a.r - b.r);

		int m = 0;
		int count = 1;
		for (int i = 1; i < N; i++) {
			if(times[i].l > times[m].r) {
				count++;
				m = i;
			}
		}
		System.out.println(count);
	}

	static class Pair {
		public int l;
		public int r;
	}
}