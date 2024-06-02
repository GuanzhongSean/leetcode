import heapq


class Solution:
    def clearStars(self, s: str) -> str:
        stack = []
        min_heap = []

        for _, char in enumerate(s):
            if char == '*':
                if stack:
                    # Remove the smallest character from the stack
                    smallest_char = heapq.heappop(min_heap)[1]
                    for i in range(len(stack)-1, -1, -1):
                        if stack[i] == smallest_char:
                            stack.pop(i)
                            break
            else:
                stack.append(char)
                heapq.heappush(min_heap, (char, char))

        return ''.join(stack)


print(Solution().clearStars("aaba*"))
