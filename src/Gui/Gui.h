#pragma once

#include "SFML/Graphics.hpp"

#include <memory>

class Game;
class Control;

class Gui : public sf::Drawable, public sf::Transformable {
private:
  Game& game_;
  std::map<std::string, std::shared_ptr<Control>> controls_;
  bool IsPointInside(const std::shared_ptr<Control>& control,
                     sf::Vector2f point);
public:
  Gui(Game& game);
  void Refresh();
  void Initialize();
  void MouseButtonPressed(sf::Vector2f point);
  void MouseButtonReleased(sf::Vector2f point);
  void MouseMoved(sf::Vector2f point);
public:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
