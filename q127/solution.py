import string
from typing import List


class Solution(object):

    class Node(object):

        def __init__(self, word):
            self.word = word
            self.neighbors = set()

    # return all the shortest transformation sequences
    def ladderLength(self, beginWord: str, endWord: str,
                     wordList: List[str]) -> int:
        wordList = set(wordList)
        if endWord not in wordList:
            return 0

        wordList.add(beginWord)

        word_to_node = {}
        for word in wordList:
            word_to_node[word] = self.Node(word)

        for word in wordList:
            node = word_to_node[word]
            for i in range(len(word)):
                for c in string.ascii_lowercase:
                    new_word = word[:i] + c + word[i + 1:]
                    if new_word in wordList:
                        node.neighbors.add(word_to_node[new_word])

        begin_node = word_to_node[beginWord]
        end_node = word_to_node[endWord]

        depth = 0
        queue = [begin_node]
        visited = set()
        visited.add(begin_node)
        while queue:
            depth += 1
            next_queue = []
            for node in queue:
                for neighbor in node.neighbors:
                    if neighbor == end_node:
                        return depth + 1
                    if neighbor not in visited:
                        visited.add(neighbor)
                        next_queue.append(neighbor)
            queue = next_queue
        return 0


example1 = Solution().ladderLength(
    "hit", "cog", ["hot", "dot", "dog", "lot", "log", "fog", "cog"])
print(example1)
assert example1 == 5

example2 = Solution().ladderLength("hit", "cog",
                                   ["hot", "dot", "dog", "lot", "log"])
print(example2)
assert example2 == 0
