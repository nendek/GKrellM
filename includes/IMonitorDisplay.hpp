/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 12:48:12 by eduriez           #+#    #+#             */
/*   Updated: 2019/06/02 12:30:47 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

# include <string>
# include "MonitorModule.hpp"

class IMonitorDisplay
{
	public:
		virtual 		~IMonitorDisplay(void) {};
		virtual void 		run(void) = 0;
		virtual void 		setModules(MonitorModule *modules, unsigned int const len) = 0;
		virtual MonitorModule*	getModules(void) = 0;
	private:
		virtual void 		m_updateView(void) = 0;


};

#endif
