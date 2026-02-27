#pragma once

#include "unifiedGraphicsConf.hpp"

#include <string>
#include <functional>

#define TTT_WINDOW_TITLE	"Stock exchange"
#define TTT_WINDOW_WIDTH	1720
#define TTT_WINDOW_HEIGH	880

const ImVec4	clear_color = ImVec4(0.67f, 0.83f, 0.02f, 1.00f);

class	Video {

private:

	std::function<void()>	_draw_func;

	SDL_Window* 	_window;
	ImGuiIO 		_io;
	SDL_GLContext 	_gl_context;
	ImGuiViewport*	_viewport;

	bool			_initialized;
	bool			_done;

public:

	Video(std::function<void()> p_draw_func);
	~Video(void);

	int		init(void);
	void	deinit(void);

	void	loop(void);
	void	treatEvents(void);
	void	draw(void);
	void	render(void);

};