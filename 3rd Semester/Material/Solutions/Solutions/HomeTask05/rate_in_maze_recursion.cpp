// #include<iostream>
// using namespace std;

// struct Pair
// {
//     int x;
//     int y;
// };

// bool solve_maze(char maze[6][6], Pair s, Pair d, int row, int col) {
//     // Base case: reached destination
//     if (s.x == d.x && s.y == d.y) {
//         cout << "(" << s.x << " , " << s.y << ")" << endl;
//         return true;
//     }
    
//     // Check if current position is valid
//     if (s.x < 0 || s.x >= row || s.y < 0 || s.y >= col || 
//         maze[s.x][s.y] == '*' || maze[s.x][s.y] == 'V') {  // Changed 'P' to 'V' for visited
//         return false;
//     }
    
//     // Mark current cell as visited (use 'V' instead of 'P' to avoid conflict with start)
//     if (maze[s.x][s.y] != 'P') {  // Don't overwrite start position
//         maze[s.x][s.y] = 'V';
//     }
    
//     // Print current path
//     cout << "(" << s.x << " , " << s.y << ") -> ";
    
//     // Try all four directions: Right, Down, Left, Up
//     Pair next;
    
//     // Right
//     next = {s.x, s.y + 1};
//     if (solve_maze(maze, next, d, row, col)) {
//         return true;
//     }
    
//     // Down
//     next = {s.x + 1, s.y};
//     if (solve_maze(maze, next, d, row, col)) {
//         return true;
//     }
    
//     // Left
//     next = {s.x, s.y - 1};
//     if (solve_maze(maze, next, d, row, col)) {
//         return true;
//     }
    
//     // Up
//     next = {s.x - 1, s.y};
//     if (solve_maze(maze, next, d, row, col)) {
//         return true;
//     }
    
//     // Backtrack - unmark current cell (only if we marked it as visited)
//     if (maze[s.x][s.y] == 'V') {
//         maze[s.x][s.y] = ' ';
//     }
    
//     return false;
// }

// int main()
// {
//     char maze1[6][6] = {
//         {' ', '*', ' ', '*', ' ', ' '},
//         {' ', '*', ' ', '*', ' ', ' '},
//         {'P', ' ', ' ', ' ', '*', ' '},
//         {'*', ' ', '*', '*', '*', ' '},
//         {' ', ' ', ' ', ' ', '*', 'T'},
//         {'*', ' ', ' ', ' ', ' ', ' '}};

//     Pair start = {2, 0};
//     Pair dest = {4, 5};

//     solve_maze(maze1, start, dest, 6, 6);

//     char maze2[6][6] = {
//         {' ', '*', ' ', '*', ' ', ' '},
//         {' ', '*', ' ', '*', ' ', ' '},
//         {'P', ' ', ' ', ' ', '*', ' '},
//         {'*', '*', '*', ' ', '*', ' '},
//         {' ', ' ', ' ', '*', '*', 'T'},
//         {'*', ' ', ' ', ' ', ' ', ' '}};

//     solve_maze(maze2, start, dest, 6, 6);

//     return 0;
// }
