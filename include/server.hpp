#pragma once

#include <fstream>
#include <iostream>
#include <set>
#include <unordered_map>

#include <crab/crab.hpp>
#include <inja/inja.hpp>

#include "database.hpp"
#include "log.hpp"
#include "mountpoint.hpp"
#include "router.hpp"
#include "script.hpp"

namespace schwifty::krabby {

namespace http = crab::http;
namespace sql  = sql_bridge;

class server {
public:
	explicit server(uint16_t port, std::string path);

	static void json_response(http::Client *who, int code, std::string msg = std::string{});
	static void html_response(http::Client *who, int code, std::string msg = std::string{});
	static void text_response(http::Client *who, int code, std::string msg = std::string{});

private:
	http::Server server_;   // http service provider
	sql::context ctx_;      // context for database
	script_engine script_;  // main scripting interface

	std::set<http::Client *> connections_;  // open connections. todo: struct for them
};

}  // namespace schwifty::krabby