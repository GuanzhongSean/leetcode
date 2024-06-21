from collections import defaultdict
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


class Solution:
    def clearStars(self, s: str) -> str:
        heap = []
        charIndex = defaultdict(list)
        s = list(s)
        for i, c in enumerate(s):
            if c == "*":
                toRemove = heap[0]
                s[charIndex[toRemove].pop()] = ""
                if not charIndex[toRemove]:
                    heapq.heappop(heap)
                s[i] = ""
            else:
                if len(charIndex[c]) == 0:
                    heapq.heappush(heap, c)
                charIndex[c].append(i)
        return "".join(s)


print(Solution().clearStars("aaba*"))
