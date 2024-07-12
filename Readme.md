# Cub3D

Cub3D is a project developed at 42 Paris, inspired by the classic game Wolfenstein 3D. It involves creating a 3D game using the ray-casting technique.
This project is a great opportunity to learn about graphics programming, game development, and working with the MiniLibX library.

## Table of Contents

- [Cub3D](#cub3d)
  - [Table of Contents](#table-of-contents)
  - [Installation](#installation)
  - [Usage](#usage)
  - [Features](#features)
  - [File Structure](#file-structure)
    - [Key Files](#key-files)
  - [Maps](#maps)
  - [Ray Casting Technique](#ray-casting-technique)
  - [Contributing](#contributing)
  - [License](#license)

## Installation

To compile and run the project, you need to have the following dependencies installed:

-   `gcc` (GNU Compiler Collection)
-   `make`
-   `X11` libraries (for Linux)

Clone the repository and navigate to the project directory:
`git clone https://github.com/Dang-Hai-Tran/cub3d_42.git`

Build the project using `make`

To build with debug information: `make debug`

To build with bonus features: `make bonus`

## Usage

To run the game, execute the following command:
`./cub3D path_to_map.cub`

Example: `./cub3D assets/maps/valid/small.cub`

## Features

-   **Ray-Casting**: Implemented using the MiniLibX library to render 3D graphics.
-   **Texture Mapping**: Supports different textures for walls and floors.
-   **Map Parsing**: Reads and validates map files.
-   **Debug Mode**: Provides detailed information about the game state.

## File Structure

The project is organized as follows:

-   **src/**: Contains the source code for the project.
-   **libs/**: Contains external libraries like `libft` and `minilibx`.
-   **assets/**: Contains map files and textures.

### Key Files

-   **src/main.c**: Entry point of the application.
-   **src/read_file/ft_check_file.c**: Functions for file validation and parsing.
-   **src/raycaster.c**: Functions for ray casting and texture mapping.
-   **libs/libft/src/**: Custom implementations of standard C library functions.

## Maps

Maps are defined in `.cub` files located in the `assets/maps/` directory. Each map file specifies textures for the walls and floor,
as well as the layout of the map.

Example of a valid map file (`assets/maps/valid/small.cub`):

```cub
NO ./assets/textures/simonkraft/wet_sponge.xpm
SO ./assets/textures/simonkraft/wet_sponge.xpm
WE ./assets/textures/simonkraft/wet_sponge.xpm
EA ./assets/textures/simonkraft/wet_sponge.xpm
F 164,169,20
C 153,204,255
11111
10001
1E001
10001
11111
```

## Ray Casting Technique

Ray casting is a technique used in 3D graphics to determine the path of rays through a scene. In the context of Cub3D, it is used to
render a 3D environment from a 2D map. Here's a breakdown of how ray casting is implemented in the project:

-   Initialization: The ray casting process starts with initializing the ray for each vertical stripe of the screen. This is done in the `init_raycaster` function
    in `raycaster.c`.

-   Setting up the DDA algorithm: The Digital Differential Analyzer (DDA) algorithm is used to perform ray traversal through the grid. This is set up in the `setup_dda_algo` function
    in `raycaster.c`.

-   Updating the texture pixels: The texture pixels are updated based on the calculated line height and the intersection point in the `update_texpixels` function in `update_texpixels.c`.

-   Rendering the frame: Finally, the frame is rendered by setting the pixels in the image in the `render_frame` function in `render_display.c`.

-   Putting it all together: The main function that ties all these steps together is `perform_raycaster`, which iterates over each vertical stripe of the screen and performs the ray casting process.

By following these steps, the ray casting technique is implemented to render a 3D scene from a 2D map.

## Contributing

Contributions are welcome! Please follow these steps to contribute:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Commit your changes (`git commit -am 'Add new feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Create a new Pull Request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
