package src;

public class Solution {
    private boolean isPalindrome(String s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s.charAt(i) != s.charAt(j)) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    public int minCut(String s) {
        int n = s.length();
        int[] dp = new int[n];
        for (int i = 0; i < n; i++) {
            dp[i] = i;
        }
        for (int i = 0; i < n; i++) {
            if (isPalindrome(s.substring(0, i + 1))) {
                dp[i] = 0;
            } else {
                for (int j = 0; j < i; j++) {
                    if (isPalindrome(s.substring(j + 1, i + 1))) {
                        dp[i] = Math.min(dp[i], dp[j] + 1);
                    }
                }
            }
        }
        return dp[n - 1];
    }
}

class Solution2 {
    public int minCut(String s) {
        int n = s.length();
        char[] seq = s.toCharArray();
        int[] dp = new int[n + 1];
        for (int i = 0; i <= n; i++)
            dp[i] = i - 1;

        for (int i = 1; i <= n; i++) {
            int lo = i - 1;
            int prev = dp[i - 1];
            dp[i] = Math.min(dp[i], prev + 1);
            while (i < n && seq[i - 1] == seq[i]) {
                i++;
                prev = Math.min(dp[i - 1], prev);
                dp[i] = Math.min(dp[i], prev + 1);
            }

            int hi = i + 1;
            while (lo > 0 && hi <= n && seq[lo - 1] == seq[hi - 1]) {
                dp[hi] = Math.min(dp[hi], dp[lo - 1] + 1);
                lo--;
                hi++;
            }
        }

        return dp[n];
    }
}
