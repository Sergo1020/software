#pragma once

#include <SFML/Graphics.hpp>
#include "Config.h"

#include <memory>

class Pole;
class Ring;
class Triangle;

class Game : public sf::Drawable, public sf::Transformable {
private:
  std::vector<std::shared_ptr<Ring>> rings_;
  std::shared_ptr<Triangle> triangle_ = nullptr;
  std::shared_ptr<Pole> pole_;
  bool IsPointInside(const std::shared_ptr<Ring>& control,
                     sf::Vector2f point);
public:
  Game();
  void Refresh();
  void MouseButtonPressed(sf::Vector2f point);
  void MouseButtonReleased(sf::Vector2f point);
  void MouseMoved(sf::Vector2f point);
  bool IsPointInGameField(sf::Vector2f point);
  std::shared_ptr<Ring> GetRingById(int id) { return rings_[id]; }
  void PushRing(std::shared_ptr<Ring> ring) {
    rings_.push_back(std::move(ring));
  }
  void SetTriangle(std::shared_ptr<Triangle> triangle) { triangle_ = triangle; }

  void ClearRings() { rings_.clear(); }
  void ClearTriangle() { triangle_ = nullptr; }
public:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
