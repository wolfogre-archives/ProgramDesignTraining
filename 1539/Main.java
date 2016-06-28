import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		while (scanner.hasNextInt())
		{
			int n = scanner.nextInt();
			int m = scanner.nextInt();
			int k = 1;
			while (true)
			{
				int r = n + k;
				if((r % 7) == 0 || HaveSenve(r)){
					if (m != 0)
						--m;
					if (m == 0)
					{
						System.out.println("" + r);
						break;
					}
				}
				++k;
			}
		}
	}
	public static boolean HaveSenve(int n){
		String str = "" + n;
		char[] cc = str.toCharArray(); 
		for(char ch : cc){
			if(ch == '7')
				return true;
		}
		return false;
	}
}