import q132_src.Solution;

public class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        String testString = "aab";
        var result = solution.minCut(testString);

        System.out.println("Min cut for \"" + testString + "\": " + result);
        assert result == 1 : "Test failed!";
    }
}
