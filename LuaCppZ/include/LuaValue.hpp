/*
 * LuaValue.hpp
 *
 *  Created on: 16 Μαΐ 2017
 *      Author: klapeto
 */

#ifndef LUAVALUE_HPP_
#define LUAVALUE_HPP_

namespace LuaCppZ {

class LuaState;

class LuaValue {
public:

	enum class Type {
		None, Nil, Number, String, Table, Function, UserData
	};

	virtual void pushToLua(LuaState& state)=0;
	virtual bool assignFromStack(LuaState& state, int stackPointer)=0;

	Type getType() const {
		return type;
	}

	LuaValue(Type type) :
			type(type) {

	}

	virtual ~LuaValue() {

	}
protected:
	Type type;
};

} /* namespace LuaCppZ */

#endif /* LUAVALUE_HPP_ */
