/*
 * LuaString.hpp
 *
 *  Created on: 17 Μαΐ 2017
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

#ifndef LUASTRING_HPP_
#define LUASTRING_HPP_

#include "LuaValue.hpp"
#include <string>

namespace LuaCppZ {

class LuaString: public LuaValue {
public:

	const std::string& getValue() const {
		return value;
	}

	void pushToLua(LuaState& state) const;
	bool assignFromStack(LuaState& state, int stackPointer);

	LuaString& operator=(const std::string& value) {
		this->value = value;
		return *this;
	}

	LuaString() :
			LuaValue(LuaValue::Type::String) {

	}

	LuaString(const std::string& value) :
			LuaValue(LuaValue::Type::String), value(value) {

	}

	~LuaString() {

	}
private:
	std::string value;
};

} /* namespace LuaCppZ */

#endif /* LUASTRING_HPP_ */
