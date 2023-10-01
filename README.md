# Particle System Project

This is a particle system project written in C++ using the openFrameworks library. It simulates the behavior of particles with different modes, such as attraction to the mouse, repulsion from the mouse, noise-driven movement, and proximity to attractor points.

## Features

- Particle modes:
  - **ATTRACT:** Particles are attracted to the mouse cursor.
  - **REPEL:** Particles are repelled from the mouse cursor.
  - **NOISE:** Simulates falling snow with noise-driven movement.
  - **NEAREST_POINTS:** Particles are attracted to the nearest attractor point.

- Particle behaviors:
  - Adjustable velocity (normal, half, double speed).
  - Ability to stop particle movement.
  - Zoom effect when particles are within a specified region.

- Color cycling: Particles can cycle through different colors or remain a fixed color.

## Usage

### Keyboard Controls

- **1-4:** Change the particle mode.
- **Spacebar:** Reset particles.
- **'t':** Toggle color cycling.
- **'s':** Start/stop particle movement.
- **'d':** Double particle velocity.
- **'a':** Halve particle velocity.
- **'r':** Start/stop recording keypresses.
- **'p':** Replay recorded keypresses.
- **'c':** Cancel replay.
- **'m':** Toggle the display of command menu.

### Mouse Controls

- **Left-click and drag:** Create a magnifying rectangle to zoom particles.
- **Right-click inside the rectangle:** Remove the rectangle.

## Additional Information

- Recorded keypresses can be replayed to demonstrate particle behavior.
- The project includes a menu that displays available commands.

## Dependencies

- This project is built using the openFrameworks library.

## Author

- [Sofia M. Barrera Vega](https://github.com/smbv)
- [Alexis Morales](https://github.com/AlexiMoral)


