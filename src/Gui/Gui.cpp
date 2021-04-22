#include "Gui.h"

#include "Utils/Assets.h"

#include "Game/Game.h"
#include "Game/Ring.h"
#include "Game/Triangle.h"

#include "Label.h"
#include "Button.h"

#include <random>
#include <ctime>
#include <math.h>
#include <iostream>

Gui::Gui(Game& g) : game_(g) {
	Initialize();
}

void Gui::Initialize() {
	srand(time(NULL));

	auto btn_test = std::make_shared<Button>(
		L"помощь", sf::Vector2f(0, 50)
	);
	btn_test->OnClick = [](Control& me, Game& game, Gui& gui) {

		sf::RenderWindow window(sf::VideoMode(800, 800), "help");

		sf::Text text(L"Для выхода = Esc\n\n функционал:\n\nдля того что-бы рисовать детскую пирамидку, нажмите .РИСОВАТЬ. \n\nдля того чтобы рисовать детскую пирамидку в разобранном виде, нажмите .РАЗОБРАТЬ. \n\nдля того что-бы рисовать детскую пирамидку случайным образом на столе, нажмите .RAND. \n\nчтобы удалить всё объекты со стола, нажмите кнопку .УДАЛИТЬ. \n\nдля того чтобы перемещать круги по любой доступной плоскости\n\nнаведите курсор на круг и зажмите его, чтобы перетаскивать круг по своему усмотрению	", Assets::Instance().font, 18);
		text.setFillColor(sf::Color::Black);
		text.setPosition(sf::Vector2f(50, 50));

		while (window.isOpen()){
			sf::Event event;
			while (window.pollEvent(event)){
				switch (event.type) {
					case sf::Event::Closed:
						window.close();
						break;
					case sf::Event::KeyPressed:
						if (event.key.code == sf::Keyboard::Escape) window.close();
						break;
				}
			}

			window.clear(sf::Color::White);
	    window.draw(text);
	    window.display();
		}
	};

/*	auto btn_test_1 = std::make_shared<Button>(
		L"Пчола", sf::Vector2f(btn_test->GetPosition().x + 125, 50)
	);
	btn_test_1->OnClick = [](Control& me, Game& game, Gui& gui) {
		if (me.GetTitleText() == L"Пчола")
		me.SetTitleText(L"Каво");
		else
		me.SetTitleText(L"Пчола");
	};*/

	auto clear_ = std::make_shared<Button>(
		L"удалить", sf::Vector2f(btn_test->GetPosition().x + 125, 50)
	);
	clear_->OnClick = [] (Control& me, Game& game, Gui& gui) {
		game.ClearRings();
		game.ClearTriangle();
	};


	auto forms = std::make_shared<Button>(   //кольца
		L"рисовать", sf::Vector2f(clear_->GetPosition().x + 125, 50)
	);
	forms->SetSize(sf::Vector2f(200, kButtonDefaultHeight));
	forms->OnClick = [](Control& me, Game& game, Gui& gui) {
		auto ring = std::make_shared<Ring>(sf::Vector2f(465, 320));
		ring->SetRadius(40);
		ring->SetColor(sf::Color::Red);
		game.PushRing(ring);

		auto ring_1 = std::make_shared<Ring>(sf::Vector2f(445, 360));
		ring_1->SetRadius(60);
		ring_1->SetColor(sf::Color::Blue);
		game.PushRing(ring_1);

		auto ring_2 = std::make_shared<Ring>(sf::Vector2f(425, 400));
		ring_2->SetRadius(80);
		ring_2->SetColor(sf::Color::Green);
		game.PushRing(ring_2);

		game.SetTriangle(std::make_shared<Triangle>(sf::Vector2f(455, 230)));
	};

	auto forms_state = std::make_shared<Button>(
		L"разобрать", sf::Vector2f(forms->GetPosition().x + 225, 50)
	);
	forms_state->SetSize(sf::Vector2f(200, kButtonDefaultHeight));
	forms_state->OnClick = [](Control& me, Game& game, Gui& gui) {
		auto ring = std::make_shared<Ring>(sf::Vector2f(210, 450));
		ring->SetRadius(40);
		ring->SetColor(sf::Color::Red);
		game.PushRing(ring);

		auto ring_1 = std::make_shared<Ring>(sf::Vector2f(250, 425));
		ring_1->SetRadius(60);
		ring_1->SetColor(sf::Color::Blue);
		game.PushRing(ring_1);

		auto ring_2 = std::make_shared<Ring>(sf::Vector2f(320, 400));
		ring_2->SetRadius(80);
		ring_2->SetColor(sf::Color::Green);
		game.PushRing(ring_2);

		game.SetTriangle(std::make_shared<Triangle>(sf::Vector2f(550, 440)));
	};

	auto btn_randomize = std::make_shared<Button>(
		L"RAND", sf::Vector2f(forms_state->GetPosition().x + 225, 50)
	);
	btn_randomize->OnClick = [](Control& me, Game& game, Gui& gui ) {
		int radius = 40;
		int tableIndent = kWindowHeight - kIndentGameFieldY - kTablePosY ;
		auto ring = std::make_shared<Ring>(
			sf::Vector2f(
				rand() % kTableLineWidth + kTablePosX,
				rand() % (tableIndent- radius * 2) + kTablePosY
			)
		);
		ring->SetRadius(radius);
		ring->SetColor(sf::Color::Blue);
		game.PushRing(ring);

		radius = 60;
		auto ring_1 = std::make_shared<Ring>(
			sf::Vector2f(
				rand() % kTableLineWidth + kTablePosX,
				rand() % (tableIndent - radius * 2) + kTablePosY
			)
		);
		ring_1->SetRadius(radius);
		ring_1->SetColor(sf::Color::Green);
		game.PushRing(ring_1);

		radius = 80;
		auto ring_2 = std::make_shared<Ring>(
			sf::Vector2f(
				rand() % kTableLineWidth + kTablePosX,
				rand() % (tableIndent - radius * 2) + kTablePosY
			)
		);
		ring_2->SetRadius(radius);
		ring_2->SetColor(sf::Color::Red);
		game.PushRing(ring_2);

		auto triangle = std::make_shared<Triangle>(
			sf::Vector2f(
				rand()% kTableLineWidth + kTablePosX,
				rand()% (tableIndent - radius * 2) + kTablePosY
			)
		);
		game.SetTriangle(triangle);
	};

	auto label_debug = std::make_shared<Label>(
		L"Координаты", sf::Vector2f(10, 5)
	);

	controls_["btn_test"]     = btn_test;
	//controls_["btn_test_1"]   = btn_test_1;
	controls_["label_debug"]  = label_debug;
	controls_["forms"]        = forms;
	controls_["forms_state"]  = forms_state;
	controls_["clear_"]       = clear_;
	controls_["btn_randomize"] = btn_randomize;
}

