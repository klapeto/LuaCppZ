/*
 * LuaString.cpp
 *
 *  Created on: 17 Μαΐ 2017
 *      Author: klapeto
 */

#include "LuaString.hpp"
#include "LuaState.hpp"
#include <lua.hpp>

namespace LuaCppZ {

void LuaString::pushToLua(LuaState& state) {
	if (&state != nullptr) {
		lua_pushstring(state.getCState(), value.c_str());
	}

}

bool LuaString::assignFromStack(LuaState& state, int stackPointer) {
	if (&state != nullptr) {
		if (lua_isstring(state.getCState(), stackPointer)) {
			value = lua_tolstring(state.getCState(), stackPointer, nullptr);
			return true;
		}
	}
	return false;
}

} /* namespace LuaCppZ */
