<h1 align="center">⬛ Cub3D</h1>
<p align="center">
  <img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="C"/>
  <img src="https://img.shields.io/badge/42-000000?style=for-the-badge&logo=42&logoColor=white" alt="42"/>
</p>

<p align="center">
  A 3D game engine using raycasting techniques, inspired by Wolfenstein 3D, developed as part of the 42 curriculum.
</p>

<p align="center">
  <img src="https://github.com/user-attachments/assets/91c5094b-7fea-45cf-9436-cc6b2ff57b45" alt="Game Screenshot 1" width="400"/>
  <img src="https://github.com/user-attachments/assets/94fdecee-2f2f-43e2-96b5-2023f4428531" alt="Game Screenshot 2" width="400"/>
</p>

## 📋 Overview
Cub3D is a raycasting-based 3D game engine that transforms 2D maps into immersive 3D environments. This project explores fundamental concepts of computer graphics, including raycasting techniques, texture mapping, and real-time rendering.

## ✨ Features
### Graphics Engine
- Raycasting-based 3D rendering
- Textured walls for each direction (North, South, East, West)
- Custom floor and ceiling colors
- Real-time rendering and smooth movement

### Player Controls
- First-person perspective navigation
- Smooth camera rotation
- Collision detection with walls

### Map System
- Custom map format (.cub)
- Dynamic map loading
- Configurable textures and colors
- Validation of map integrity

## 🚀 Getting Started
### Prerequisites
- GCC compiler
- Make
- MinilibX library
- Unix-like operating system

### Installation
```bash
# Clone the repository
git clone https://github.com/clemllovio/cub3D.git
cd cub3D

# Compile the project
make
```

### Usage
```bash
# Run the game with a map file
./cub3D maps/map_name.cub
```

## 🗺️ Map Configuration
### File Format (.cub)
```plaintext
# Texture paths
NO ./path_to_north_texture
SO ./path_to_south_texture
WE ./path_to_west_texture
EA ./path_to_east_texture

# Colors (RGB format)
F 220,100,0    # Floor color
C 225,30,0     # Ceiling color

# Map layout
111111
100101
1N0001
111111
```

### Map Characters
- `0`: Empty space
- `1`: Wall
- `N`, `S`, `E`, `W`: Player spawn point and orientation

## 🎮 Controls
- `W`: Move forward
- `S`: Move backward
- `A`: Strafe left
- `D`: Strafe right
- `←/→`: Rotate camera
- `ESC`: Exit game

## 🎯 Project Objectives
- Implement a raycasting engine
- Create realistic 3D visualization from 2D maps
- Handle texture mapping and color rendering
- Manage player movement and collision
- Process user input and game events
- Ensure smooth performance and optimization

## 🤝 Contributors
- **Lisa Ciullo** - [@lciullo](https://github.com/YOUR_USERNAME)
- **Clémence Llovio** - [@clemllovio](https://github.com/clemllovio)

## 🧠 Learning Outcomes
This project provided valuable experience in:
- 3D graphics programming fundamentals
- Raycasting algorithms and optimization
- Game development principles
- Real-time rendering techniques
- User input handling and game controls
- Collaborative development
- Code organization and optimization

## 📝 License
This project is part of the 42 school curriculum.
