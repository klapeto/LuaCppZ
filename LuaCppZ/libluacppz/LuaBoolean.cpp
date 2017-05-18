/*
 * LuaBoolean.cpp
 *
 *  Created on: 18 Μαΐ 2017
 *      Author: klapeto
 */

/*
 * Copyright (c) 2017 Ioannis Panagiotopoulos
 *
 * This file is part of LuaCppZ.
 *
 * LuaCppZ is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Foobar is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
*/

#include "LuaBoolean.hpp"
#include "LuaState.hpp"
#include <lua.hpp>

namespace LuaCppZ {

void LuaBoolean::pushToLua(LuaState& state) const {
	if (&state != nullptr) {
		lua_pushboolean(state.getCState(), value);
	}
}

bool LuaBoolean::assignFromStack(LuaState& state, int stackPointer) {
	if (&state != nullptr) {
		lua_State* lstate = state.getCState();
		if (lua_isboolean(lstate, stackPointer)) {
			value = lua_toboolean(lstate, stackPointer);
			return true;
		}
	}
	return false;
}

} /* namespace LuaCppZ */
