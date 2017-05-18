/*
 * LuaBoolean.hpp
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

#ifndef LUABOOLEAN_HPP_
#define LUABOOLEAN_HPP_

#include "LuaValue.hpp"

namespace LuaCppZ {

class LuaState;

class LuaBoolean: public LuaValue {
public:

	bool getValue() const {
		return value;
	}

	void pushToLua(LuaState& state) const;
	bool assignFromStack(LuaState& state, int stackPointer);

	LuaBoolean(bool value = false) :
			LuaValue(LuaValue::Type::Boolean), value(value) {

	}
	~LuaBoolean() {

	}
private:
	bool value;
};

} /* namespace LuaCppZ */

#endif /* LUABOOLEAN_HPP_ */
