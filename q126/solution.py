import collections
import string
from typing import List


class Solution(object):
    class Node(object):
        def __init__(self, word):
            self.word = word
            self.neighbors = set()

    # return all the shortest transformation sequences
    def findLadders(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: List[List[str]]
        """
        wordList = set(wordList)
        if endWord not in wordList:
            return []

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

        result = []
        queue = [[begin_node]]
        found = False
        while queue:
            new_queue = []
            for path in queue:
                node = path[-1]
                if node == end_node:
                    found = True
                    result.append([node.word for node in path])
                else:
                    for neighbor in node.neighbors:
                        if neighbor not in path:
                            new_queue.append(path + [neighbor])
            if found:
                break
            queue = new_queue
        return result


class Solution2:  # 44 ms, faster than 86.16%
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        wordSet = set(wordList)  # to check if a word is existed in the wordSet, in O(1)
        wordSet.discard(beginWord)

        def neighbors(word):
            for i in range(len(word)):  # change every possible single letters and check if it's in wordSet
                for c in string.ascii_lowercase:
                    newWord = word[:i] + c + word[i + 1:]
                    if newWord in wordSet:
                        yield newWord

        level = {}
        # level[word] is all possible sequence paths which start from beginWord and end at `word`.
        level[beginWord] = [[beginWord]]
        while level:
            nextLevel = collections.defaultdict(list)
            for word, paths in level.items():
                if word == endWord:
                    return paths  # return all shortest sequence paths
                for nei in neighbors(word):
                    for path in paths:
                        # form new paths with `nei` word at the end
                        nextLevel[nei].append(path + [nei])
            wordSet -= set(nextLevel.keys())  # remove visited words to prevent loops
            level = nextLevel  # move to new level

        return []


example = Solution().findLadders("hit", "cog", ["hot", "dot", "dog", "lot", "log", "fog", "cog"])
assert example == [['hit', 'hot', 'dot', 'dog', 'cog'], ['hit', 'hot', 'lot', 'log', 'cog']]
print(example)

