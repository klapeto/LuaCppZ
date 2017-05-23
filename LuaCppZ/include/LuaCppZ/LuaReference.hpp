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
 * LuaCppZ is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with LuaCppZ.  If not, see <http://www.gnu.org/licenses/>.
 *
*/

#ifndef LUAREFERENCE_HPP_
#define LUAREFERENCE_HPP_

#include "LuaValue.hpp"

namespace LuaCppZ {

class LuaState;

/**
 * Abstact class for providing Reference mechanics to certain LuaValues
 */
class LuaReference: public LuaValue {
public:

	/**
	 * Gets the Reference number this object has inside the Lua environment
	 * @return The reference number
	 */
	int getReference() const {
		return reference;
	}

	void pushToLua(LuaState& state) const;

	LuaReference(const LuaReference&) = delete;
	LuaReference& operator=(const LuaReference&) = delete;

	/**
	 * Constructs A LuaReference with no parent LuaState and no reference
	 * @param type The type of this LuaReference (LuaValue)
	 */
	LuaReference(LuaValue::Type type);
	/**
	 * Constructs A LuaReference with the provided parent LuaState and reference
	 * @param type The type of this LuaReference (LuaValue)
	 * @param state The LuaState that will own this reference
	 * @param reference The reference number
	 */
	LuaReference(LuaValue::Type type, LuaState& state, int reference);

	virtual ~LuaReference();
protected:
	LuaState* parentState;
	int reference;

	/**
	 * Sets the parentState gets a reference from the provided stackPointer
	 * @param state The LuaState that has the value we need a reference to
	 * @param stackPointer The stack index where the value resides
	 */
	void setReference(LuaState& state, int stackPointer);

	/**
	 * Invalidates the LuaReference by setting the parentState to null an reference to NOREF
	 */
	void invalidate();

	friend class LuaState;
};

} /* namespace LuaCppZ */

#endif /* LUAREFERENCE_HPP_ */
