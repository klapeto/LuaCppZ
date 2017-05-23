/*
 * LuaValue.hpp
 *
 *  Created on: 16 Μαΐ 2017
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

#ifndef LUAVALUE_HPP_
#define LUAVALUE_HPP_

namespace LuaCppZ {

class LuaState;

/**
 * Abstract base class for all the LuaValues
 */
class LuaValue {
public:

	enum class Type {
		None,
		Nil,
		Boolean,
		Number,
		String,
		Table,
		Function,
		UserData,
		LightUserData
	};

	/**
	 * Pushes the value to the stack of the LuaState provided
	 * @param state The LuaState to push the value
	 */
	virtual void pushToLua(LuaState& state) const=0;

	/**
	 * Tries to assign the value from the value residing in the stack of the LuaState state
	 * at the index stackPointer. If the assignment was success, will return true, otherwise false.
	 *
	 * @param state The state the value resides
	 * @param stackPointer The stack index the value resides
	 * @return true on sucess, otherwise false
	 */
	virtual bool assignFromStack(LuaState& state, int stackPointer)=0;

	/**
	 * Gets the type of this LuaValue
	 * @return The type of this value
	 */
	Type getType() const {
		return type;
	}

	LuaValue(Type type) :
			type(type) {

	}

	virtual ~LuaValue() {

	}
protected:
	Type type;
};

} /* namespace LuaCppZ */

#endif /* LUAVALUE_HPP_ */
