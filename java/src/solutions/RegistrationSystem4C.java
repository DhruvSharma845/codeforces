import java.util.*;
public class RegistrationSystem4C {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int num = scanner.nextInt();

		Map<String, Integer> namesMap = new HashMap<>();
		for(int i = 0; i < num; i++) {
			String name = scanner.next();
			if(!namesMap.containsKey(name)) {
				System.out.println("OK");
				namesMap.put(name, 0);
			}
			else {
				int count = namesMap.get(name) + 1;
				namesMap.put(name, count);
				System.out.println(name + "" + count);
			}
		}
	}
}