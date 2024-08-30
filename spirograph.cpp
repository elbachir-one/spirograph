#include <SFML/Graphics.hpp>
#include <cmath>
#include "config.hpp"

sf::Color getNextColor(int iteration) {
    int r = (iteration * 5) % 255;
    int g = (iteration * 7) % 255;
    int b = (iteration * 11) % 255;
    return sf::Color(r, g, b);
}

void drawSpirograph(sf::RenderWindow& window, float R, float r, float a, float offsetX, float offsetY, int steps, float angleOffset, float thickness, float lengthFactor) {
    sf::VertexArray lines(sf::LineStrip, steps);

    // Line extension for thickness
    sf::VertexArray thickLines(sf::LinesStrip, steps * 2);

    for (int i = 0; i < steps; ++i) {
        float t = i * (2 * M_PI / steps) + angleOffset;
        float x = (R - r) * cos(t) + a * cos((R - r) * t / r);
        float y = (R - r) * sin(t) - a * sin((R - r) * t / r);

        // Apply scaling and center the pattern in the window
        sf::Vector2f position(window.getSize().x / 2 + x * 100 + offsetX, window.getSize().y / 2 + y * 100 + offsetY);

        lines[i] = sf::Vertex(position, getNextColor(i));

        // Extend the lines for thickness
        sf::Vector2f direction = (i > 0) ? (position - thickLines[i - 1].position) : sf::Vector2f(0, 0);
        sf::Vector2f normal(-direction.y, direction.x);
        float length = std::sqrt(normal.x * normal.x + normal.y * normal.y);
        if (length != 0) {
            normal /= length;
        }

        // Create two parallel lines for thickness
        thickLines[i * 2] = sf::Vertex(position + normal * (thickness * lengthFactor), getNextColor(i));
        thickLines[i * 2 + 1] = sf::Vertex(position - normal * (thickness * lengthFactor), getNextColor(i));
    }

    window.draw(thickLines);
}

int main() {
    // Initialize window with initial dimensions from config.hpp
    sf::RenderWindow window(sf::VideoMode(INITIAL_WINDOW_WIDTH, INITIAL_WINDOW_HEIGHT), "Spirograph");
    window.setFramerateLimit(60);

    // Parameters for the first spirograph
    float R1 = 5, r1 = 3, a1 = 2;
    float offsetX1 = -100, offsetY1 = -100; // Offset for positioning the first spirograph
    // Parameters for the second spirograph
    float R2 = 7, r2 = 4, a2 = 3;
    float offsetX2 = 100, offsetY2 = 100; // Offset for positioning the second spirograph

    float angleOffset = 0.0f;
    float speed = INITIAL_SPEED;  // Initial speed of the spirograph
    float thickness = INITIAL_THICKNESS;  // Initial line thickness
    float lengthFactor = INITIAL_LENGTH_FACTOR;  // Initial length factor for line extension

    // Variables to store current dimensions
    int windowWidth = INITIAL_WINDOW_WIDTH;
    int windowHeight = INITIAL_WINDOW_HEIGHT;
    const int resizeAmount = 20;  // Amount to change window size by
    const float speedChangeAmount = 0.001f;  // Amount to change speed by
    const float thicknessChangeAmount = 0.5f;  // Amount to change line thickness by
    const float lengthChangeAmount = 0.1f;  // Amount to change line length factor by

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == KEY_QUIT)
                    window.close();
                else if (event.key.code == KEY_INCREASE_WIDTH)
                    windowWidth += resizeAmount;
                else if (event.key.code == KEY_DECREASE_WIDTH && windowWidth > resizeAmount)
                    windowWidth -= resizeAmount;
                else if (event.key.code == KEY_INCREASE_HEIGHT)
                    windowHeight += resizeAmount;
                else if (event.key.code == KEY_DECREASE_HEIGHT && windowHeight > resizeAmount)
                    windowHeight -= resizeAmount;
                else if (event.key.code == KEY_INCREASE_SPEED)
                    speed += speedChangeAmount;
                else if (event.key.code == KEY_DECREASE_SPEED && speed > speedChangeAmount)
                    speed -= speedChangeAmount;
                else if (event.key.code == KEY_INCREASE_THICKNESS)
                    thickness += thicknessChangeAmount;
                else if (event.key.code == KEY_DECREASE_THICKNESS && thickness > thicknessChangeAmount)
                    thickness -= thicknessChangeAmount;
                else if (event.key.code == KEY_INCREASE_LENGTH)
                    lengthFactor += lengthChangeAmount;
                else if (event.key.code == KEY_DECREASE_LENGTH && lengthFactor > lengthChangeAmount)
                    lengthFactor -= lengthChangeAmount;

                // Update window size
                window.setSize(sf::Vector2u(windowWidth, windowHeight));
            }
        }

        window.clear();
        drawSpirograph(window, R1, r1, a1, offsetX1, offsetY1, 1000, angleOffset, thickness, lengthFactor);
        drawSpirograph(window, R2, r2, a2, offsetX2, offsetY2, 1000, angleOffset, thickness, lengthFactor);
        window.display();

        angleOffset += speed;  // Use the current speed
    }

    return 0;
}
