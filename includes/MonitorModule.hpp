/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonitorModul.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 15:20:08 by pnardozi          #+#    #+#             */
/*   Updated: 2019/06/02 12:32:43 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITORMODULE_HPP
# define MONITORMODULE_HPP

# include "IMonitorModule.hpp"

class MonitorModule : public IMonitorModule
{
public:
	MonitorModule(void);
	virtual ~MonitorModule(void);
	void moduleInit(const std::string &name, const std::string &cmd);
	const std::string	&getRawDatas(void) const;
	const std::string	&getModuleName(void) const;
	const std::string	outputString(void);

private:
	virtual void m_execute();
	MonitorModule(const MonitorModule &src);
	MonitorModule &operator=(const MonitorModule &rhs);

	std::string		m_rawDatas;
	std::string		m_module_name;
	std::string 	m_cmd;
};

#endif
