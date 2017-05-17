/*
 * LuaNumber.hpp
 *
 *  Created on: 16 Μαΐ 2017
 *      Author: klapeto
 */

#ifndef LUANUMBER_HPP_
#define LUANUMBER_HPP_

#include <lua.hpp>

#include "LuaValue.hpp"

namespace LuaCppZ {

class LuaNumber: public LuaValue {
public:

	lua_Number getValue() const {
		return value;
	}

	void pushToLua(LuaState& state);
	bool assignFromStack(LuaState& state, int stackPointer);

	LuaNumber() :
			LuaValue(LuaValue::Type::Number), value(0.0) {

	}

	LuaNumber(lua_Number value) :
			LuaValue(LuaValue::Type::Number), value(value) {

	}

	~LuaNumber() {

	}
private:
	lua_Number value;
};

} /* namespace LuaCppZ */

#endif /* LUANUMBER_HPP_ */
