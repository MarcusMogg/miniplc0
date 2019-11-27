#include "catch2/catch.hpp"
#include "tokenizer/tokenizer.h"
#include "fmt/core.h"

#include <sstream>
#include <vector>

// 下面是示例如何书写测试用例
TEST_CASE("Test hello world.") {

    std::string input =
        "begin\n"
        "	var a = 1;\n";
    /*"	const b = 1\n"
    "	print(a+b);\n"
    "end\n";*/
    std::stringstream ss;
    ss.str(input);
    miniplc0::Tokenizer tkz(ss);
    std::vector<miniplc0::Token> output =
    {
        miniplc0::Token(miniplc0::TokenType::BEGIN,std::string("begin"),0,0,0,5),
        miniplc0::Token(miniplc0::TokenType::VAR,std::string("var"),1,1,1,4),
        miniplc0::Token(miniplc0::TokenType::IDENTIFIER,std::string("a"),1,5,1,6),
        miniplc0::Token(miniplc0::TokenType::EQUAL_SIGN,'=',1,7,1,8),
        miniplc0::Token(miniplc0::TokenType::UNSIGNED_INTEGER,1,1,9,1,10),
        miniplc0::Token(miniplc0::TokenType::SEMICOLON,';',1,10,1,11),
    };
    std::cout << output[0].GetValueString();
    auto result = tkz.AllTokens();
    if (result.second.has_value()) {
        FAIL();
    }
    REQUIRE((result.first == output));
}