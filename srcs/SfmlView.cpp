#include "SfmlView.hpp"
#include <iostream>

SfmlView::SfmlView(int width, int height) : m_modules(NULL), m_len(0), m_width(width), m_height(height)
{
}

SfmlView::~SfmlView(void)
{
}

MonitorModule * SfmlView::getModules(void)
{
	return this->m_modules;
}

void	SfmlView::setModules(MonitorModule *mod, unsigned int const len)
{
	this->m_modules = mod;
	this->m_len = len;
}

void 	SfmlView::m_setFont(void)
{
	if (!this->m_font.loadFromFile("arial.ttf"))
	{
		throw(std::exception());
	}
}

void	SfmlView::m_updateView(void)
{
	float		y;
	for (unsigned int i = 0; i < this->m_len; i++)
	{
		sf::Text	text;

		text.setString(this->m_modules[i].outputString());
		y = static_cast<float>(i) * (static_cast<float>(this->m_window.getSize().y) / 12.0f) + 10;
		text.setFont(this->m_font);
		text.setPosition(12.0f, y);
		text.setFillColor(sf::Color::White);
		text.setCharacterSize(20);
		this->m_window.draw(text);

		if (i == 1 || i == 4 || i == 5 || i == 8 || i == 9 || i == 10 || i == 11)
		{
			text.setString("____________________________________________________________________________");
			text.setPosition(10.0f, y + 15);
			text.setFillColor(sf::Color::White);
			text.setCharacterSize(15);
			this->m_window.draw(text);
		}
	}
}



void	SfmlView::run(void)
{
	sf::Clock	clocker;

	try {
		this->m_setFont();
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
		return;
	};
	this->m_window.create(sf::VideoMode(this->m_width, this->m_height), "ft_gkrellm", sf::Style::Titlebar|sf::Style::Close);
	while (this->m_window.isOpen())
	{
		sf::Event	event;

		if (clocker.getElapsedTime().asSeconds() >= 1.0f)
		{
			this->m_window.clear(sf::Color::Black);
			this->m_updateView();
			clocker.restart();
			this->m_window.display();
		}
		while (this->m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				this->m_window.close();
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				return;
		}
	}
}
