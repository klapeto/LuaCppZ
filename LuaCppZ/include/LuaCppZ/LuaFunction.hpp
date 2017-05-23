/*
 * LuaFunction.hpp
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

#ifndef LUAFUNCTION_HPP_
#define LUAFUNCTION_HPP_

#include <initializer_list>

#include "LuaReference.hpp"

namespace LuaCppZ {

/**
 * Class for calling and retrieving Functions from and to Lua environment
 */
class LuaFunction: public LuaReference {
public:

	bool assignFromStack(LuaState& state, int stackPointer);

	/**
	 * Calls the Lua function with the arguments provided.
	 * The return values of this function will be assigned to the LuaValues
	 * provided in that order. Both arguments and return values must be constructed
	 * and passed as pointers.
	 *
	 * @param argumentList A brace enclosed list of the pointers of the LuaValues that will be used as arguments
	 * @param returnValues A brace enclosed list of the pointers of the LuaValues that will be assigned the return values
	 */
	void call(std::initializer_list<const LuaValue*> argumentList = { },
			std::initializer_list<LuaValue*> returnValues = { }) const {
		operator ()(argumentList, returnValues);
	}

	/**
	 * \see call
	 */
	void operator ()(std::initializer_list<const LuaValue*> argumentList = { },
			std::initializer_list<LuaValue*> returnValues = { }) const;

	/**
	 * Constructs a LuaFunction
	 * This object has no use unless assigned from a table or the LuaState
	 */
	LuaFunction();

	~LuaFunction();
};

} /* namespace LuaCppZ */

#endif /* LUAFUNCTION_HPP_ */
