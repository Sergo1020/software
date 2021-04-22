#pragma once

#include <SFML/Graphics.hpp>
#include "Config.h"

class Pole : public sf::Drawable, public sf::Transformable {
private:
  sf::Vector2f size_;
  sf::Vector2f position_;
public:
  Pole(sf::Vector2f position) {
    position_ = position;
    size_ = sf::Vector2f(kPoleWidth, kPoleHeight);
   }
public:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
