#pragma once

#include <SFML/Graphics.hpp>

class Ring : public sf::Drawable, public sf::Transformable {
private:
  bool is_dragged_ = false;
  sf::Vector2f size_;
  sf::Vector2f position_;
  int radius_;
  sf::Color color_;
public:
  Ring(sf::Vector2f position) { position_ = position; }
  sf::Vector2f GetSize() { return size_; }
  sf::Vector2f GetPosition() { return position_; }
  void SetRadius(int radius) {
    radius_ = radius;
    size_ = sf::Vector2f(radius * 2, radius);
  }
  int GetRadius() { return radius_; }
  void SetPosition(sf::Vector2f position) { position_ = position; }
  bool GetDragged() { return is_dragged_; }
  void SetDragged(bool state) { is_dragged_ = state; }
  void SetColor(sf::Color color) { color_ = color; }
public:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
