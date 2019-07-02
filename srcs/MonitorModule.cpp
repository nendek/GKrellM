/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonitorModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 15:22:27 by pnardozi          #+#    #+#             */
/*   Updated: 2019/06/02 12:23:08 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MonitorModule.hpp"
#include <cstdio>
#include <exception>

MonitorModule::MonitorModule()
	: m_rawDatas(""), m_module_name(""), m_cmd("")
{
}

MonitorModule::~MonitorModule(void)
{
}

void 	MonitorModule::moduleInit(const std::string &name, const std::string &cmd)
{
	this->m_module_name = name;
	this->m_cmd = cmd;
}

void	MonitorModule::m_execute()
{
	FILE		*pipe = popen(this->m_cmd.c_str(), "r");
	char		buf[200];

	this->m_rawDatas.clear();
	memset(buf, '\0', 200);
	if (pipe != NULL)
	{
		while (fgets(buf, sizeof(buf), pipe) != NULL)
			this->m_rawDatas += buf;
		if (ferror(pipe) != 0)
		{
			pclose(pipe);
			this->m_rawDatas.clear();
			throw (std::exception());
		}
		pclose(pipe);
	}
	else
		throw (std::exception());
}

const std::string	&MonitorModule::getRawDatas(void) const
{
	return (this->m_rawDatas);
}

const std::string	&MonitorModule::getModuleName(void) const
{
	return (this->m_module_name);
}

const std::string	MonitorModule::outputString(void)
{
	this->m_execute();
	std::string result = this->m_module_name + ": " + this->m_rawDatas;
	return result;
}
