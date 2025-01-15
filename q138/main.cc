#include <gtest/gtest.h>

#include "Node.h"
#include "Utils.h"
#include "solution.cc"

constexpr auto null = Random::Node::null;

int main() {
	Random::Node* head = new Random::Node({{7, null}, {13, 0}, {11, 4}, {10, 2}, {1, 0}});
	print(head);
	auto result = q138::Solution().copyRandomList(head);
	print("Result:", result);
	EXPECT_EQ(result->val, 7);
	EXPECT_EQ(result->random, nullptr);
	EXPECT_EQ(result->next->val, 13);
	EXPECT_EQ(result->next->random->val, 7);
	EXPECT_EQ(result->next->random, result);
	EXPECT_EQ(result->next->random->next->next->val, 11);
	print_human_readable_typename<decltype(result)>();
}
