# Cub3D
![perspective2](https://github.com/user-attachments/assets/91c5094b-7fea-45cf-9436-cc6b2ff57b45) 
![perspective6](https://github.com/user-attachments/assets/94fdecee-2f2f-43e2-96b5-2023f4428531)

Cub3D is a project that aims to create a basic 3D game engine using raycasting techniques. Inspired by games like Wolfenstein 3D, this project deepens understanding of graphics programming, game development basics, and efficient rendering techniques. The engine renders a 3D-like environment from a 2D map, allowing the player to navigate through the space.

## Installation
1. CLone the repository:
```
git clone https://github.com/clemllovio/cub3D.git
```
2. Navigate to the project directory and compile the project
 ## Usage 
 To run the game:
 ```
./cub3D map_name.cub
```
Several test maps are available in the maps directory.

## Map configuration
The `.cub` file should contain:
• Texture paths for each direction:
```
NO ./path_to_north_texture
SO ./path_to_south_texture
WE ./path_to_west_texture
EA ./path_to_east_texture
```

• Floor and ceiling colors: `F 220,100,0` and `C 225,30,0`

#### Map layout using characters:
  
  • `0` for empty space
  
  • `1` for walls
  
  • `N`, `S`, `E` or `W` for player starting position and orientation

## Controls
• `W`, `A`, `S`, `D`: Move the player

• Left/Right arrow keys: Rotate the camera

• `ESC`: Exit the game

## Credits
This project was developed by Clémence Llovio and Lisa Ciullo as part of the curriculum at 42 School..
