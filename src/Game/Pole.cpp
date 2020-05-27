#include "Pole.h"


void Pole::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  states.transform *= getTransform();

  sf::RectangleShape shape(sf::Vector2f(size_.x, size_.y));
  shape.setFillColor(sf::Color::Blue);

  shape.setPosition(position_);

  target.draw(shape, states);
}
