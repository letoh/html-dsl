#ifndef _HTML_H_
#define _HTML_H_

#define _t(tag)	printf("<" tag ">\n")

#define _vartag(t, ...)						\
	_t(#t);									\
	__VA_ARGS__;							\
	_t("/" #t)

#define html(...) _vartag(html, __VA_ARGS__) 
#define head(...) _vartag(head, __VA_ARGS__) 
#define body(...) _vartag(body, __VA_ARGS__) 

#define title(s)								\
	_t("title");								\
	printf(s);									\
	_t("/title")

#define meta(...)								\
	printf("<meta %s>\n", ##__VA_ARGS__)

#define css(f)									\
	printf("<link rel=\"stylesheet\" type=\"text/css\" href=\"%s\" />\n", f)

#define script(f)									\
	printf("<script type=\"text/javascript\" src=\"%s\" />\n", f)

#define raw(r) printf(#r)
#define js(r)  raw(r)

#define h1(...) _vartag(h1, __VA_ARGS__) 
#define h2(...) _vartag(h2, __VA_ARGS__) 
#define h3(...) _vartag(h3, __VA_ARGS__) 
#define h4(...) _vartag(h4, __VA_ARGS__) 

#define div(...)   _vartag(div, __VA_ARGS__)
#define span(...)  _vartag(span, __VA_ARGS__)
#define table(...) _vartag(table, __VA_ARGS__)
#define form(...)  _vartag(form, __VA_ARGS__)

#define img(f, ...)								\
	printf("<img src=\"%s\" %s />\n", #f, # __VA_ARGS__) \

#endif /* _HTML_H_ */
