/*******************************************************************************
 * Copyright (c) 2017 Ioannis Panagiotopoulos
 *
 * This file is part of Foobar.
 *
 * Foobar is free software: you can redistribute it and/or modify
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
 *******************************************************************************/

/*
 * LuaTable.cpp
 *
 *  Created on: 16 Μαΐ 2017
 *      Author: klapeto
 */

#include <lua.hpp>
#include <LuaBoolean.hpp>
#include <LuaFunction.hpp>
#include <LuaLightUserData.hpp>
#include <LuaNumber.hpp>
#include <LuaState.hpp>
#include <LuaString.hpp>
#include <LuaTable.hpp>
#include <LuaUserData.hpp>
#include <LuaValue.hpp>

#define saveStackPointer(lstate) int sp = lua_gettop(lstate)
#define restoreStackPointer(lstate) lua_settop(lstate, sp)

namespace LuaCppZ {

struct TableKey {
	LuaString str;
	LuaUserData<void> ud;
	LuaTable table;
	LuaFunction func;
	LuaLightUserData<void> lud;
	LuaNumber num;
	LuaBoolean bl;
	LuaValue* key;
};

LuaTable::LuaTable() :
		LuaReference(LuaValue::Type::Table) {

}
LuaTable::~LuaTable() {

}

bool LuaTable::getField(const LuaValue& key, LuaValue& value) {
	if (parentState != nullptr) {
		saveStackPointer(parentState->getCState());
		pushToLua(*parentState);
		key.pushToLua(*parentState);
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
		key.pushToLua(*parentState);
		value.pushToLua(*parentState);
		lua_settable(lstate, -3);
		restoreStackPointer(lstate);
	}
}

bool LuaTable::assignFromStack(LuaState& state, int stackPointer) {
	if (parentState != nullptr) {
		parentState->releaseReference(*this);
	}
	if (&state != nullptr) {

		if (lua_istable(state.getCState(), stackPointer)) {
			setReference(state, stackPointer);
			return true;
		}
	}
	return false;
}

void LuaTable::forEach(
		const std::function<void(const LuaValue&, const LuaValue&)>& func) const {

	if (parentState != nullptr) {

		lua_State* lstate = parentState->getCState();

		saveStackPointer(lstate);

		pushToLua(*parentState);

		lua_pushnil(lstate);

		while (lua_next(lstate, -2)) {

			int secondStageSP = lua_gettop(lstate);

			lua_pushvalue(lstate, -2);

			TableKey keys;

			switch (lua_type(lstate, -1)) {
			case LUA_TSTRING:
				keys.str.assignFromStack(*parentState, -1);
				keys.key = &keys.str;
				break;
			case LUA_TNUMBER:
				keys.num.assignFromStack(*parentState, -1);
				keys.key = &keys.num;
				break;
			case LUA_TBOOLEAN:
				keys.bl.assignFromStack(*parentState, -1);
				keys.key = &keys.bl;
				break;
			case LUA_TTABLE:
				keys.table.assignFromStack(*parentState, -1);
				keys.key = &keys.table;
				break;
			case LUA_TFUNCTION:
				keys.func.assignFromStack(*parentState, -1);
				keys.key = &keys.func;
				break;
			case LUA_TLIGHTUSERDATA:
				keys.lud.assignFromStack(*parentState, -1);
				keys.key = &keys.lud;
				break;
			case LUA_TUSERDATA:
				keys.ud.assignFromStack(*parentState, -1);
				keys.key = &keys.ud;
				break;
			default:
				// TODO: if it is Thread?
				keys.str = lua_tolstring(lstate, -1, nullptr);
				keys.key = &keys.str;
				break;
			}

			switch (lua_type(lstate, -2)) {
			case LUA_TSTRING:
				func(*keys.key, LuaString(lua_tolstring(lstate, -2, nullptr)));
				break;
			case LUA_TNUMBER:
				func(*keys.key, LuaNumber(lua_tonumber(lstate, -2)));
				break;
			case LUA_TBOOLEAN:
				func(*keys.key, LuaBoolean(lua_toboolean(lstate, -2)));
				break;
			case LUA_TTABLE: {
				LuaTable val;
				val.assignFromStack(*parentState, -2);
				func(*keys.key, val);
			}
				break;
			case LUA_TFUNCTION: {
				LuaFunction val;
				val.assignFromStack(*parentState, -2);
				func(*keys.key, val);
			}
				break;
			case LUA_TLIGHTUSERDATA:
				func(*keys.key,
						LuaLightUserData<void>(lua_touserdata(lstate, -2)));
				break;
			case LUA_TUSERDATA: {
				LuaUserData<void> val;
				val.assignFromStack(*parentState, -2);
				func(*keys.key, val);
			}
				break;
			default:
				// TODO: if it is Thread?
				break;
			}

			lua_settop(lstate, secondStageSP);
		}

		restoreStackPointer(lstate);

	}

}

} /* namespace LuaCppZ */
