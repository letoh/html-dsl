#ifndef _HTML_H_
#define _HTML_H_

#define _t(tag)									\
	printf("<" tag ">\n")

#define html(...)							\
	_t("html");								\
	__VA_ARGS__;							\
	_t("/html")

#define head(...)								\
	_t("head");									\
	__VA_ARGS__;								\
	_t("/head")

#define title(s)								\
	_t("title");								\
	printf(s);									\
	_t("/title")

#define css(f)									\
	printf("<link rel=\"stylesheet\" type=\"text/css\" href=\"%s\" />\n", f)

#define script(f)									\
	printf("<script type=\"text/javascript\" src=\"%s\" />\n", f)

#define body(...)								\
	_t("body");									\
	__VA_ARGS__;								\
	_t("/body")

#define raw(r)									\
	printf(#r)

#define js(r)									\
	raw(r)

#define h1(s)									\
	_t("h1");									\
	printf(s);									\
	_t("/h1")

#define img(f, ...)								\
	printf("<img src=\"%s\" %s />\n", #f, # __VA_ARGS__) \

#endif /* _HTML_H_ */
