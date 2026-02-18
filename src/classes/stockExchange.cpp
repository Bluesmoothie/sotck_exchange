#include "classes/stockExchange.hpp"

stockExchange::stockExchange(void) : _addIndex(false), _showIndices(false), _removeIndex(false) {}

void	stockExchange::draw(void) {
		ImGui::BeginMainMenuBar(); {
			if (ImGui::BeginMenu("Indices")) {
				this->_addIndex = ImGui::MenuItem("Add index", "Ctrl+A");
				this->_showIndices = ImGui::MenuItem("Show indices", "Ctrl+S");
				this->_removeIndex = ImGui::MenuItem("Remove index", "Ctrl+R");
				ImGui::EndMenu();
			}

			if (ImGui::BeginMenu("Select index")) {
				if (this->_indices.empty()) {
					ImGui::PushStyleColor(ImGuiCol_Text, color_medium_grey);
					ImGui::MenuItem("Empty...", nullptr, false, false);
					ImGui::PopStyleColor(1);
				} else {
					std::vector<std::string>::iterator	it = this->_indices.begin();
					std::vector<std::string>::iterator	ite = this->_indices.end();
					for (; it != ite; ++it) {
						ImGui::MenuItem((*it).c_str());
					}
				}
				ImGui::EndMenu();
			}
		} ImGui::EndMainMenuBar();

		this->addIndexPopup();
}

void	stockExchange::addIndexPopup(void) {
	static std::string	message = {};
	static std::string	buff = {};

	if (this->_addIndex) {
		ImGui::OpenPopup("Add index");
		this->_addIndex = false;
		message.clear();
		buff.clear();
	}
	
	if (ImGui::BeginPopupModal("Add index", nullptr, ImGuiWindowFlags_AlwaysAutoResize)) {
		ImGui::Text("Index:");
		ImGui::SameLine();
		ImGui::InputText("##indexInput", &buff);

		ImGui::Spacing();

		ImGui::SetCursorPosX(20.0f);
		if (ImGui::Button("Add", ImVec2(100.0f, 0))) {
			message = this->addIndex(buff);
			if (message == "OK") {
				message.clear();
				ImGui::CloseCurrentPopup();
			}
		}
		ImGui::SameLine(ImGui::GetWindowWidth() - 100.0f - 20.0f);
		if (ImGui::Button("Cancel", ImVec2(100.0f, 0)))
			ImGui::CloseCurrentPopup();

		if (!message.empty()) {
			ImVec2	text_size = ImGui::CalcTextSize(message.c_str());

			ImGui::PushStyleColor(ImGuiCol_Text, color_red);
			ImGui::SetCursorPosX((ImGui::GetContentRegionAvail().x - text_size.x) * 0.5f);
			ImGui::Text("%s", message.c_str());
			ImGui::PopStyleColor(1);

		} else
			ImGui::Text("");

		ImGui::EndPopup();
	}
}

std::string	stockExchange::addIndex(std::string p_index) {
	if (p_index.size() == 0)
		return "Empty text";

	std::vector<std::string>::iterator	ite = this->_indices.end();
	if (std::find(this->_indices.begin(), ite, p_index) != ite)
		return ("Index aleady added");
	
	this->_indices.push_back(p_index);
	return ("OK");
}

void	stockExchange::showIndicesPopup(void) {

}

void	stockExchange::removeIndexPopup(void) {

}
