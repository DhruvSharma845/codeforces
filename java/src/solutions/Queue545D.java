import java.util.*;
public class Queue545D {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int n = scanner.nextInt();

		int[] arr = new int[n];
		for(int i = 0; i < n; i++) {
			arr[i] = scanner.nextInt();
		}

		int res = findMinDisappointedPeople(n, arr); 
		System.out.println(res);
	}

	public static int findMinDisappointedPeople(int n, int[] arr) {
		Arrays.sort(arr);
		int sum = 0;
		int count = 0;
		for(int i = 0; i < n; i++) {
			if(sum <= arr[i]) {
				count++;
				sum += arr[i];
			}
		}
		return count;
	}
}