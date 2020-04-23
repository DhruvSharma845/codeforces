import java.util.*;

public class Mentors978F {
	public static void main(String[] args) {
		Mentors m = new Mentors();
		m.findInternsForMentors();
	}

	private static class Mentors {
		public void findInternsForMentors() {
			Scanner sc = new Scanner(System.in);
			int nP = sc.nextInt();
			int k = sc.nextInt();

			int[] skills = new int[nP];
			for(int i = 0; i < nP; i++) {
				skills[i] = sc.nextInt();
			}

			int[] B = skills.clone();

			Arrays.sort(B);

			Map<Integer, Integer> quarrelMap = new HashMap<>();
			for(int i = 0; i < k; i++) {
				int x = sc.nextInt();
				int y = sc.nextInt();

				if(skills[x-1] > skills[y-1]) {
					if(!quarrelMap.containsKey(x-1)) {
						quarrelMap.put(x-1, 0);
					}
					quarrelMap.put(x-1, quarrelMap.get(x-1) + 1);
				}
				if(skills[x-1] < skills[y-1]) {
					if(!quarrelMap.containsKey(y-1)) {
						quarrelMap.put(y-1, 0);
					}
					quarrelMap.put(y-1, quarrelMap.get(y-1) + 1);
				}
			}
			// 1 1 2 3 4 4 5 5 5 7
			for(int i = 0; i < nP; i++) {
				int skill = skills[i];
				int index = upperBound(B, skill-1, 0, B.length - 1);
				if(index == -1) {
					System.out.print("0 ");
				}
				else {
					int res = index + 1 - (quarrelMap.containsKey(i) ? quarrelMap.get(i) : 0);
					if(res < 0) {
						System.out.print("0 ");
					}
					else {
						System.out.print(res + " ");
					}
				}
			}
		}
		public int upperBound(int[] arr, int key, int low, int high) {
			if(high < low) {
				return -1;
			}
			int mid = low + (high - low)/2;
			//System.out.print("Key: " + key + " mid: " + mid + "   ");

			if(mid > low && arr[mid-1] <= key && arr[mid] > key) {
				return (mid-1);
			}
			if(mid < high && arr[mid] <= key && arr[mid+1] > key) {
				return mid;
			}
			if(arr[mid] <= key) {
				return upperBound(arr, key, mid+1, high);
			}
			else {
				return upperBound(arr, key, low, mid-1);
			}
		}
	}
}