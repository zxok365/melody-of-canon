import java.io.*;
import java.util.*;
import java.math.*;

public class Main{
	public static void main(String [] args){
		Scanner cin = new Scanner(System.in);
		int n,m,k;
		n = cin.nextInt(); 
		m = cin.nextInt();
		k = cin.nextInt();
		BigInteger [][] c = new BigInteger[50][50];
		for (int i = 0;i <= 40;i++)
			for (int j = 0;j <= 40;j++)
				c[i][j] = BigInteger.ZERO;
		for (int i = 0;i <= 40;i++) 
			c[i][0] = BigInteger.ONE;
		for (int i = 1;i <= 40;i++)
			for (int j = 1;j <= i;j++){
				c[i][j] = c[i][j].add(c[i - 1][j - 1]);
				c[i][j] = c[i][j].add(c[i - 1][j]);
			}
		BigInteger a = BigInteger.valueOf(100);
		BigInteger b = BigInteger.valueOf(100);
		if (a != b) System.out.println("!!!");
		else System.out.println("!!");
		BigInteger [][] calc = new BigInteger[50][50];
		for (int j = 0;j <= n;j++)
			for (int jj = 0;jj <= n;jj++){
				BigInteger ret = BigInteger.ZERO;
				int pos;
				int pos2;
				if (k > j) pos = j; else pos = k;
				if ( jj < j) pos2 = j - jj; else pos2 = 0;
				for (int p = pos2;p <= pos;p++){
					BigInteger tt = BigInteger.ONE;
					if (n - p < jj) continue;
					if (jj - j + p >= 0){
						tt = tt.multiply(c[n - j][jj - j + p]);
					}
					tt = tt.multiply(c[j][p]);
					ret = ret.add(tt);
				}
				calc[j][jj] = ret;
			}
/*		
		for (int i = 0;i <= n;i++)
			for (int j = 0;j <= n;j++)
				System.out.println(i + " " + j + " " + calc[i][j]);
*/		
		BigInteger [][] f = new BigInteger[50][50];
		for (int j = 0;j <= n;j++)
			f[1][j] = c[n][j];
		for (int i = 2;i <= m;i++)
			for (int j = 0;j <= n;j++){
				int st;
			//	if (n - j - k > 0) st = n - j - k; else st = 0;
				st = 0;
				f[i][j] = BigInteger.ZERO;
				for (int jj = st;jj <= n;jj++){
					BigInteger tmp = f[i - 1][jj];
					tmp = tmp.multiply(calc[jj][j]);
					f[i][j] = f[i][j].add(tmp);
				}
			}
	/*
		for (int i = 1;i <= m;i++)
			for (int j = 0;j <= n;j++)
				System.out.println(i + " " + j + " " + f[i][j]);
	*/
			BigInteger ans = BigInteger.ZERO;
		for (int j = 0;j <= n;j++)
			ans = ans.add(f[m][j]);
		System.out.println(ans);
	}
}
