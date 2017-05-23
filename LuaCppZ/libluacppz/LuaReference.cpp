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
 * LuaReference.cpp
 *
 *  Created on: 16 Μαΐ 2017
 *      Author: klapeto
 */


#include <lua.hpp>
#include <LuaCppZ/LuaReference.hpp>
#include <LuaCppZ/LuaState.hpp>

namespace LuaCppZ {

LuaReference::LuaReference(LuaValue::Type type) :
		LuaValue(type), parentState(nullptr), reference(LUA_NOREF) {

}

LuaReference::LuaReference(LuaValue::Type type, LuaState& state, int reference) :
		LuaValue(type), parentState(&state), reference(reference) {
	parentState->addReference(*this);
}

LuaReference::~LuaReference() {
	if (parentState != nullptr) {
		parentState->releaseReference(*this);
	}
}

void LuaReference::pushToLua(LuaState& state) const {
	if (&state != nullptr) {
		lua_getref(state.getCState(), reference);
	}
}

void LuaReference::setReference(LuaState& state, int stackPointer) {
	lua_pushvalue(state.getCState(), stackPointer);
	reference = luaL_ref(state.getCState(), LUA_REGISTRYINDEX);
	parentState = &state;
	state.addReference(*this);

}

void LuaReference::invalidate() {
	parentState = nullptr;
	reference = LUA_NOREF;
}

} /* namespace LuaCppZ */
