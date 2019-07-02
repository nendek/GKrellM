/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcursesView.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 16:43:50 by pnardozi          #+#    #+#             */
/*   Updated: 2019/06/02 12:33:33 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURSESVIEW_HPP
# define NCURSESVIEW_HPP

#include "IMonitorDisplay.hpp"
#include "MonitorModule.hpp"
#include <ncurses.h>
#include <unistd.h>

class NcursesView: public IMonitorDisplay
{

public:
	NcursesView(void);
	virtual ~NcursesView(void);

	virtual void 		run(void);
	virtual void		setModules(MonitorModule *, unsigned int const);
	virtual MonitorModule*	getModules(void);

private:
	NcursesView(NcursesView const &src);
	NcursesView &operator=(NcursesView const &src);
	virtual void		m_updateView(void);
	MonitorModule		*m_modules;
	unsigned int 		m_len;
	void			m_display_line(int x, char c);

};

#endif
