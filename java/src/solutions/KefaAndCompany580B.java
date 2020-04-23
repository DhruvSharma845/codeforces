import java.util.*;
public class KefaAndCompany580B {
	public static class Pair {
		public int money;
		public int ffactor;

		public Pair(int m, int ff) {
			this.money = m;
			this.ffactor = ff;
		}
	}
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int numOfFriends = scanner.nextInt();
		int minDiff = scanner.nextInt();

		List<Pair> friends = new ArrayList<>();
		for(int i = 0; i < numOfFriends; i++) {
			int m = scanner.nextInt();
			int ff = scanner.nextInt();

			Pair p = new Pair(m, ff);
			friends.add(p);
		}

		long res = 0;
		if(numOfFriends == 1) {
			res =  friends.get(0).ffactor;
		}

		Collections.sort(friends, (a, b) -> a.money - b.money);

		res = findMaxFFactor(friends, minDiff);

		System.out.println(res);
	}

	public static long findMaxFFactor(List<Pair> friends, int minDiff) {
		int left = 0, right = 0;

		long maxFFactor = -1;
		long curFFactor = 0;
		while(right < friends.size()) {
			Pair lF = friends.get(left);
			Pair rF = friends.get(right);
			if((rF.money - lF.money) < minDiff) {
				right++;
				curFFactor += rF.ffactor;
			}
			else {
				if(curFFactor > maxFFactor) {
					maxFFactor = curFFactor;
				}
				curFFactor -= lF.ffactor; 
				left++;
			}
		}
		if(curFFactor > maxFFactor) {
			maxFFactor = curFFactor;
		}
		return maxFFactor;
	}
}