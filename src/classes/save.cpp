#include "classes/save.hpp"

save::save(void) {
	this->saveFile.open("settings.json", std::ifstream::binary);
	if (this->saveFile.is_open()) {
		this->loadSave();
	}
}

void	save::loadSave(void) {
	// Json::Value	settings;

	// this->saveFile >> settings;

	this->_apiKey = retrieveApiKey();
}

void	save::saveSettings(void) {
	// Json::Value	settings;

	saveApiKey(this->_apiKey);
}