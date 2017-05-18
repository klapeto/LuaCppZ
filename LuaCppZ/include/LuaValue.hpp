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
 * Foobar is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
*/

#ifndef LUAVALUE_HPP_
#define LUAVALUE_HPP_

namespace LuaCppZ {

class LuaState;

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

	virtual void pushToLua(LuaState& state) const=0;
	virtual bool assignFromStack(LuaState& state, int stackPointer)=0;

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
