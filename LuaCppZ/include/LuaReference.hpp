/*
 * LuaReference.hpp
 *
 *  Created on: 16 Μαΐ 2017
 *      Author: klapeto
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

	void pushToLua(LuaState& state);

	LuaReference(LuaValue::Type type);
	LuaReference(LuaValue::Type type, LuaState& state, int reference);
	virtual ~LuaReference();
protected:
	LuaState* parentState;
	int reference;

	void setReference(int reference) {
		this->reference = reference;
	}

	void setParentState(LuaState& state) {
		this->parentState = &state;
	}

	friend class LuaState;
};

} /* namespace LuaCppZ */

#endif /* LUAREFERENCE_HPP_ */
