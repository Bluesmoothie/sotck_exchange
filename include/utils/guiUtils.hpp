#pragma once

#include "unifiedGraphicsConf.hpp"

#ifdef DEBUG
# include "debug.hpp"
#endif

#include <functional>

#include "ui.hpp"

namespace	guiUtils {
	void	obligatoryInputPopup(std::string& buff, std::string& message, const char popupName[], const std::string& inputName, std::function<std::string(const std::string&)> callbackFunc);
	void	inputPopup(std::string& buff, std::string& message, const char popupName[], const std::string& inputName, std::function<std::string(const std::string&)> callbackFunc);
	void	selectableListPopup(const char popupName[], std::vector<std::string>& list, std::vector<std::string>::difference_type& selectedIndex, std::function<void(const std::vector<std::string>::difference_type)> setFunc, bool closeOnOk = 1);
}