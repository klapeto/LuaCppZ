/*
 * Tokenizer.hpp
 *
 *  Created on: 16 Μαΐ 2017
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

#ifndef TOKENIZER_HPP_
#define TOKENIZER_HPP_

#include <list>
#include <string>

namespace LuaCppZ {

/**
 * Helper class for providing string operations
 */
class Tokenizer {
public:

	/**
	 * Parses the str to break it into tokens
	 * @param list the std::list<std::string> to put the tokens
	 * @param str The string to be parsed
	 * @param delimiter The character that seperates the tokens inside the str
	 */
	static void parse(std::list<std::string>& list, const std::string& str,
			char delimiter);
};

} /* namespace LuaCppZ */

#endif /* TOKENIZER_HPP_ */
