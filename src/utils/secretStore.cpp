#include "utils/secretStore.hpp"

bool	saveApiKey(const std::string& p_apiKey) {
	GError*	error = nullptr;

	const bool ok = secret_password_store_sync(
		&secretSchema,
		SECRET_COLLECTION_DEFAULT,
		SECRET_LABEL,
		p_apiKey.c_str(),
		nullptr, &error,
		SECRET_APPLICATION,
		nullptr
	);

	if (!ok) {
		#ifdef DEBUG
			std::cerr << "ApiKey keyring save failed: " << (error ? error->message : "unknow") << std::endl;
		#endif

		g_clear_error(&error);
	}

	return ok;
}

std::string	retrieveApiKey(void) {
	GError*	error = nullptr;

	const gchar*	apiKey = secret_password_lookup_sync(
		&secretSchema,
		nullptr, &error,
		SECRET_APPLICATION,
		nullptr
	);

	if (!apiKey) {
		#ifdef DEBUG
			std::cerr << "ApiKey keyring retrieve failed: " << (error ? error->message : "unknow") << std::endl;
		#endif

		g_clear_error(&error);
	}

	return apiKey ? apiKey : "";
}