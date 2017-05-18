/*
 * LuaNumber.hpp
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

#ifndef LUANUMBER_HPP_
#define LUANUMBER_HPP_

#include <lua.hpp>

#include "LuaValue.hpp"

namespace LuaCppZ {

class LuaNumber: public LuaValue {
public:

	lua_Number getValue() const {
		return value;
	}

	void pushToLua(LuaState& state) const;
	bool assignFromStack(LuaState& state, int stackPointer);

	LuaNumber& operator=(lua_Number value) {
		this->value = value;
		return *this;
	}

	LuaNumber() :
			LuaValue(LuaValue::Type::Number), value(0.0) {

	}

	LuaNumber(lua_Number value) :
			LuaValue(LuaValue::Type::Number), value(value) {

	}

	~LuaNumber() {

	}
private:
	lua_Number value;
};

} /* namespace LuaCppZ */

#endif /* LUANUMBER_HPP_ */
