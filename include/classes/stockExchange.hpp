#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include "video.hpp"

class stockExchange {
	private:

		std::vector<std::string>	_indices;

		bool	_addIndex;
		bool	_showIndices;
		bool	_removeIndex;

		void		addIndexPopup(void);
		std::string	addIndex(std::string p_index);
		void		showIndicesPopup(void);
		void		removeIndexPopup(void);

	public:

		stockExchange(void);
		
		void	draw(void);
};