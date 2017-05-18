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
 * Foobar is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
*/

#ifndef LUAUSERDATA_HPP_
#define LUAUSERDATA_HPP_

#include "LuaReference.hpp"
#include "LuaState.hpp"
#include <lua.hpp>

namespace LuaCppZ {

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

	size_t getSize() const {
		return size;
	}

	T* operator->() {
		return ptr;
	}

	T* operator[](size_t index) {
		if (ptr != nullptr) {
			if (index < size) {
				return ptr[index];
			}
		}
		return ptr;
	}

	LuaUserData() :
			LuaReference(LuaValue::Type::UserData), size(0), ptr(nullptr) {

	}

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
