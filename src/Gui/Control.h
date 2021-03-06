#pragma once

#include "SFML/Graphics.hpp"

class Game;
class Gui;

class Control : public sf::Drawable, public sf::Transformable {
protected:
  std::wstring title_text_;
  bool is_hovered_ = false;
  bool is_pressed_ = false;
  sf::Vector2f size_;
  sf::Vector2f position_;
public:
  Control(std::wstring title_text, sf::Vector2f position) {
    title_text_ = title_text;
    position_ = position;
  };
  void (*OnClick) (Control& me, Game& game, Gui& gui) = NULL;
  sf::Vector2f GetSize() { return size_; }
  void SetSize(sf::Vector2f size) { size_ = size; }
  sf::Vector2f GetPosition() { return position_; }
  bool GetPressed() { return is_pressed_; }
  void SetPressed(bool state) { is_pressed_ = state; }
  void SetHovered(bool state) { is_hovered_ = state; }
  std::wstring GetTitleText() { return title_text_; }
  void SetTitleText(std::wstring title_text) {
    title_text_ = title_text;
  }
};
