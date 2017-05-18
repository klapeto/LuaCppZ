/*
 * LuaReference.hpp
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

#ifndef LUAREFERENCE_HPP_
#define LUAREFERENCE_HPP_

#include "LuaValue.hpp"

namespace LuaCppZ {

class LuaState;

class LuaReference: public LuaValue {
public:

	int getReference() const {
		return reference;
	}

	void pushToLua(LuaState& state) const;

	LuaReference(LuaValue::Type type);
	LuaReference(LuaValue::Type type, LuaState& state, int reference);

	LuaReference(const LuaReference&) = delete;
	LuaReference& operator=(const LuaReference&) = delete;

	virtual ~LuaReference();
protected:
	LuaState* parentState;
	int reference;

	void setReference(LuaState& state, int stackPointer);

	friend class LuaState;
};

} /* namespace LuaCppZ */

#endif /* LUAREFERENCE_HPP_ */
