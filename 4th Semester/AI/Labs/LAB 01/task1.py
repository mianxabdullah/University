class Puzzle:
    def __init__(self, initial_state, goal_state):
        self.initial_state = initial_state
        self.goal_state = goal_state
        self.n = 4  

    def is_solvable(self, state):
        def parity(s):
            flat = [tile for row in s for tile in row if tile != 0]
            I = 0
            for i in range(len(flat)):
                for j in range(i + 1, len(flat)):
                    if flat[i] > flat[j]:
                        I += 1

            for i in range(self.n):
                for j in range(self.n):
                    if s[i][j] == 0:
                        R = self.n - i

            return (I + R) % 2

        return parity(state) == parity(self.goal_state)

    def generate_moves(self, state):
        moves = []

        for i in range(self.n):
            for j in range(self.n):
                if state[i][j] == 0:
                    x, y = i, j

        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            if 0 <= nx < self.n and 0 <= ny < self.n:
                new_state = [row[:] for row in state]
                new_state[x][y], new_state[nx][ny] = new_state[nx][ny], new_state[x][y]
                moves.append(new_state)

        return moves
    
    def depth_limited_search(self, state, depth, visited):
        if state == self.goal_state:
            return [state]

        if depth == 0:
            return None

        visited.add(tuple(map(tuple, state))) 

        for move in self.generate_moves(state):
            state_key = tuple(map(tuple, move))
            if state_key not in visited:
                result = self.depth_limited_search(move, depth - 1, visited)
                if result:
                    return [state] + result

        return None

    def iddfs(self, max_depth=20):
        if not self.is_solvable(self.initial_state):
            return "Puzzle is NOT solvable."

        for depth in range(max_depth):
            visited = set()
            result = self.depth_limited_search(self.initial_state, depth, visited)
            if result:
                return result

        return "Solution not found within depth limit."


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

    puzzle = Puzzle(initial_state, goal_state)

    print("Checking solvability...")
    if puzzle.is_solvable(initial_state):
        print("Puzzle is solvable.\n")
        solution = puzzle.iddfs()

        print("IDDFS Solution Path:")
        for step in solution:
            print(step)
    else:
        print("Puzzle is NOT solvable.")

main()