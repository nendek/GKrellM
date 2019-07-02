/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 12:15:06 by eduriez           #+#    #+#             */
/*   Updated: 2019/06/02 12:30:48 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

# include <string>

class IMonitorModule
{
public:
	virtual ~IMonitorModule(void) {};
	virtual	const std::string	outputString(void) = 0;
private:
	virtual void m_execute() = 0;
};

#endif
