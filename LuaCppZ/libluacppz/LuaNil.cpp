/*******************************************************************************
 * Copyright (c) 2017 Ioannis Panagiotopoulos
 *
 * This file is part of Foobar.
 *
 * Foobar is free software: you can redistribute it and/or modify
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
 *******************************************************************************/

/*
 * LuaNil.cpp
 *
 *  Created on: 17 Μαΐ 2017
 *      Author: klapeto
 */

#include "LuaNil.hpp"
#include "LuaState.hpp"
#include <lua.hpp>

namespace LuaCppZ {

void LuaNil::pushToLua(LuaState& state) const {
	if (&state != nullptr) {
		lua_pushnil(state.getCState());
	}
}

} /* namespace LuaCppZ */
