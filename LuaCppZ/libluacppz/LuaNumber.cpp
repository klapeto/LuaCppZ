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
 * LuaNumber.cpp
 *
 *  Created on: 16 Μαΐ 2017
 *      Author: klapeto
 */

#include <LuaCppZ/LuaNumber.hpp>
#include <LuaCppZ/LuaState.hpp>

namespace LuaCppZ {

void LuaNumber::pushToLua(LuaState& state) const {
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
