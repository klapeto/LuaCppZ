/*
 * LuaUserData.hpp
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

#ifndef LUAUSERDATA_HPP_
#define LUAUSERDATA_HPP_

#include "LuaReference.hpp"
#include "LuaState.hpp"
#include <lua.hpp>

namespace LuaCppZ {

/**
 * Template for creating User data inside the Lua environment
 */
template<typename T>
class LuaUserData: public LuaReference {
public:

	bool assignFromStack(LuaState& state, int stackPointer) {
		if (parentState != nullptr) {
			parentState->releaseReference(*this);
		}
		if (&state != nullptr) {
			if (lua_isuserdata(state.getCState(), stackPointer)) {
				setReference(state, stackPointer);
				return true;
			}
		}
		return false;
	}

	/**
	 * Gets the size of the user data in number of elements
	 * @return The number of elements reside in the pointer
	 */
	size_t getSize() const {
		return size;
	}

	/**
	 * Gets the pointer to the data
	 * @return The pointer
	 */
	T* operator->() {
		return ptr;
	}

	/**
	 * Gets a specific element from the subscript provided
	 * \notice Be advised that of the bounds'
	 * @param index The index in array
	 * @return The element
	 */
	T* operator[](size_t index) {
		if (ptr != nullptr) {
			if (index < size) {
				return ptr[index];
			}
		}
		return ptr;
	}

	/**
	 * Constructs an Empty LuaUserData with no data (Null)
	 */
	LuaUserData() :
			LuaReference(LuaValue::Type::UserData), size(0), ptr(nullptr) {

	}

	/**
	 * Constructs a LuaUserData object from the LuaState provided and amount of objects
	 * specified from the size argument
	 *
	 * @param state The LuaState to construct the data
	 * @param size The amount of objects to construct
	 */
	LuaUserData(LuaState& state, size_t size = 1) :
			LuaReference(LuaValue::Type::UserData), size(size), ptr(nullptr) {
		if (&state != nullptr && size != 0) {
			lua_State* lstate = state.getCState();
			int sp = lua_gettop(lstate);

			ptr = static_cast<T*>(lua_newuserdata(lstate, size * sizeof(T)));
			setReference(state, -1);

			lua_settop(lstate, sp);
		}
	}

	~LuaUserData() {

	}
private:
	T* ptr;
	size_t size;
};

} /* namespace LuaCppZ */

#endif /* LUAUSERDATA_HPP_ */
