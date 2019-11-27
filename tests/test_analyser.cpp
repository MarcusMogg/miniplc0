#include "catch2/catch.hpp"

#include "instruction/instruction.h"
#include "tokenizer/tokenizer.h"
#include "analyser/analyser.h"
#include <sstream>

/*
	不要忘记写测试用例喔。
*/
TEST_CASE("nmd") {

    std::string input =
        "begin     \n"
        "var a = 1;\n"
        "var b;    \n"
        "var c;    \n"
        "var d;    \n"
        "var e;    \n"
        "b = a;    \n"
        "e = b;    \n"
        "d = e;    \n"
        "c = a;    \n"
        "print(c); \n"
        "end       \n";

    std::stringstream ss;
    ss.str(input);
    miniplc0::Tokenizer tkz(ss);
    auto result = tkz.AllTokens();
    miniplc0::Analyser a(result.first);
    a.Analyse();
    if (result.second.has_value()) {
        FAIL();
    }
}