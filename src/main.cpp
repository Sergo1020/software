#include "SFML/Graphics.hpp"

#include "Utils/Assets.h"
#include "Game/Game.h"
#include "Gui/Gui.h"

int main() {
  Assets::Instance().Load();

  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;

  sf::RenderWindow window(sf::VideoMode(kWindowWidth, kWindowHeight),
  "Pyramid", sf::Style::Default, settings);
  window.setFramerateLimit(60);

  Game game;
  game.setPosition(0, kIndentGameFieldY);

  Gui gui(game);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      sf::Vector2f point =
        window.mapPixelToCoords(sf::Mouse::getPosition(window));
      switch (event.type) {
        case sf::Event::Closed:
          window.close();
          break;
        case sf::Event::KeyPressed:
          if (event.key.code == sf::Keyboard::Escape) window.close();
          break;
          case sf::Event::MouseButtonPressed: {
            if (event.mouseButton.button == sf::Mouse::Left)
              if (game.IsPointInGameField(point))
                game.MouseButtonPressed(point);
              else
                gui.MouseButtonPressed(point);
            break;
          }
        case sf::Event::MouseButtonReleased: {
          if (event.mouseButton.button == sf::Mouse::Left)
            if (game.IsPointInGameField(point))
              game.MouseButtonReleased(point);
            else
              gui.MouseButtonReleased(point);
          break;
        }
        case sf::Event::MouseMoved: {
            game.MouseMoved(point);
            gui.MouseMoved(point);
          break;
        }
        default:
          break;
      }
    }

    game.Refresh();

    window.clear(sf::Color::White);
    window.draw(game);
    window.draw(gui);
    window.display();
  }

  return 0;
}
