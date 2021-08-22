import java.io.*;

public class helloworld {

    public static void main(String[] args) throws NumberFormatException, IOException {

        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(in.readLine());
        while (t-- > 0)
            solve(in);

    }

    public static void solve(BufferedReader in) throws NumberFormatException, IOException {

        String s[] = in.readLine().split(" ");
        int a = Integer.parseInt(s[0]), b = Integer.parseInt(s[1]), k = Integer.parseInt(s[2]);

        if (a > b) {
            int t = a;
            a = b;
            b = t;
        }

        int U = calc(a) + calc(b);
        int D;
        if (b % a == 0 && a != b)
            D = 1;
        else
            D = 2;

        if (D <= k && k <= U)
            System.out.println("YES");
        else
            System.out.println("NO");
    }

    static int calc(int x) {
        int res = 0;

        for (int i = 2; i * i <= x; ++i)
            while (x % i == 0) {
                ++res;
                x /= i;
            }

        if (x > 1)
            ++res;

        return res;
    }

}
