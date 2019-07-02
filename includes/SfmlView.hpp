#ifndef SFMLVIEW_HPP
# define SFMLVIEW_HPP

# include "IMonitorDisplay.hpp"
# include "MonitorModule.hpp"
# include <SFML/Graphics.hpp>

class SfmlView: public IMonitorDisplay
{
public:
	SfmlView(int width, int height);
	virtual ~SfmlView(void);

	virtual void		setModules(MonitorModule *, unsigned int const);
	virtual MonitorModule*	getModules(void);
	virtual void 		run(void);

private:
	SfmlView(SfmlView const &src);
	SfmlView &operator=(SfmlView const &src);
	SfmlView(void);
	virtual void	m_updateView(void);
	void 		m_setFont(void);
	MonitorModule	*m_modules;
	unsigned int 	m_len;
	int 		m_width;
	int 		m_height;
	sf::RenderWindow m_window;
	sf::Font 	m_font;

};

#endif
