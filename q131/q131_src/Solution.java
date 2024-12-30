package q131_src;

import java.util.ArrayList;
import java.util.List;

public class Solution {
    private List<List<String>> partitions;

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

    private void helper(String s, List<String> cur) {
        if (s.isEmpty()) {
            partitions.add(new ArrayList<>(cur));
            return;
        }

        int n = s.length();
        for (int i = 1; i <= n; i++) {
            String sub_s = s.substring(0, i);
            if (isPalindrome(sub_s)) {
                cur.add(sub_s);
                helper(s.substring(i), cur);
                cur.remove(cur.size() - 1);
            }
        }
    }

    public List<List<String>> partition(String s) {
        partitions = new ArrayList<>();
        helper(s, new ArrayList<>());
        return partitions;
    }
}
