# Spirograph

![spirograph](assets/spirograph.gif)

A simple spirograph drawing application using SFML. This program generates and displays spirographs with customizable parameters such as speed, line thickness, and window size. The application supports two parallel spirographs, each with its own path and color.

## Features

- **Two Parallel Spirographs**: Draws two distinct spirographs with separate paths and colors.
- **Customizable Parameters**: Adjust the spirograph's speed, line thickness, and length factor.
- **Resizable Window**: Change the window dimensions on-the-fly.
- **Interactive Controls**: Use keyboard shortcuts to modify spirograph settings.

## Dependencies

- **SFML**: Ensure SFML is installed on your system. The application uses SFML for graphics and window management.

## Installation

1. **Install SFML**: Follow instructions on [SFML's official website](https://www.sfml-dev.org/download.php) to install SFML.

NOTE: Use your package manager to install SFML.

2. **Compile the Application**:

    ```bash
    git clone https://github.com/elbachir-one/spirograph
    cd spirograph/
    make
    ./spirograph
    ```

## Configuration

The application reads configuration settings from `config.hpp`. You can adjust the following parameters:

- **Window Dimensions**:
  - `INITIAL_WINDOW_WIDTH`: Initial width of the window (default: 1920).
  - `INITIAL_WINDOW_HEIGHT`: Initial height of the window (default: 1080).

- **Spirograph Settings**:
  - `INITIAL_SPEED`: Initial speed of the spirograph (default: 0.01f).
  - `INITIAL_THICKNESS`: Initial line thickness (default: 1.0f).
  - `INITIAL_LENGTH_FACTOR`: Initial length factor for line extension (default: 1.0f).

- **Key Bindings**:
  - `KEY_QUIT`: Key to quit the application (default: `Q`).
  - `KEY_INCREASE_WIDTH`: Key to increase window width (default: `Right Arrow`).
  - `KEY_DECREASE_WIDTH`: Key to decrease window width (default: `Left Arrow`).
  - `KEY_INCREASE_HEIGHT`: Key to increase window height (default: `Up Arrow`).
  - `KEY_DECREASE_HEIGHT`: Key to decrease window height (default: `Down Arrow`).
  - `KEY_INCREASE_SPEED`: Key to increase spirograph speed (default: `Page Up`).
  - `KEY_DECREASE_SPEED`: Key to decrease spirograph speed (default: `Page Down`).
  - `KEY_INCREASE_THICKNESS`: Key to increase line thickness (default: `K`).
  - `KEY_DECREASE_THICKNESS`: Key to decrease line thickness (default: `L`).
  - `KEY_INCREASE_LENGTH`: Key to increase line length factor (default: `I`).
  - `KEY_DECREASE_LENGTH`: Key to decrease line length factor (default: `J`).

## Usage

- **Increase/Decrease Window Size**:
  - Use the arrow keys to adjust the window width and height.

- **Adjust Spirograph Parameters**:
  - Use `Page Up` and `Page Down` to change the speed.
  - Use `K` and `L` to adjust the line thickness.
  - Use `I` and `J` to modify the length factor.

- **Exit the Application**:
  - Press `Q` to close the window.

## Example

Here's how the spirographs might look with different parameters:

- Two spirographs drawn in parallel with unique colors and paths.
- Adjustable settings for speed, line thickness, and window size.

## Contributing

Contributions are welcome! Feel free to open issues or submit pull requests.

