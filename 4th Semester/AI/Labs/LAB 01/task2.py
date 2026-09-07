import heapq
import math

class PuzzleNode:
    def __init__(self, state, parent, g_cost, h_cost):
        self.state = state
        self.parent = parent
        self.g_cost = g_cost
        self.h_cost = h_cost
        self.f_cost = g_cost + h_cost

    def __lt__(self, other):
        return self.f_cost < other.f_cost

    def generate_children(self):
        children = []
        n = 4

        for i in range(n):
            for j in range(n):
                if self.state[i][j] == 0:
                    x, y = i, j

        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            if 0 <= nx < n and 0 <= ny < n:
                new_state = [row[:] for row in self.state]
                new_state[x][y], new_state[nx][ny] = new_state[nx][ny], new_state[x][y]
                children.append(new_state)

        return children

    @staticmethod
    def calculate_heuristic(state, goal, heuristic_type):
        n = 4
        h = 0

        for i in range(n):
            for j in range(n):
                val = state[i][j]
                if val != 0:
                    for x in range(n):
                        for y in range(n):
                            if goal[x][y] == val:

                                if heuristic_type == "manhattan":
                                    h += abs(i - x) + abs(j - y)

                                elif heuristic_type == "euclidean":
                                    h += math.sqrt((i - x) ** 2 + (j - y) ** 2)

                                elif heuristic_type == "misplaced_tiles":
                                    if (i, j) != (x, y):
                                        h += 1

                                elif heuristic_type == "chebyshev":
                                    h += max(abs(i - x), abs(j - y))

                                elif heuristic_type == "tile_squared":
                                    h += (i - x) ** 2 + (j - y) ** 2

        return h


class PuzzleSolver:
    def __init__(self, start_state, goal_state):
        self.start_state = start_state
        self.goal_state = goal_state

    def is_solvable(self, state):

        def parity(s):
            flat = [x for row in s for x in row if x != 0]

            inv = sum(
                flat[i] > flat[j]
                for i in range(len(flat))
                for j in range(i + 1, len(flat))
            )

            for i in range(4):
                for j in range(4):
                    if s[i][j] == 0:
                        blank_row = 4 - i

            return (inv + blank_row) % 2

        return parity(state) == parity(self.goal_state)

    def astar_search(self, heuristic_type):

        open_list = []
        visited = set()

        h = PuzzleNode.calculate_heuristic(
            self.start_state, self.goal_state, heuristic_type
        )

        root = PuzzleNode(self.start_state, None, 0, h)
        heapq.heappush(open_list, root)

        while open_list:

            current = heapq.heappop(open_list)

            if current.state == self.goal_state:
                return current

            visited.add(tuple(map(tuple, current.state)))

            for child in current.generate_children():
                child_key = tuple(map(tuple, child))

                if child_key not in visited:
                    g = current.g_cost + 1
                    h = PuzzleNode.calculate_heuristic(
                        child, self.goal_state, heuristic_type
                    )
                    heapq.heappush(
                        open_list,
                        PuzzleNode(child, current, g, h)
                    )

        return None
    
    def trace_solution(self, node):
        path = []
        while node:
            path.append(node.state)
            node = node.parent

        path.reverse()

        for step in path:
            for row in step:
                print(row)
            print()

def main():

    initial_state = [
        [1, 2, 3, 4],
        [5, 6, 7, 8],
        [9, 10, 11, 12],
        [13, 14, 0, 15]
    ]

    goal_state = [
        [1, 2, 3, 4],
        [5, 6, 7, 8],
        [9, 10, 11, 12],
        [13, 14, 15, 0]
    ]

    solver = PuzzleSolver(initial_state, goal_state)

    print("Checking solvability...")

    if solver.is_solvable(initial_state):
        print("Puzzle is solvable.\n")

        solution = solver.astar_search("manhattan")

        if solution:
            print("Solution Path:\n")
            solver.trace_solution(solution)
        else:
            print("No solution found.")

    else:
        print("Puzzle is NOT solvable.")


if __name__ == "__main__":
    main()