/*
 * LuaTable.cpp
 *
 *  Created on: 16 Μαΐ 2017
 *      Author: klapeto
 */

#include "LuaTable.hpp"
#include "LuaState.hpp"
#include <lua.hpp>

#define saveStackPointer(lstate) int sp = lua_gettop(lstate)
#define restoreStackPointer(lstate) lua_settop(lstate, sp)

namespace LuaCppZ {

LuaTable::LuaTable() :
		LuaReference(LuaValue::Type::Table) {

}
LuaTable::~LuaTable() {

}

bool LuaTable::getField(const LuaValue& key, LuaValue& value) {
	if (parentState != nullptr) {
		saveStackPointer(parentState->getCState());
		pushToLua(*parentState);
		const_cast<LuaValue&>(key).pushToLua(*parentState);
		lua_gettable(parentState->getCState(), -2);
		bool ret = value.assignFromStack(*parentState, -1);
		restoreStackPointer(parentState->getCState());
		return ret;
	} else {
		// TODO: Error output?
		return false;
	}
}

void LuaTable::setField(const LuaValue& key, const LuaValue& value) {
	if (parentState != nullptr) {
		lua_State* lstate = parentState->getCState();
		saveStackPointer(lstate);
		pushToLua(*parentState);
		const_cast<LuaValue&>(key).pushToLua(*parentState);
		const_cast<LuaValue&>(value).pushToLua(*parentState);
		lua_settable(lstate, -3);
		restoreStackPointer(lstate);
	}
}

bool LuaTable::assignFromStack(LuaState& state, int stackPointer) {
	if (parentState != nullptr) {
		parentState->releaseReference(*this);
	}
	if (&state != nullptr) {
		lua_State *lstate = state.getCState();

		if (lua_istable(lstate, stackPointer)) {
			lua_pushvalue(lstate, stackPointer);
			reference = luaL_ref(lstate, LUA_REGISTRYINDEX);
			parentState = &state;
			state.addReference(*this);
			return true;
		}
	}
	return false;
}

} /* namespace LuaCppZ */

