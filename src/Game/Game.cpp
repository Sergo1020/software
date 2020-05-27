#include "Game.h"

#include "Pole.h"
#include "Ring.h"
#include "Triangle.h"

#include "Config.h"

Game::Game() {
  pole_ = std::make_shared<Pole>(
    sf::Vector2f(kPolePosX, kWindowHeight - kIndentGameFieldY - kPoleHeight)
  );
}

bool Game::IsPointInGameField(sf::Vector2f point) {
  return point.y >= kIndentGameFieldY;
}

void Game::MouseButtonPressed(sf::Vector2f point) {
  sf::Vector2f point_in_container = point - getPosition();

  for (auto const& ring : rings_)
    ring->SetDragged(IsPointInside(ring, point_in_container));
}

void Game::MouseButtonReleased(sf::Vector2f point) {
  for (auto const& ring : rings_)
    ring->SetDragged(false);
}

void Game::MouseMoved(sf::Vector2f point) {
  sf::Vector2f point_in_container = point - getPosition();

  for (auto const& ring : rings_)
    if (ring->GetDragged())
      ring->SetPosition(point_in_container);
}

void Game::Refresh() {
  /*for (auto const& ring : rings_)
    if (!ring->GetDragged() && ring->GetPosition().y <
        (kWindowHeight - kIndentGameFieldY - ring->GetRadius()))
      ring->SetPosition(ring->GetPosition() + sf::Vector2f(0, 1));*/
}

bool Game::IsPointInside(const std::shared_ptr<Ring>& ring,
                         sf::Vector2f point) {
  float left = ring->GetPosition().x;
  float right = left + ring->GetSize().x;
  float top = ring->GetPosition().y;
  float bottom = top + ring->GetSize().y;

  return (left <= point.x && point.x <= right) &&
    (top <= point.y && point.y <= bottom);
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const {   //стол
  states.transform *= getTransform();

  sf::RectangleShape line(sf::Vector2f(kTableLineWidth, kTableLineThickness));
  line.setFillColor(sf::Color::Black);
  line.setPosition(sf::Vector2f(kTablePosX, kTablePosY));
  line.rotate(120);
  target.draw(line, states);

  line.rotate(-120);
  target.draw(line, states);

  line.setPosition(line.getPosition() + sf::Vector2f(line.getSize().x, 0));
  line.rotate(60);
  target.draw(line, states);

  target.draw(*pole_, states);
/*
  line.setPosition(sf::Vector2f(510, 500));
  line.rotate(-120);
  target.draw(line, states);
*/

  if (triangle_.get() != nullptr)
    target.draw(*triangle_, states);

  for (auto const& ring: rings_)
     target.draw(*ring, states);
}
/*
void Shadow::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  states.transform *= getTransform();

  sf::VertexArray lines(sf::Lines, 16);
  lines[0].position = sf::Vector2f(0,0);
  lines[1].position = sf::Vector2f(100,150);
  //и т.д.

  //далее для каждой точки указываем цвет(так можно создавать градиенты):
  lines[0].color = sf::Color::White;
  lines[1].color = sf::Color::Blue;;

  target.draw(lines, states);
}
*/
