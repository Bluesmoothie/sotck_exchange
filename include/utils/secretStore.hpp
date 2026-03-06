#pragma once

#include <libsecret/secret.h>
#include <glib-2.0/glib.h>
#include <string>
#ifdef DEBUG
# include <iostream>
#endif

#define SECRET_LABEL		"Stock Exchange Api Key"
#define SECRET_APPLICATION	"application", "Stock Exchange"

static const SecretSchema	secretSchema = {
	"fr.yvesgille.stock_exchange.apiKey",
	SECRET_SCHEMA_NONE,
	{
		{ "application", SECRET_SCHEMA_ATTRIBUTE_STRING },
		{ nullptr, SECRET_SCHEMA_ATTRIBUTE_STRING }
	},
	0,          // reserved
    nullptr,    // reserved1
    nullptr,    // reserved2
    nullptr,    // reserved3
    nullptr,    // reserved4
    nullptr,    // reserved5
    nullptr,    // reserved6
    nullptr     // reserved7
};