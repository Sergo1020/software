#include "Triangle.h"

void Triangle::draw(sf::RenderTarget& target, sf::RenderStates states) const {
   states.transform *= getTransform();

   sf::CircleShape triangle(kTriangleRadius, 3);

   triangle.setPosition(position_); 
   triangle.setFillColor(sf::Color::Blue);
   target.draw(triangle, states);
}
