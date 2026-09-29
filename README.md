This project was built as part of the 42 cursus by hcarrasc42 and jaizpuru.

# cub3d

> _A maze, a ray per column, and the illusion of a third dimension._

A first-person maze renderer in C, built on **raycasting** in the style of the
original Wolfenstein 3D. It parses a scene description, then draws a textured 3D
view of a 2D grid map in real time, with a movable camera.

![Language](https://img.shields.io/badge/language-C-blue?style=flat-square)
![Technique](https://img.shields.io/badge/technique-raycasting-red?style=flat-square)
![Graphics](https://img.shields.io/badge/graphics-MiniLibX-purple?style=flat-square)

## 📖 About

Raycasting is a rendering trick that turns a flat grid into a convincing 3D
scene without a full 3D engine. For every vertical column of the screen, a single
ray is cast from the camera into the map; the distance to the first wall it hits
determines how tall that column's wall slice should be drawn. Do this for all
`WINDOW_WIDTH` columns and the result is a smooth, first-person view.

The scene is described in a `.cub` file: the four wall textures (north, south,
east, west), the floor and ceiling colors, and the map grid itself — with the
player's start position and facing direction embedded in it.

## ✨ Key Features

- **DDA raycasting engine:** each ray uses the Digital Differential Analyzer
  algorithm to step efficiently from grid line to grid line until it hits a wall,
  computing the exact side and distance of the hit.
- **Perspective-correct walls:** the perpendicular ray distance is used to size
  each wall slice, avoiding the fisheye distortion a naive Euclidean distance
  would produce.
- **Textured walls:** four 64×64 textures, one per wall orientation; the exact
  texture column is chosen from where the ray struck the wall.
- **Configurable floor/ceiling colors** parsed from the scene file (RGB).
- **Full scene-file parser and validator:** checks the textures, the colors, and
  that the map is closed (surrounded by walls), uses only valid characters, and
  contains exactly one player start.
- **Real-time controls:** `W`/`A`/`S`/`D` to move, arrow keys to rotate the
  camera, `ESC` to quit.
- **Bonus interactivity:** live changing of the floor and ceiling colors.

## 🛠 Technologies

| Component | Detail |
|-----------|--------|
| Language | C (`-Wall -Werror -Wextra`) |
| Rendering | custom raycaster (DDA) drawing to an image buffer |
| Graphics | MiniLibX (window, image, hooks) |
| Math | `<math.h>` vector math for ray directions and distances |
| I/O | `get_next_line` (bundled) for reading the `.cub` scene |
| Build system | GNU Make |

## 🏗 Architecture

### Key data structures

| Struct | Role |
|--------|------|
| `t_map` | The parsed scene: the grid, its dimensions, the texture paths, and the floor/ceiling colors. |
| `t_grid` | The camera/player state: position, direction, and per-frame ray origin. |
| `t_vector` | Per-ray state for the DDA: `raydir`, `sidedist`, `deltadist`, `step`, the hit side (`axe`), and the wall distance. |
| `t_colors` | Per-column drawing state: wall slice height, texture coordinates, floor/ceiling/wall colors. |
| `t_in` | Top-level context tying together MiniLibX, the image buffer, and all of the above. |

### Rendering pipeline

```
main()
  └── ft_valid()        — parse + validate the .cub scene into t_map
  └── in_structs()      — init camera, MiniLibX, image buffer
  └── get_hooks()       — register key hooks + the render loop
        └── redraw_text()          — for each screen column x:
              ├── init_ray_dis()   — ray direction + initial side distances
              ├── step_comp_calc() — DDA step/delta setup
              ├── get_wall()       — DDA march until a wall cell is hit
              ├── get_height()     — perpendicular distance → slice height + texture X
              └── draw_ver_line()  — draw ceiling / textured wall / floor for column x
```

### The DDA in brief

For a ray, the engine precomputes how far it must travel to cross one grid line
in `x` and in `y` (`deltadist`). It then repeatedly advances to whichever axis'
next grid line is closer (`sidedist`), stepping one cell at a time, until the
cell it enters is a wall. Because it only ever lands on grid boundaries, it finds
the wall in a bounded number of steps and knows exactly which face (N/S/E/W) was
hit — which selects the texture and the texture column.

## 🚀 How to Run

```sh
make
./cub3D maps/map1.cub      # or any valid .cub scene
```

Controls:

| Key | Action |
|-----|--------|
| `W` / `S` | move forward / backward |
| `A` / `D` | strafe left / right |
| `←` / `→` | rotate the camera |
| `ESC` | quit |

## 📂 Project Structure

```
cub3d/
├── Makefile
├── includes/            # cub3D.h, structs_map.h, structs_image.h
├── srcs/
│   ├── main.c
│   ├── map/             # scene parsing + validation (valid, param, umap, utils)
│   ├── images/          # raycasting: vectors, textures, colors, image, timing
│   ├── hooks/           # movement, camera rotation, color hooks
│   ├── get_next_line/   # bundled line reader
│   └── utils_free.c
├── test/                # example .cub scenes
└── minilib-mac/         # MiniLibX graphics library
```

## 💡 What This Project Demonstrates

- **Raycasting rendering** with the DDA algorithm and perspective-correct wall
  projection.
- **Real-time graphics** in C: drawing directly to an image buffer and blitting
  it each frame through MiniLibX.
- **Texture mapping** — selecting the right texture and column from a ray hit.
- **Vector math** for camera direction, ray directions, and distance computation.
- **Robust file parsing and validation** of a structured scene format.
- **Working in a pair** on a shared engine split across parsing, rendering, and
  input modules.

## Note

Group project, done together with a teammate (**jaizpuru**).
