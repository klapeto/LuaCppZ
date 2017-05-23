/*
 * LuaTable.hpp
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

#ifndef LUATABLE_HPP_
#define LUATABLE_HPP_

#include "LuaReference.hpp"
#include <functional>

namespace LuaCppZ {

/**
 * Class for providing acess to LuaTables and its fields
 */
class LuaTable: public LuaReference {
public:

	/**
	 * Tries to get the value that exist in the table[key].
	 * The value will be assigned to the one provided. If the types
	 * does not match, it will fail and return false.
	 * @param key The LuaValue that has the key to be used
	 * @param value The LuaValue to assing the value
	 * @return true if the assingment was success, othewise false
	 */
	bool getField(const LuaValue& key, LuaValue& value);

	/**
	 * Assigns the value to the table field with the provided key
	 * eg. table[key]=value
	 * @param key The key to assing the value
	 * @param value The value to assign
	 */
	void setField(const LuaValue& key, const LuaValue& value);

	/**
	 * Iterates through all table elements and calls the lambda function provided.
	 * The lambda function takes as arguments the key of the element and the value.
	 * Both key and value should be checked for its type before casting to specific one
	 * @param func The lambda function to call for all elements
	 */
	void forEach(const std::function<void(const LuaValue&, const LuaValue&)>& func) const;

	bool assignFromStack(LuaState& state, int stackPointer);

	/**
	 * Constructs an empty LuaTable
	 * It cannot be used until it was assigned from LuaState or another LuaTable
	 */
	LuaTable();


	~LuaTable();
};

} /* namespace LuaCppZ */

#endif /* LUATABLE_HPP_ */
