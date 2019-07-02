/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monitor.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 19:23:21 by pnardozi          #+#    #+#             */
/*   Updated: 2019/06/02 12:23:01 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Monitor.hpp"
#include <iostream>

Monitor::Monitor()
{
}

Monitor::~Monitor(void)
{
	delete [] this->m_tab;
}


void	Monitor::m_moduleInit()
{
	this->m_tab = new MonitorModule[12];
	this->m_tab[0].moduleInit("hostname", "hostname -f");
	this->m_tab[1].moduleInit("username", "id -un");
	this->m_tab[2].moduleInit("OS name", "sw_vers -productName");
	this->m_tab[3].moduleInit("version", "sw_vers -productVersion");
	this->m_tab[4].moduleInit("build", "sw_vers -buildVersion");
	this->m_tab[5].moduleInit("Date", "date");
	this->m_tab[6].moduleInit("CPU name", "sysctl -n machdep.cpu.brand_string");
	this->m_tab[7].moduleInit("Nb core", "sysctl -n hw.ncpu");
	this->m_tab[8].moduleInit("Usage", "top -l 1 | grep 'CPU usage' | cut -d ':' -f 2");
	this->m_tab[9].moduleInit("PhysMem", "top -l 1 | grep 'PhysMem' | cut -d ':' -f 2");
	this->m_tab[10].moduleInit("Networks", "top -l 1 | grep 'Networks' | cut -d ':' -f 2,3");
	this->m_tab[11].moduleInit("Disk", "top -l 1 | grep 'Disks' | cut -d ':' -f 2,3");
}

void	Monitor::ncursesChoice(void)
{
	NcursesView view;
	try {
		this->m_moduleInit();
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
		return;
	}
	view.setModules(this->m_tab, 12);
	view.run();
}

void	Monitor::sfmlChoice(void)
{
	SfmlView view(640, 480);
	try {
		this->m_moduleInit();
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
		return;
	}
	view.setModules(this->m_tab, 12);
	view.run();
}
