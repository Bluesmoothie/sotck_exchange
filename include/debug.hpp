#pragma once

#include <iostream>

#define DEBUG_CLOSE_POPUP(popupName, popupType, reason)	std::cout << "Closing popup " << popupType << " |" << popupName << "| because " << reason << std::endl;

#define DEBUG_POPUP_TYPE_OBLIGATORY_INPUT	"obligatory input"
#define	DEBUG_POPUP_TYPE_INPUT				"input"
#define DEBUG_POPUP_TYPE_SELECTABLE_LIST	"selectable list"

#define	DEBUG_REASON_CANCEL			"cancel button clicked"
#define	DEBUG_REASON_CLOSE_ON_OK	"ok button clicked and closeOnOk = true"
#define	DEBUG_REASON_CLOSE_ON_VALID	"ok button clicked and callback function returned OK"