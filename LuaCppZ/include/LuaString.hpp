/*
 * LuaString.hpp
 *
 *  Created on: 17 Μαΐ 2017
 *      Author: klapeto
 */

#ifndef LUASTRING_HPP_
#define LUASTRING_HPP_

#include "LuaValue.hpp"
#include <string>

namespace LuaCppZ {

class LuaString: public LuaValue {
public:

	const std::string& getValue() const {
		return value;
	}

	void pushToLua(LuaState& state);
	bool assignFromStack(LuaState& state, int stackPointer);

	LuaString() :
			LuaValue(LuaValue::Type::String) {

	}

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
