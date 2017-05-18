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
 * LuaFunction.cpp
 *
 *  Created on: 17 Μαΐ 2017
 *      Author: klapeto
 */

#include "LuaFunction.hpp"
#include "LuaState.hpp"
#include <lua.hpp>
#include <iostream>

#define saveStackPointer() int sp = lua_gettop(lstate)
#define restoreStackPointer() lua_settop(lstate, sp)

namespace LuaCppZ {

LuaFunction::LuaFunction() :
		LuaReference(LuaValue::Type::Function) {

}

LuaFunction::~LuaFunction() {

}

bool LuaFunction::assignFromStack(LuaState& state, int stackPointer) {
	if (&state != nullptr) {
		lua_State* lstate = state.getCState();
		if (lua_isfunction(lstate, stackPointer)) {

			setReference(state, stackPointer);
			return true;
		}
	}
	return false;
}

void LuaFunction::operator ()(std::initializer_list<const LuaValue*> argumentList,
		std::initializer_list<LuaValue*> returnValues) const {
	if (parentState != nullptr) {
		lua_State* lstate = parentState->getCState();

		saveStackPointer();

		pushToLua(*parentState);

		int argC = 0;
		for (auto arg : argumentList) {
			arg->pushToLua(*parentState);
			++argC;
		}

		if (lua_pcall(lstate, argC, returnValues.size(), 0)) {
			std::cerr << "Error during calling a Lua Function from LuaCppZ: "
					<< lua_tolstring(lstate, -1, nullptr) << std::endl;
			restoreStackPointer();
			return;
		}

		if (lua_gettop(lstate) - sp != returnValues.size()) {
			std::cerr
					<< "Warning! during calling a Lua Function from LuaCppZ: The number of return values do not match the number of return objects passed from C++!"
					<< std::endl;
		}

		int retSp = returnValues.size();
		for (auto ret : returnValues) {
			ret->assignFromStack(*parentState, -retSp);
			--retSp;
		}

		restoreStackPointer();
	}
}

}
/* namespace LuaCppZ */
