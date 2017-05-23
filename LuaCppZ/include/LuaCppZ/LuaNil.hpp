/*
 * LuaNil.hpp
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

#ifndef LUANIL_HPP_
#define LUANIL_HPP_

#include "LuaValue.hpp"

namespace LuaCppZ {

/**
 * Placeholder class for pushing nil values to Lua environment
 */
class LuaNil: public LuaValue {
public:

	void pushToLua(LuaState& state) const;
	bool assignFromStack(LuaState& state, int stackPointer) {
		return false;
	}

	/**
	 * Constructs a LuaNil object
	 */
	LuaNil() :
			LuaValue(LuaValue::Type::Nil) {

	}

	~LuaNil() {

	}
};

} /* namespace LuaCppZ */

#endif /* LUANIL_HPP_ */
