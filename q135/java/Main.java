import q135_src.Solution;

public class Main {
    public static void main(String[] args) {
        int[] arr = {4, 1, 0, 2, 3, 5, 6, 7, 8, 9};
        int result = Solution.candy(arr);

        System.out.println("Number of candies need: " + result);
        assert result == 41 : "Test failed";
    }
}
