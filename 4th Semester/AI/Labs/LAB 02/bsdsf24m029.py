import time
def print_board(board):
    print(f"{board[0]} | {board[1]} | {board[2]}")
    print("---------")
    print(f"{board[3]} | {board[4]} | {board[5]}")
    print("---------")
    print(f"{board[6]} | {board[7]} | {board[8]}")

def check_winner(board, player):
    win_conditions = [
        (0,1,2),(3,4,5),(6,7,8),
        (0,3,6),(1,4,7),(2,5,8),
        (0,4,8),(2,4,6)
    ]
    return any(all(board[i]==player for i in cond) for cond in win_conditions)

class Minimax:

    def __init__(self, game_state, ai_player='O', human_player='X', max_depth=9):
        self.game_state = game_state
        self.ai = ai_player
        self.human = human_player
        self.max_depth = max_depth
        self.nodes_expanded = 0

    def is_terminal(self, state):
        return check_winner(state, self.ai) or check_winner(state, self.human) or ' ' not in state

    def utility(self, state):
        if check_winner(state, self.ai):
            return 1
        elif check_winner(state, self.human):
            return -1
        else:
            return 0

    def heuristic(self, state):
        ai_score = 0
        human_score = 0
        
        win_conditions = [
            (0,1,2),(3,4,5),(6,7,8),
            (0,3,6),(1,4,7),(2,5,8),
            (0,4,8),(2,4,6)
        ]
        
        for condition in win_conditions:
            ai_count = sum(1 for i in condition if state[i] == self.ai)
            human_count = sum(1 for i in condition if state[i] == self.human)
            
            if human_count == 0 and ai_count > 0:
                ai_score += ai_count
            if ai_count == 0 and human_count > 0:
                human_score += human_count
        
        return ai_score - human_score

    def minimax(self, state, depth, maximizing_player):

        self.nodes_expanded += 1

        if self.is_terminal(state):
            return self.utility(state)

        if depth == 0:
            return self.heuristic(state)

        if maximizing_player:
            best = -float('inf')

            for i in range(9):
                if state[i] == ' ':
                    state[i] = self.ai
                    value = self.minimax(state, depth-1, False)
                    state[i] = ' '
                    best = max(best, value)

            return best

        else:
            best = float('inf')

            for i in range(9):
                if state[i] == ' ':
                    state[i] = self.human
                    value = self.minimax(state, depth-1, True)
                    state[i] = ' '
                    best = min(best, value)

            return best

    def best_move(self, state):

        start = time.time()

        best_val = -float('inf')
        move = -1

        for i in range(9):
            if state[i] == ' ':
                state[i] = self.ai
                move_val = self.minimax(state, self.max_depth-1, False)
                state[i] = ' '

                if move_val > best_val:
                    best_val = move_val
                    move = i

        end = time.time()

        print("Nodes Expanded:", self.nodes_expanded)
        print("Time Taken:", round(end-start,4),"seconds")

        return move


class AlphaBetaPruning:

    def __init__(self, game_state, ai_player='O', human_player='X', depth=9):
        self.max_depth = depth
        self.game_state = game_state
        self.ai = ai_player
        self.human = human_player
        self.nodes_expanded = 0

    def is_terminal(self, state):
        return check_winner(state, self.ai) or check_winner(state, self.human) or ' ' not in state

    def utility(self, state):
        if check_winner(state, self.ai):
            return 1
        elif check_winner(state, self.human):
            return -1
        else:
            return 0

    def heuristic(self, state):
        ai_score = 0
        human_score = 0
        
        win_conditions = [
            (0,1,2),(3,4,5),(6,7,8),
            (0,3,6),(1,4,7),(2,5,8),
            (0,4,8),(2,4,6)
        ]
        
        for condition in win_conditions:
            ai_count = sum(1 for i in condition if state[i] == self.ai)
            human_count = sum(1 for i in condition if state[i] == self.human)
            
            if human_count == 0 and ai_count > 0:
                ai_score += ai_count
            if ai_count == 0 and human_count > 0:
                human_score += human_count
        
        return ai_score - human_score

    def alphabeta(self, state, depth, alpha, beta, maximizing_player):

        self.nodes_expanded += 1

        if self.is_terminal(state):
            return self.utility(state)

        if depth == 0:
            return self.heuristic(state)

        if maximizing_player:

            value = -float('inf')

            for i in range(9):
                if state[i] == ' ':
                    state[i] = self.ai
                    value = max(value, self.alphabeta(state, depth-1, alpha, beta, False))
                    state[i] = ' '

                    alpha = max(alpha, value)

                    if alpha >= beta:
                        break

            return value

        else:

            value = float('inf')

            for i in range(9):
                if state[i] == ' ':
                    state[i] = self.human
                    value = min(value, self.alphabeta(state, depth-1, alpha, beta, True))
                    state[i] = ' '

                    beta = min(beta, value)

                    if beta <= alpha:
                        break

            return value

    def best_move(self, state):

        start = time.time()

        best_val = -float('inf')
        move = -1

        for i in range(9):

            if state[i] == ' ':
                state[i] = self.ai
                move_val = self.alphabeta(state, self.max_depth-1, -float('inf'), float('inf'), False)
                state[i] = ' '

                if move_val > best_val:
                    best_val = move_val
                    move = i

        end = time.time()

        print("Nodes Expanded:", self.nodes_expanded)
        print("Time Taken:", round(end-start,4),"seconds")

        return move
    
    
def main():

    board = [' ']*9
    human = 'X'
    ai_player = 'O'

    print("WELCOME TO TIC-TAC-TOE")
    print("Choose game mode:")
    print("1. Play against Minimax")
    print("2. Play against Alpha-Beta Pruning")
    
    choice = input("Enter choice (1-2): ").strip()
    
    depth_choice = input("Enter AI difficulty (2, 4, or 9): ").strip()
    try:
        depth = int(depth_choice)
        if depth not in [2, 4, 9]:
            depth = 9
    except:
        depth = 9

    if choice == '1':
        ai = Minimax(board, max_depth=depth)
        algo_name = "Minimax"
    else:
        ai = AlphaBetaPruning(board, depth=depth)
        algo_name = "Alpha-Beta Pruning"

    current = human

    while ' ' in board:

        print_board(board)

        if current == human:

            move = int(input("Enter position (0-8): "))

            if board[move] == ' ':
                board[move] = human

                if check_winner(board, human):
                    print_board(board)
                    print("You Win!")
                    return

                current = ai_player
            else:
                print("Invalid Move")

        else:

            print(f"\n{algo_name} is thinking...")
            move = ai.best_move(board)
            board[move] = ai_player

            print(f"AI played: {move}")

            if check_winner(board, ai_player):
                print_board(board)
                print(f"{algo_name} Wins")
                return

            current = human

    print_board(board)
    print("Draw")

if __name__ == "__main__":
    main()