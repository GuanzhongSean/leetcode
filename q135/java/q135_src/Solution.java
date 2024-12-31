package q135_src;

import java.util.*;

public class Solution {
    public static int candy(int[] ratings) {
        int n = ratings.length;
        Integer[] ranks = new Integer[n];
        for (int i = 0; i < n; i++) {
            ranks[i] = i;
        }
        Arrays.sort(ranks, (Integer i, Integer j) -> Integer.compare(ratings[i], ratings[j]));

        System.out.print("[ ");
        for (var i : ranks) {
            System.out.print(i + " ");
        }
        System.out.println("]");

        int[] candies = new int[n];
        Arrays.fill(candies, 1);

        for (int i = 0; i < n; i++) {
            int cur = ranks[i];
            if (cur != 0 && ratings[cur] > ratings[cur - 1])
                candies[cur] = candies[cur - 1] + 1;
            if (cur != n - 1 && ratings[cur] > ratings[cur + 1])
                candies[cur] = Math.max(candies[cur], candies[cur + 1] + 1);
        }

        int count = 0;
        for (int i : candies)
            count += i;

        return count;
    }

    static class AnothorSolution {
        public static int candy(int[] ratings) {
            int n = ratings.length;
            int i = 1;
            int cnt = 1;

            while (i < n) {
                if (ratings[i] == ratings[i - 1]) {
                    cnt++;
                    i++;
                    continue;
                }

                int peak = 1;
                while (i < n && ratings[i - 1] < ratings[i]) {
                    peak++;
                    cnt += peak;
                    i++;
                }
                int down = 1;
                while (i < n && ratings[i - 1] > ratings[i]) {
                    cnt += down;
                    down++;
                    i++;
                }
                if (down > peak)
                    cnt += down - peak;
            }
            return cnt;
        }
    }
}
