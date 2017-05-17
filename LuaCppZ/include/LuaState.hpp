/*
 * LuaState.hpp
 *
 *  Created on: 14 Μαΐ 2017
 *      Author: klapeto
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
