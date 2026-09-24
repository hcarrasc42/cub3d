# cub3d

A raycasting engine in the style of early Wolfenstein, built in C with MiniLibX — no game engine, no shortcuts.

Every wall, texture, and camera movement is math written from scratch: casting a ray per screen column against a 2D map, computing wall distance and height, texture-mapping the result, and keeping it all running at real-time frame rates. The map, textures, and starting position are configurable through a custom `.cub` scene file parsed by hand.

**Built with:** C · MiniLibX · computer graphics

---

A pair project completed as part of the core curriculum at [42 Urduliz](https://42urduliz.com). Part of my [GitHub profile](https://github.com/hcarrasc42).
