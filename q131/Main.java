import java.util.List;
import src.Solution;

public class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        String testString = "aab";
        List<List<String>> partitions = solution.partition(testString);

        System.out.println("Partitions for \"" + testString + "\":");
        for (List<String> partition : partitions) {
            System.out.println(partition);
        }
    }
}
