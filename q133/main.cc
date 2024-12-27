#include <gtest/gtest.h>

#include "Utils.h"
#include "solution.cc"

int main() {
  Graph graph{{{2, 4}, {1, 3}, {2, 4}, {1, 3}}};
  print(&graph);
  auto result = q133::Solution().cloneGraph(graph[0]);
  print("Result:", result);
  EXPECT_EQ(result->val, 1);
  EXPECT_EQ(result->neighbors.size(), 2);
  EXPECT_EQ(result->neighbors[0]->val, 2);
  EXPECT_EQ(result->neighbors[1]->val, 4);
  print_human_readable_typename<decltype(result)>();
}
