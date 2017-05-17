# LuaCppZ

## C++11 Lua Wrapper


Made to simplify the data exchange between Lua and C++.
Currently under development.


Example:
exampleProgram.cpp

```cpp
#include "LuaState.hpp"
#include "LuaTable.hpp"
#include "LuaNumber.hpp"
#include "LuaString.hpp"

#include <iostream>

using namespace LuaCppZ;

int main(int argC, char** argV) {

	// Create a Lua State
	LuaState lua;

	// Load the standard libraries
	lua.loadLibraries();

	// execute a local file
	lua.executeFile("exampleProgram/script.lua");

	{

		// Retrieve the Lua table Table.z
		LuaTable table;

		if (!lua.getVariable("Table.z", table)) {
			std::cout << "Could get table 'Table.z'" << std::endl;
			return 0;
		}

		// Retrieve the Field 'Eleos' from the table we have
		LuaString ret;

		if (!table.getField(LuaString("Eleos"), ret)) {
			std::cout
					<< "Could get the string field 'Eleos'. Is it really a string in Lua?"
					<< std::endl;
			return 0;
		}
		std::cout << "Table.z.Eleos = " << ret.getValue() << std::endl;

		// Assign a new value to the Table.z.Eleos
		table.setField(LuaString("Eleos"), LuaString("hahahahaaha"));

		// Print the new content
		if (!table.getField(LuaString("Eleos"), ret)) {
			std::cout
					<< "Could get the string field 'Eleos'. Is it really a string in Lua?"
					<< std::endl;
			return 0;
		}
		std::cout << "Table.z.Eleos = " << ret.getValue() << std::endl;

	}

	return 0;
}
```
