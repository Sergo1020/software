#include "Button.h"

#include "Utils/Assets.h"

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  states.transform *= getTransform();

  sf::RectangleShape shape(sf::Vector2f(size_.x, size_.y));

  if (is_pressed_)
    shape.setFillColor(sf::Color(230, 130, 60));
  else if (is_hovered_)
    shape.setFillColor(sf::Color(50, 50, 50));
  else
    shape.setFillColor(sf::Color(100, 100, 100));

  shape.setPosition(position_);

  target.draw(shape, states);

  sf::Text text(title_text_, Assets::Instance().font, kDefaultFontSize);
  text.setFillColor(sf::Color::White);

  int title_x = shape.getPosition().x - text.getLocalBounds().left +
    shape.getSize().x / 2 - text.getLocalBounds().width / 2,
  title_y = shape.getPosition().y - text.getLocalBounds().top +
      shape.getSize().y / 2 - text.getLocalBounds().height / 2;

  text.setPosition(title_x, title_y);

  target.draw(text, states);
}
