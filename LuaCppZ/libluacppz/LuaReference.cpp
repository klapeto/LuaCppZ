/*
 * LuaReference.cpp
 *
 *  Created on: 16 Μαΐ 2017
 *      Author: klapeto
 */

#include "LuaReference.hpp"
#include "LuaState.hpp"
#include <lua.hpp>

namespace LuaCppZ {

LuaReference::LuaReference(LuaValue::Type type) :
		LuaValue(type), parentState(nullptr), reference(LUA_NOREF) {

}

LuaReference::LuaReference(LuaValue::Type type, LuaState& state, int reference) :
		LuaValue(type), parentState(&state), reference(reference) {
	parentState->addReference(*this);
}

LuaReference::~LuaReference() {
	if (parentState != nullptr) {
		parentState->releaseReference(*this);
	}
}

void LuaReference::pushToLua(LuaState& state) {
	if (&state != nullptr) {
		lua_getref(state.getCState(), reference);
	}
}

} /* namespace LuaCppZ */

