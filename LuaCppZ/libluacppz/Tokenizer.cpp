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
 * Tokenizer.cpp
 *
 *  Created on: 16 Μαΐ 2017
 *      Author: klapeto
 */

#include "Tokenizer.hpp"
#include <cstddef>

namespace LuaCppZ {

void Tokenizer::parse(std::list<std::string>& list, const std::string& str,
		char delimiter) {

	size_t lastDelimiterIndex = 0;
	size_t index = 0;

	list.clear();

	while (str[index] != '\0') {

		if (str[index] == delimiter) {

			list.push_back(
					std::move(
							str.substr(lastDelimiterIndex,
									index - lastDelimiterIndex)));
			lastDelimiterIndex = index + 1;
		}
		++index;
	}

	// Add the last token to the list
	list.push_back(std::move(str.substr(lastDelimiterIndex)));

}

} /* namespace LuaCppZ */
