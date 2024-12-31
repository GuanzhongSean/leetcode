using System;

namespace q134
{
    public class Program
    {
        public static void Main()
        {
            // Manual testing of Solution
            var solution = new Solution();
            int[] gas = { 1, 2, 3, 4, 5 };
            int[] cost = { 3, 4, 5, 1, 2 };
            Console.WriteLine(solution.CanCompleteCircuit(gas, cost)); // Expected: 3

            int[] gas2 = { 2, 3, 4 };
            int[] cost2 = { 3, 4, 3 };
            Console.WriteLine(solution.CanCompleteCircuit(gas2, cost2)); // Expected: -1
        }
    }
}
