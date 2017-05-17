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
