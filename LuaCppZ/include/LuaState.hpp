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
 * Foobar is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
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

class LuaState {
public:

	void executeCode(const std::string& code);
	void executeFile(const std::string& filepath);

	void loadLibraries();

	void releaseReference(LuaReference& reference);
	void addReference(LuaReference& reference);

	bool getVariable(const std::string& name, LuaValue& value);

	lua_State* getCState() {
		return lstate;
	}

	LuaState();
	~LuaState();
private:
	std::unordered_set<LuaReference*> references;
	lua_State* lstate;

	void pushValue(const std::string& name);

};

} /* namespace LuaCppZ */

#endif /* LUASTATE_HPP_ */
