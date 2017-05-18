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
 * Foobar is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
*/

#ifndef LUATABLE_HPP_
#define LUATABLE_HPP_

#include "LuaReference.hpp"
#include <functional>

namespace LuaCppZ {

class LuaTable: public LuaReference {
public:

	bool getField(const LuaValue& key, LuaValue& value);
	void setField(const LuaValue& key, const LuaValue& value);

	void forEach(const std::function<void(const LuaValue&, const LuaValue&)>& func) const;

	bool assignFromStack(LuaState& state, int stackPointer);

	LuaTable();
	~LuaTable();
};

} /* namespace LuaCppZ */

#endif /* LUATABLE_HPP_ */
