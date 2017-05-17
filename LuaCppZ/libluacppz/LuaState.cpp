/*
 * LuaState.cpp
 *
 *  Created on: 14 Μαΐ 2017
 *      Author: klapeto
 */

#include "LuaState.hpp"
#include "LuaTable.hpp"
#include "Tokenizer.hpp"
#include <iostream>

#define saveStackPointer() int sp = lua_gettop(lstate)
#define restoreStackPointer() lua_settop(lstate, sp)

namespace LuaCppZ {

LuaState::LuaState() {
	lstate = luaL_newstate();
}

LuaState::~LuaState() {
	if (lstate != nullptr) {
		lua_close(lstate);
	}
}

void LuaState::loadLibraries() {
	luaL_openlibs(lstate);
}

void LuaState::executeCode(const std::string& code) {
	saveStackPointer();

	if (luaL_loadstring(lstate, code.c_str())) {
		std::cerr << "Error during loading Lua string code: "
				<< lua_tostring(lstate, -1);
		restoreStackPointer();
		return;
	}

	if (lua_pcall(lstate, 0, 0, 0)) {
		std::cerr << "Error during execution of Lua string code: "
				<< lua_tostring(lstate, -1);
	}

	restoreStackPointer();

}

void LuaState::executeFile(const std::string& filepath) {
	saveStackPointer();

	if (luaL_loadfile(lstate, filepath.c_str())) {
		std::cerr << "Error during loading Lua file: "
				<< lua_tostring(lstate, -1);
		restoreStackPointer();
		return;
	}

	if (lua_pcall(lstate, 0, 0, 0)) {
		std::cerr << "Error during execution of Lua string code: "
				<< lua_tostring(lstate, -1);
	}

	restoreStackPointer();
}

void LuaState::addReference(LuaReference& reference) {

	if (&reference != nullptr) {
		references.insert(&reference);
	}
}

void LuaState::releaseReference(LuaReference& reference) {
	if (&reference != nullptr) {
		lua_unref(lstate, reference.getReference());
		references.erase(&reference);
	}
}

bool LuaState::getVariable(const std::string& name, LuaValue& value) {
	saveStackPointer();
	pushValue(name);
	bool ret = value.assignFromStack(*this, -1);
	restoreStackPointer();
	return ret;
}

void LuaState::pushValue(const std::string& name) {
	std::list<std::string> tokens;

	Tokenizer::parse(tokens, name, '.');

	lua_getglobal(lstate, tokens.begin()->c_str());

	tokens.pop_front();

	if (lua_istable(lstate, -1)) {

		for (auto& token : tokens) {

			lua_pushstring(lstate, token.c_str());
			lua_gettable(lstate, -2);

			if (!lua_istable(lstate, -1)) {
				break;
			}
		}

	}
}

} /* namespace LuaCppZ */