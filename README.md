# C++ Mini Projects

This repository is a small collection of C++ practice projects. Right now it contains a console-based Tic-Tac-Toe engine and an unfinished AI version that is being built toward a minimax-based opponent.

## Repository Structure

```text
.
├── README.md
└── xo_engine/
    ├── Engine.cpp       # Completed two-player Tic-Tac-Toe console game
    ├── Ai_Engine.cpp    # Work-in-progress AI Tic-Tac-Toe engine
    ├── Engine           # Compiled Linux executable for Engine.cpp
    └── ai               # Compiled Linux executable for an earlier AI build
```

## Projects

### 1. Tic-Tac-Toe Engine

Source file: `xo_engine/Engine.cpp`

This is a playable two-player Tic-Tac-Toe game for the terminal.

Features:

- 3x3 Tic-Tac-Toe board
- Two-player turn system
- Input validation for occupied or invalid cells
- Win detection for rows, columns, and diagonals
- Draw detection when the board is full
- Simple console board rendering

Player markers:

- Player 1: `x`
- Player 2: `o`

Build and run:

```bash
g++ xo_engine/Engine.cpp -o xo_engine/Engine
./xo_engine/Engine
```

### 2. AI Tic-Tac-Toe Engine

Source file: `xo_engine/Ai_Engine.cpp`

This file is currently half complete. It appears to be an AI version of the Tic-Tac-Toe engine using a minimax-style approach.

Current implemented pieces:

- Board initialization
- Human move input
- Move validation
- Board drawing
- Win detection
- Draw detection
- Early minimax structure

Current status:

- The AI turn is not finished inside `play()`.
- The `minmax()` function is incomplete.
- `Ai_Engine.cpp` currently does not compile with `g++` because the code uses the iterator returned by `std::find()` as a direct vector index.
- `minmax()` also has code paths that do not return a value even though the function return type is `int`.

Example current compile command:

```bash
g++ xo_engine/Ai_Engine.cpp -o xo_engine/ai
```

Expected next work:

- Finish minimax recursion.
- Convert the `std::find()` iterator to a numeric index before accessing `move_x` and `move_y`.
- Make sure every `minmax()` path returns an integer score.
- Add the AI move inside the `else` block of `play()`.
- Test human win, AI win, and draw cases.

## Requirements

- A C++ compiler such as `g++`
- A Linux/macOS terminal or Windows terminal with a C++ compiler installed

Checked with:

```bash
g++ 13.3.0
```

## Notes

The compiled files in `xo_engine/Engine` and `xo_engine/ai` are Linux executables. If you are on another system, rebuild the programs from the `.cpp` source files instead of relying on the existing binaries.

This repo is still in progress and is useful as a learning space for C++ basics, arrays, classes, game loops, validation, and simple game AI.
