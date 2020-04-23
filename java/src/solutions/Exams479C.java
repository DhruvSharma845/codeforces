import java.util.*;
public class Exams479C {

	private static class Pair {
		public int actualDate;
		public int earlyDate;

		public Pair(int ad, int ed) {
			this.actualDate = ad;
			this.earlyDate = ed;
		}
	}

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		int subjects = scanner.nextInt();

		List<Pair> pairs = new ArrayList<>();
		for(int i = 0; i < subjects; i++) {
			int ad = scanner.nextInt();
			int ed = scanner.nextInt();

			Pair pair = new Pair(ad, ed);
			pairs.add(pair);
		}

		Collections.sort(pairs, (p1, p2) -> {
			if(p1.actualDate == p2.actualDate) {
				return p1.earlyDate - p2.earlyDate;
			}
			return p1.actualDate - p2.actualDate;
		});

		if(isSortedByEarlyDate(pairs) == true) {
			System.out.println(pairs.get(pairs.size() - 1).earlyDate);
		} 
		else {
			System.out.println(pairs.get(pairs.size() - 1).actualDate);
		}
	}

	public static boolean isSortedByEarlyDate(List<Pair> pairs) {
		for(int i = 0; i < pairs.size() - 1; i++) {
			if(pairs.get(i).earlyDate > pairs.get(i+1).earlyDate) {
				return false;
			}
		}
		return true;
	}
}