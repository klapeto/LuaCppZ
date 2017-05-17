/*
 * LuaNumber.cpp
 *
 *  Created on: 16 Μαΐ 2017
 *      Author: klapeto
 */

#include "LuaNumber.hpp"
#include "LuaState.hpp"

namespace LuaCppZ {

void LuaNumber::pushToLua(LuaState& state) {
	if (&state != nullptr) {
		lua_pushnumber(state.getCState(), value);
	}
}

bool LuaNumber::assignFromStack(LuaState& state, int stackPointer) {
	if (&state != nullptr) {
		if (lua_isnumber(state.getCState(), stackPointer)) {
			value = lua_tonumber(state.getCState(), stackPointer);
			return true;
		}
	}
	return false;
}

} /* namespace LuaCppZ */
