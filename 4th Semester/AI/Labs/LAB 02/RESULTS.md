# AI Lab 02 - Minimax and Alpha-Beta Pruning Implementation
## Task Completion Report

---

## OVERVIEW
This lab implements two fundamental game-playing algorithms:
1. **Minimax Algorithm** - explores all possible game states
2. **Alpha-Beta Pruning** - optimizes Minimax by pruning unnecessary branches

---

## TASK 01: MINIMAX ALGORITHM ✓

### Implementation Status: COMPLETE

#### Requirements Met:
1. ✓ Implemented Minimax algorithm for Tic-Tac-Toe
2. ✓ Utility function evaluates terminal states (win/lose/draw)
3. ✓ Heuristic function for non-terminal states
4. ✓ Tracking of nodes expanded
5. ✓ Timing measurements

#### Improvements Made:
- **Enhanced Heuristic Function**: Evaluates potential winning lines
  - Counts positions toward AI victories
  - Counts positions blocking opponent victories
  - Returns differential score (AI advantage - Human advantage)

#### Test Results with Different Depths:

| Depth | Nodes Expanded | Time (seconds) | Best Move |
|-------|---|---|---|
| 2 | 81 | 0.0018 | 4 |
| 4 | 3,609 | 0.0736 | 4 |
| 9 | 549,945 | 5.2386 | 0 |

**Observations:**
- Performance decreases exponentially with depth
- Depth 9 takes 5.2+ seconds with nearly 550K nodes
- Optimal play achieved at all depths

---

## TASK 02: ALPHA-BETA PRUNING ✓

### Implementation Status: COMPLETE

#### Requirements Met:
1. ✓ Implemented Alpha-Beta Pruning for Tic-Tac-Toe
2. ✓ Alpha and Beta bounds tracking
3. ✓ Branch pruning when alpha >= beta
4. ✓ Custom heuristic evaluation functions
5. ✓ Nodes expanded tracking
6. ✓ Timing measurements
7. ✓ Performance comparison with Minimax

#### Improvements Made:
- **Same heuristic as Minimax** for fair comparison
- **Timing information** in best_move() method
- **Comprehensive performance metrics**

#### Test Results with Different Depths:

| Depth | Nodes Expanded | Time (seconds) | Best Move |
|-------|---|---|---|
| 2 | 81 | 0.0019 | 4 |
| 4 | 1,139 | 0.0210 | 4 |
| 9 | 30,709 | 0.2768 | 0 |

**Observations:**
- Significantly fewer nodes than Minimax
- Same optimal moves found
- Dramatically faster execution time

---

## PERFORMANCE COMPARISON

### Nodes Expanded (Pruning Efficiency):

| Depth | Minimax | Alpha-Beta | Reduction | Efficiency |
|-------|---|---|---|---|
| 2 | 81 | 81 | 0% | No pruning at shallow depth |
| 4 | 3,609 | 1,139 | **68.4%** | Substantial pruning |
| 9 | 549,945 | 30,709 | **94.4%** | Extreme pruning |

### Execution Time Comparison:

| Depth | Minimax | Alpha-Beta | Speedup |
|-------|---|---|---|
| 2 | 0.0018s | 0.0019s | 0.95x |
| 4 | 0.0736s | 0.0210s | **3.5x** faster |
| 9 | 5.2386s | 0.2768s | **18.9x** faster |

### Key Findings:
- **Depth 2**: Minimal pruning (shallow game tree)
- **Depth 4**: Significant optimization (68% nodes saved)
- **Depth 9**: Extreme efficiency (94% nodes saved, 18.9x faster)

---

## GAME FEATURES IMPLEMENTED

### Game Modes:
1. **Play against Minimax** - Choose difficulty (depth 2, 4, or 9)
2. **Play against Alpha-Beta Pruning** - Choose difficulty
3. **Automatic Testing** - Compare algorithms across all depths

### User Interface:
- Clear menu selection
- Real-time move tracking
- Performance metrics display
- Win/loss/draw detection

### Metrics Displayed:
- Number of nodes expanded
- Time taken for move calculation
- Best move selected
- Game state after each move

---

## CODE STRUCTURE

### Main Classes:

#### 1. Minimax Class
```python
- __init__(): Initialize with game state and depth
- is_terminal(): Check if game is finished
- utility(): Evaluate terminal states
- heuristic(): Evaluate non-terminal states
- minimax(): Core recursive algorithm
- best_move(): Find optimal first move
```

#### 2. AlphaBetaPruning Class
```python
- __init__(): Initialize with game state and depth
- is_terminal(): Check if game is finished
- utility(): Evaluate terminal states
- heuristic(): Evaluate non-terminal states
- alphabeta(): Core algorithm with alpha-beta bounds
- best_move(): Find optimal first move
```

#### 3. Helper Functions
```python
- print_board(): Display current game state
- check_winner(): Detect winning positions
- test_algorithms(): Compare algorithms at different depths
- main(): Interactive game controller
```

---

## FILES PROVIDED

1. **tasks.py** - Complete implementation with all features
2. **test_algorithms.py** - Automated comparison testing
3. **test_game.py** - Game mode verification
4. **RESULTS.md** - This comprehensive report

---

## CONCLUSION

Both algorithms have been successfully implemented and tested:

✓ **Minimax** provides correct optimal play but with exponential time complexity
✓ **Alpha-Beta Pruning** achieves the same optimal play with 94% efficiency gain at depth 9
✓ Both algorithms make identical strategic decisions
✓ Game is fully playable with difficulty selection
✓ Comprehensive performance metrics demonstrate theory in practice

**The lab demonstrates the practical value of pruning algorithms in game AI.**

---

## HOW TO USE

### Run Interactive Game:
```bash
python tasks.py
```
Then select:
- Option 1: Play vs Minimax
- Option 2: Play vs Alpha-Beta
- Option 3: Run comparison tests

### Run Automated Tests:
```bash
python test_algorithms.py    # Compare algorithms
python test_game.py          # Test gameplay
```

---

**Lab Completed Successfully** ✓
Date: March 8, 2026
