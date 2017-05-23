/*
 * LuaState.hpp
 *
 *  Created on: 14 Μαΐ 2017
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

#ifndef LUASTATE_HPP_
#define LUASTATE_HPP_

#include <lua.hpp>
#include <string>
#include <unordered_set>

namespace LuaCppZ {

class LuaValue;
class LuaTable;
class LuaReference;

/**
 * The basic object of the Lua Environment
 */
class LuaState {
public:


	/**
	 * Executes the Lua code from the string provided
	 * @param code The string that contains the Lua code to be exectuted
	 */
	void executeCode(const std::string& code);

	/**
	 * Executes the Lua code from the file in filepath provided
	 * @param filepath The full filepath of the file to execute
	 */
	void executeFile(const std::string& filepath);

	/**
	 * Loads all the standard Lua Libraries in the Lua Environment
	 */
	void loadLibraries();

	/**
	 * Releases a LuaReference object from this LuaState
	 * It invalidates the LuaReference object, meaning that you
	 * cannot use it unless it is assigned a new reference.
	 * @param reference The LuaReference to release
	 */
	void releaseReference(LuaReference& reference);

	/**
	 * Adds this LuaReference object to this State
	 * Unless you really know what you do, don't bother with is function
	 * @param reference The LuaReference to add
	 */
	void addReference(LuaReference& reference);

	/**
	 * Tries to assign the named Lua variable to the value provided
	 * The name can be a period separated value for instance:
	 * "table.table2.value"
	 * will try to retrieve the 'value' from 'table2' which is a
	 * member of 'table'. If the 'value' type does not match the type
	 * of the 'value' object provided in this function, then assignment
	 * will fail and the function will return false.
	 *
	 * @param name The named Lua value
	 * @param value The object to assign the value to
	 * @return true if the assignment was a success, otherwise false
	 */
	bool getVariable(const std::string& name, LuaValue& value);

	/**
	 * Gets the amount of memory used by lua environment in KB
	 * @return The amount of memory in KB
	 */
	int getMemoryUsed() const;

	/**
	 * Causes the Lua garbage collector to stop
	 */
	void stopGarbageCollection();

	/**
	 * Restarts the Lua garbage collector to restart
	 */
	void startGarbageCollection();

	/**
	 * Performs garbage collection cycle in the Lua environment
	 */
	void performGarbageCollection();


	/**
	 * Gets the C Lua state
	 * @return The C lua state Object
	 */
	lua_State* getCState() {
		return lstate;
	}

	/**
	 * Constructs a Lua State
	 */
	LuaState();

	~LuaState();
private:
	std::unordered_set<LuaReference*> references;
	lua_State* lstate;

	void pushValue(const std::string& name);

};

} /* namespace LuaCppZ */

#endif /* LUASTATE_HPP_ */
