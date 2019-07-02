/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcursesView.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 17:06:46 by pnardozi          #+#    #+#             */
/*   Updated: 2019/06/02 12:33:32 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NcursesView.hpp"

NcursesView::NcursesView(void) : m_modules(NULL), m_len(0)
{
}

NcursesView::~NcursesView(void)
{
}

MonitorModule * NcursesView::getModules(void)
{
	return this->m_modules;
}

void	NcursesView::setModules(MonitorModule *mod, unsigned int const len)
{
	this->m_modules = mod;
	this->m_len = len;
}

void 	NcursesView::run(void)
{
	initscr();
	noecho();
	nodelay(stdscr, TRUE);
	curs_set(0);

	keypad(stdscr, TRUE);
	refresh();
	while (true)
	{
		if (getch() == 'q')
			break;
		this->m_updateView();
		refresh();
		sleep(1);
	}
	endwin();
}

void	NcursesView::m_updateView(void)
{
	int line = 1;
	std::string str;

	this->m_display_line(0, '-');
	for (unsigned int i = 0; i < this->m_len; i++)
	{
		if (i == 2 || i == 5 || i == 6 || i == 9 || i == 10 || i == 11 || i == 12)
		{
			this->m_display_line(line, '-');
			line++;
			this->m_display_line(line, '-');
			line++;
		}
		str = this->m_modules[i].outputString();
		for (size_t j = 0; j < str.length(); j++)
		{
			move(line, 0 + j);
			addch(str[j]);
		}
		line++;
	}
	this->m_display_line(line, '-');
}

void	NcursesView::m_display_line(int x, char c)
{
	for (int i = 0; i < 70; i++)
	{
		move(x, i);
		addch(c);
	}
}
