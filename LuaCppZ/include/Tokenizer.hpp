/*
 * Tokenizer.hpp
 *
 *  Created on: 16 Μαΐ 2017
 *      Author: klapeto
 */

#ifndef TOKENIZER_HPP_
#define TOKENIZER_HPP_

#include <list>
#include <string>

namespace LuaCppZ {

class Tokenizer {
public:
	static void parse(std::list<std::string>& list, const std::string& str,
			char delimiter);
};

} /* namespace LuaCppZ */

#endif /* TOKENIZER_HPP_ */
