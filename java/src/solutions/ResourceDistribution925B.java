import java.util.*;
import java.io.*;

public class ResourceDistribution925B {
	static class Pair {
		public int ser;
		public int ind;
	}
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int numServers = scanner.nextInt();

		int service1 = scanner.nextInt();
		int service2 = scanner.nextInt();

		Pair[] servers = new Pair[numServers];
		for (int i = 0; i < numServers; ++i) {
			servers[i] = new Pair();
			servers[i].ser = scanner.nextInt();
			servers[i].ind = i;
		}

		determineServersForBothServices(numServers, servers, service1, service2);
	}

	public static void determineServersForBothServices(int numServers, Pair[] servers, int service1, int service2) {
		StringBuilder sb1 = new StringBuilder("");
		int count1 = 0;	
		StringBuilder sb2 = new StringBuilder("");
		int count2 = 0;

		int service1Start = -1;
		int service1Servers = 0;
			

		Arrays.sort(servers, (a, b) -> a.ser - b.ser);

		boolean flag = false;
		
		for(int i = 1; i <= numServers; ++i) {
			int p1 = (service1 / i) + ((service1 % i == 0) ? 0 : 1);
			//System.out.println("p1: " + p1);
			int index = findCeil(servers, p1);
			if(index == -1 || index + i > numServers) {
				continue;
			}
			//System.out.println("Index: " + index);
			int count = 0;
			StringBuilder sb2Temp = new StringBuilder("");
			
			for(int j = numServers - 1; j >= 0; j--) {
				if(j < index || j >= index + i) {
					sb2Temp.insert(0, (servers[j].ind+1) + " ");
					count++;
				}
				else {
					continue;
				}
				int p2 = service2 / count + ((service2 % count == 0) ? 0 : 1);
				//System.out.println("p2: " + p2);
				if(servers[j].ser >= p2) {
					//System.out.println("j: " + j);
					flag = true;
					break;
				}
			}
			if(flag == true) {
				service1Start = index;
				service1Servers = i;
				sb2 = sb2Temp;
				count2 = count;
				break;
			}
		}

		if(flag == true) {
			System.out.println("Yes");
			for(int i = service1Start; i < service1Start + service1Servers; i++) {
				sb1.append((servers[i].ind+1) + " ");
				count1++;
			}
			System.out.println(count1 + " " + count2);
			System.out.println(sb1.toString());
			System.out.println(sb2.toString());
		}
		else {
			System.out.println("No");	
		}
	}

	public static int findCeil(Pair[] A, int x) {
        int left = 0, right = A.length - 1;
 
        int ceil = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
 
            if (A[mid].ser == x) {
                return mid;
            }
            else if (x < A[mid].ser) {
                ceil = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        return ceil;
    }
 
}