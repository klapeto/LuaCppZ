/*
 * LuaTable.hpp
 *
 *  Created on: 16 Μαΐ 2017
 *      Author: klapeto
 */

#ifndef LUATABLE_HPP_
#define LUATABLE_HPP_

#include "LuaReference.hpp"

namespace LuaCppZ {

class LuaTable: public LuaReference {
public:

	bool getField(const LuaValue& key, LuaValue& value);
	void setField(const LuaValue& key, const LuaValue& value);

	bool assignFromStack(LuaState& state, int stackPointer);

	LuaTable();
	~LuaTable();
};

} /* namespace LuaCppZ */

#endif /* LUATABLE_HPP_ */
