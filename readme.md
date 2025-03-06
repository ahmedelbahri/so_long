# so_long

**so_long** is a 2D game project created using the **MLX** library, which is a graphical interface for C. The project is focused on implementing a simple game where the player navigates through a maze to collect items, and the goal is to reach an exit. This project helps to develop skills in graphics, event handling, and game mechanics in C. It is part of the 42 School curriculum.

---

## About

The goal of the **so_long** project is to create a game with the following features:

- A player can move around a 2D map.
- The map consists of walls, an exit, and collectible items.
- The player needs to collect all items and reach the exit to win.

The project includes the following steps:
1. Reading a map from a file.
2. Rendering a simple game interface.
3. Handling user input to move the player character.
4. Checking win conditions (all items collected and exit reached).

---

## Installation

To install **so_long**, follow these steps:

1. Clone this repository:
    ```bash
    git clone https://github.com/ahmedelbahri/so_long.git
    cd so_long
    ```

2. Compile the project:
    ```bash
    make
    ```

3. Optionally, to remove all compiled objects:
    ```bash
    make clean
    ```

4. To remove the executable:
    ```bash
    make fclean
    ```

5. To recompile the project after cleaning:
    ```bash
    make re
    ```

---

## Usage

To run the game, simply execute the compiled program:

```bash
./so_long maps/your_map.ber
