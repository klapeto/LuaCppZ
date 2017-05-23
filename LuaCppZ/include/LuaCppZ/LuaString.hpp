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
 * LuaCppZ is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with LuaCppZ.  If not, see <http://www.gnu.org/licenses/>.
 *
*/

#ifndef LUASTRING_HPP_
#define LUASTRING_HPP_

#include "LuaValue.hpp"
#include <string>

namespace LuaCppZ {

/**
 * Class for passing and retrieving strings from and to Lua environment
 */
class LuaString: public LuaValue {
public:

	/**
	 * Gets the actual string
	 * @return The std::string containing the string
	 */
	const std::string& getValue() const {
		return value;
	}

	void pushToLua(LuaState& state) const;
	bool assignFromStack(LuaState& state, int stackPointer);

	/**
	 * Assigns the string to this LuaString
	 * @return The same object
	 */
	LuaString& operator=(const std::string& value) {
		this->value = value;
		return *this;
	}

	/**
	 * Constructs a LuaString with no value
	 */
	LuaString() :
			LuaValue(LuaValue::Type::String) {

	}

	/**
	 * Constructs a LuaString and assigns the value
	 * @param value The string to assign
	 */
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
