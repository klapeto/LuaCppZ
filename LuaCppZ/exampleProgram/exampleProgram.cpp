/*
 ============================================================================
 Name        : exampleProgram.c
 Author      : klapeto
 Version     :
 Copyright   : Ioannis Panagiotopoulos
 Description : Uses shared library to print greeting
 To run the resulting executable the LD_LIBRARY_PATH must be
 set to ${project_loc}/libluacppz/.libs
 Alternatively, libtool creates a wrapper shell script in the
 build directory of this program which can be used to run it.
 Here the script will be called exampleProgram.
 ============================================================================
 */

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
