#include "Ring.h"

void Ring::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  states.transform *= getTransform();

  sf::CircleShape ellipse;
  ellipse.setRadius(radius_);
  ellipse.setOutlineColor(color_);
  ellipse.setFillColor(sf::Color(255, 255, 255, 0));
  ellipse.setOutlineThickness(radius_ / 2);
  ellipse.setPosition(position_);
  ellipse.setScale(1, 0.5);

  target.draw(ellipse, states);
}
