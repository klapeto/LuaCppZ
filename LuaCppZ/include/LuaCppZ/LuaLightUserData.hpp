/*
 * LuaLightUserData.hpp
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
 * LuaCppZ is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with LuaCppZ.  If not, see <http://www.gnu.org/licenses/>.
 *
*/

#ifndef LUALIGHTUSERDATA_HPP_
#define LUALIGHTUSERDATA_HPP_

#include "LuaValue.hpp"
#include "LuaState.hpp"
#include <lua.hpp>

namespace LuaCppZ {

/**
 * Template for passing and retrieving Light user data from and to Lua environment
 */
template<typename T>
class LuaLightUserData: public LuaValue {
public:

	/**
	 * Retrieves the User Data pointer
	 * @return The pointer
	 */
	T* operator->() {
		return ptr;
	}

	void pushToLua(LuaState& state) const {
		if (&state != nullptr) {
			lua_pushlightuserdata(state.getCState(), static_cast<void*>(ptr));
		}
	}

	bool assignFromStack(LuaState& state, int stackPointer) {
		if (&state != nullptr) {
			lua_State* lstate = state.getCState();
			if (lua_islightuserdata(lstate, stackPointer)) {
				ptr = lua_touserdata(lstate, stackPointer);
				return true;
			}
		}
		return false;
	}

	/**
	 * Constructs a LightUserData object with the pointer provided (default = nullptr)
	 */
	LuaLightUserData(T* ptr = nullptr) :
			LuaValue(LuaValue::Type::LightUserData), ptr(ptr) {

	}
	~LuaLightUserData() {

	}
private:
	T* ptr;
};

} /* namespace LuaCppZ */

#endif /* LUALIGHTUSERDATA_HPP_ */
