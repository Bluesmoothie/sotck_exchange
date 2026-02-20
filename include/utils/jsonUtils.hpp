#pragma once

#include <jsoncpp/json/json.h>

namespace	jsonUtils {

	bool				isErrorResponse(const Json::Value* p_res);
	const std::string	getResponseError(const Json::Value* p_res);
}
