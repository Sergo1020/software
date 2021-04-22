#pragma once

#include <SFML/Graphics.hpp>
#include "Config.h"

class Triangle : public sf::Drawable, public sf::Transformable {
private:
  sf::Vector2f position_;
public:
  Triangle(sf::Vector2f position) {
    position_ = position;
   }
public:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
