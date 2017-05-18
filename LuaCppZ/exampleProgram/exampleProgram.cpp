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
