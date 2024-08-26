import java.util.Scanner;

public class cr {
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int K = sc.nextInt();

        int[] nums = new int[N];
        for (int n = 0; n < N; n++) nums[n] = sc.nextInt();

        for (int k = 0; k < K; k++)
        {
            int num = sc.nextInt();
            
            int lo = 0;
            int hi = N - 1;
            int ans = N + 1;

            while (lo <= hi)
            {
                int m = lo + (hi - lo + 1)/2;

                if (nums[m] >= num)
                {
                    ans = m + 1;
                    hi = m - 1;
                }
                else if (num > nums[m])
                {
                    lo = m + 1;
                }
            }

            System.out.println(ans);
        }
        sc.close();
    }
}