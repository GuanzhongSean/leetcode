import libGraph
from libGraph import Node, Graph


class Solution(object):

    def cloneGraph(self, node):
        """
        :type node: Node
        :rtype: Node
        """
        if not node:
            return None

        mapping = {}
        queue = [node]
        clone_node = Node(node.val)
        mapping[node] = clone_node

        while queue:
            current_node = queue.pop(0)
            for neighbor in current_node.neighbors:
                # If the neighbor has not been visited
                if neighbor not in mapping:
                    # Create a clone of the neighbor
                    clone_neighbor = Node(neighbor.val)
                    mapping[neighbor] = clone_neighbor

                    # Add the neighbor to the queue
                    queue.append(neighbor)

                # Add the cloned neighbor to the current cloned node's neighbors
                n = mapping[current_node].neighbors
                n.append(mapping[neighbor])
                mapping[current_node].neighbors = n

        return clone_node


# Create a graph using an adjacency list
adj_list = [[2, 3], [3], [1]]
graph = libGraph.Graph(adj_list)
graph.print()
clone_node = Solution().cloneGraph(graph[0])
print("Cloned graph:")
clone_node.print()
assert clone_node.val == graph[0].val
assert clone_node.neighbors[0].val == graph[0].neighbors[0].val
assert id(clone_node) != id(graph[0])
