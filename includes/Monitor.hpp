/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monitor.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 19:23:40 by pnardozi          #+#    #+#             */
/*   Updated: 2019/06/02 12:31:27 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITOR_HPP
# define MONITOR_HPP

#include <ncurses.h>
#include "NcursesView.hpp"
#include "MonitorModule.hpp"
#include "SfmlView.hpp"

class Monitor
{
public:
	Monitor(void);
	virtual ~Monitor(void);
	void	ncursesChoice(void);
	void	sfmlChoice(void);

private:
	Monitor(const Monitor &src);
	Monitor &operator=(const Monitor &rhs);
	void 	m_moduleInit(void);
	MonitorModule *m_tab;
};

#endif
