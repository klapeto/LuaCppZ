/*******************************************************************************
 * Copyright (c) 2017 Ioannis Panagiotopoulos
 *
 * This file is part of LuaCppZ.
 *
 * LuaCppZ is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * LuaCppZ is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with LuaCppZ.  If not, see <http://www.gnu.org/licenses/>.
 *******************************************************************************/

/*
 * LuaString.cpp
 *
 *  Created on: 17 Μαΐ 2017
 *      Author: klapeto
 */


#include <lua.hpp>
#include <LuaCppZ/LuaString.hpp>
#include <LuaCppZ/LuaState.hpp>

namespace LuaCppZ {

void LuaString::pushToLua(LuaState& state) const {
	if (&state != nullptr) {
		lua_pushstring(state.getCState(), value.c_str());
	}

}

bool LuaString::assignFromStack(LuaState& state, int stackPointer) {
	if (&state != nullptr) {
		lua_State* lstate = state.getCState();
		if (lua_isstring(lstate, stackPointer)) {
			value = lua_tolstring(lstate, stackPointer, nullptr);
			return true;
		}
	}
	return false;
}

} /* namespace LuaCppZ */
