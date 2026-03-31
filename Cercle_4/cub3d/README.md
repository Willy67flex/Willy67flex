*This project has been created as part of the 42 curriculum by whollebe, ele-moig*

# cub3D - My first RayCaster with miniLibX

## Description

**cub3D** is a 3D graphical representation of the inside of a maze from a first-person perspective, built in C. Inspired by the world-famous 1992 game *Wolfenstein 3D* (widely considered the first First-Person Shooter in gaming history), this project is a deep dive into the practical applications of mathematics and rendering. 

The core of this project relies on **Ray-Casting**, a rendering technique that creates a 3D perspective in a 2D map. By casting rays from the player's viewpoint and calculating their intersections with walls, the program scales vertical lines on the screen to simulate depth and distance. 


## Features

### Mandatory Requirements
* **Smooth Window Management**: Built using the `miniLibX` library, allowing fluid window handling (minimizing, switching, etc.).
* **Directional Textures**: Different textures are applied to walls depending on the side they are facing (North, South, East, West).
* **Dynamic Colors**: Floor and ceiling colors are customizable directly from the configuration file.
* **Clean Exit**: The game handles cross-clicks and the `ESC` key to free all memory and exit cleanly.

### Bonus Implementations

* **Interactive Doors (`D`)**: A custom map identifier allowing the placement of doors. They can be opened and closed by the player. We implemented specific checks to ensure doors do not open into the void.
* **Mouse Look**: The player can smoothly rotate their point of view using the mouse, greatly enhancing the modern FPS feel.
* **Collision**: The players cannot go through walls.
* **Mini-map**: a minimap showing the level and the player position.

---

## Instructions

### Prerequisites
* A C compiler (`cc`).
* The `miniLibX` library installed or compiled from source.
* The standard C math library.

### Compilation
We provide a `Makefile` that compiles the project adhering to the strict 42 Norm.
* To compile the standard project:
  ```bash
  make
  ```
* Additional rules: `clean` (removes object files), `fclean` (removes objects and executable), `re` (recompiles from scratch).

### Execution
Run the game by passing a valid `.cub` scene description file as an argument:
```bash
./cub3D maps/example.cub
```

---

## Controls

* **W**: Move forward
* **S**: Move backward
* **A**: Strafe left
* **D**: Strafe right
* **Mouse Movement**: Rotate camera view
* **E**: Interact / Open and close doors
* **ESC**: Quit the game

---

## Map and Configuration Rules

The `.cub` file defines the rules of the environment. The parser strictly checks for the following elements, which can be provided in any order (except the map, which must be last).

### Identifiers
Each identifier must be followed by its specific information, separated by spaces:
* `NO ./path_to_texture`: North wall texture.
* `SO ./path_to_texture`: South wall texture.
* `WE ./path_to_texture`: West wall texture.
* `EA ./path_to_texture`: East wall texture.
* `F R,G,B`: Floor color in RGB format (0-255).
* `C R,G,B`: Ceiling color in RGB format (0-255).

### Map Layout
The map itself must be constructed using the following characters:
* `0`: Empty space.
* `1`: Solid wall.
* `N, S, E, W`: Player spawn point and initial facing direction.
* `D`: Interactive Door (Must be flanked by walls and cannot face the void).

*Note: The map must be completely closed/surrounded by walls, otherwise the parser will return an error*.

---

## Resources & AI Usage

### References
* [Lode's Computer Graphics Tutorial (Raycasting)](https://lodev.org/cgtutor/raycasting.html) - The primary mathematical and conceptual resource used to understand Digital Differential Analysis (DDA) and ray calculations.
* MiniLibX Documentation - For managing the graphical window and hooking keyboard/mouse events.

### AI usage
In accordance with the school's AI guidelines, artificial intelligence was used strictly as an educational assistant:
* **Concept Clarification**: AI was queried to help demystify the complex trigonometry and vector math required for camera plane rotation and ray collision.
* **Mathematical help**: AI was also used to help us with the math side of this project, because it was hard for me (ele-moig) to use matrices and vectors.
* **Readme**: AI was used to help create this readme because this is exactly the kind of shit i want the ai to do for me (this was written by ele-moig)
