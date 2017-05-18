# LuaCppZ

## C++11 Lua Wrapper


Made to simplify the data exchange between Lua and C++.
Currently under development.


Example:
exampleProgram.cpp

```cpp
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
#include "LuaFunction.hpp"
#include "LuaUserData.hpp"

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
					<< "Couldn't get the string field 'Eleos'. Is it really a string in Lua?"
					<< std::endl;
			return 0;
		}
		std::cout << "Table.z.Eleos = " << ret.getValue() << std::endl;

		// Assign a new value to the Table.z.Eleos
		table.setField(LuaString("Eleos"), LuaString("hahahahaaha"));

		// Print the new content
		if (!table.getField(LuaString("Eleos"), ret)) {
			std::cout
					<< "Couldn't get the string field 'Eleos'. Is it really a string in Lua?"
					<< std::endl;
			return 0;
		}
		std::cout << "Table.z.Eleos = " << ret.getValue() << std::endl;

		{

			// Get a lua function from the table
			LuaFunction func;
			table.getField(LuaString("func"), func);

			// Define the argument, and expected return values
			LuaString orisma("Orisma!");
			LuaNumber ret1;
			LuaString ret2, ret3;

			// Call the Lua function
			func( { &orisma }, { &ret1, &ret2, &ret3 });

			// Print the return values
			std::cout << "Ret1 = " << ret1.getValue() << std::endl;
			std::cout << "Ret2 = " << ret2.getValue() << std::endl;
			std::cout << "Ret3 = " << ret3.getValue() << std::endl;

		}

		{

			// Iterate to all fields of the table and execute the Lamda function for each
			table.forEach([](const LuaValue& key, const LuaValue& value) {

				// Check if the value is string
					if (value.getType() == LuaValue::Type::String) {
						std::cout << reinterpret_cast<const LuaString*>(&value)->getValue()<< std::endl;
					}

				});
		}

	}

	return 0;
}
```

```