void Gui::MouseButtonPressed(sf::Vector2f point) {
	for (auto const& [name, control] : controls_)
	control->SetPressed(IsPointInside(control, point));
}

void Gui::MouseButtonReleased(sf::Vector2f point) {
	for (auto const& [name, control] : controls_) {
		if (IsPointInside(control, point) &&
		(control->GetPressed() && control->OnClick))
		control->OnClick(*control, game_, *this);

		control->SetPressed(false);
	}
}

void Gui::MouseMoved(sf::Vector2f point) {
	for (auto const& [name, control] : controls_)
	control->SetHovered(IsPointInside(control, point));

	controls_.find("label_debug")->second->SetTitleText(
		game_.IsPointInGameField(point) ?
		L"Координаты в игровом поле: " + std::to_wstring(point.x) +
		L" " + std::to_wstring(point.y - kIndentGameFieldY) :
		L"Координаты в окне: " + std::to_wstring(point.x) +
		L" " + std::to_wstring(point.y)
	);
}

bool Gui::IsPointInside(const std::shared_ptr<Control>& control,
	sf::Vector2f point) {
		float left = control->GetPosition().x;
		float right = left + control->GetSize().x;
		float top = control->GetPosition().y;
		float bottom = top + control->GetSize().y;

		return (left <= point.x && point.x <= right) &&
		(top <= point.y && point.y <= bottom);
	}

	void Gui::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		states.transform *= getTransform();

		for (auto const& [name, control] : controls_)
		target.draw(*control, states);
	}
