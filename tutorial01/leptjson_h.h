#ifndef LEPTJSON_TEST_LEPTJSON_H_H
#define LEPTJSON_TEST_LEPTJSON_H_H

typedef enum { LEPT_NULL, LEPT_FALSE, LEPT_TRUE, LEPT_NUMBER, LEPT_STRING, LEPT_ARRAY, LEPT_OBJECT } lept_type;

typedef struct {
    lept_type type;
}lept_value;
/*
LEPT_PARSE_OK:

这个结果码表示 JSON 解析成功，没有错误。
在您的代码中，如果 lept_parse 函数成功解析了一个有效的 JSON 值（如 null），它会返回 LEPT_PARSE_OK。例如，在 lept_parse_null 函数中，如果输入字符串正确地匹配了 "null"，函数将设置值类型为 LEPT_NULL 并返回 LEPT_PARSE_OK。
LEPT_PARSE_EXPECT_VALUE:

这个结果码表示在解析 JSON 文本时没有找到期望的值。
在您的代码中，如果输入字符串为空或只包含空白字符（没有任何有效的 JSON 值），lept_parse_value 函数将返回 LEPT_PARSE_EXPECT_VALUE。这表明解析器预期有一个 JSON 值，但实际上并没有找到。*/
/*LEPT_PARSE_INVALID_VALUE:

这个错误码表示解析器遇到了一个无效的值。换句话说，当解析器尝试解析一个字符串，但发现这个字符串不符合任何有效的 JSON 值格式时，它会返回这个错误码。
例如，如果输入字符串是 "nul"（这是 "null" 的错误拼写），或者是一个完全不符合 JSON 格式的字符串（比如 "@123"），解析器就会返回 LEPT_PARSE_INVALID_VALUE。这表示输入的文本不能被识别为任何合法的 JSON 数据类型。*/

enum {
    LEPT_PARSE_OK = 0,
    LEPT_PARSE_EXPECT_VALUE,
    LEPT_PARSE_INVALID_VALUE,
    LEPT_PARSE_ROOT_NOT_SINGULAR

};

int lept_parse(lept_value* v, const char* json);

lept_type lept_get_type(const lept_value* v);

#endif
