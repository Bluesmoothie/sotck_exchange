#pragma once

#include "finnhub-api-cpp/FinnHubAPI.h"
#include "utils/secretStoreExt.hpp"
#include <fstream>

class save
{
	private:

		std::ifstream	saveFile;
		
	protected:
		
		std::string	_apiKey;
		
		save(void);
		
		void	saveSettings(void);
		void	loadSave(void);
};
