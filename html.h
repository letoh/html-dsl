#ifndef _HTML_H_
#define _HTML_H_

#define _t(tag)	printf("<" tag ">\n")

#define xstr(s)  #s

#define single(tag, ...)						\
	printf("<" xstr(tag) " " xstr(__VA_ARGS__) " />\n")

#define _vartag(t, a, ...) \
	printf("<" xstr(t) " " a " >\n");	\
	__VA_ARGS__;						\
	_t("/" xstr(t))

#define html(...) _vartag(html, "", __VA_ARGS__) 
#define head(...) _vartag(head, "", __VA_ARGS__) 
#define body(...) _vartag(body, "", __VA_ARGS__) 

#define title(s)								\
	_t("title");								\
	printf(s);									\
	_t("/title")

#define meta(...) single(meta, __VA_ARGS__)

#define css(f)									\
	printf("<link rel=\"stylesheet\" type=\"text/css\" href=\"%s\" />\n", f)

//#define script(f)													\
//	printf("<script type=\"text/javascript\" src=\"%s\" />\n", f)
#define script(f)								\
	printf("<script type=\"text/javascript\" src=\"%s\"></script>\n", f)

#define echo(r) printf(r)
#define raw(r) echo(#r)
#define js(r)  raw(r)

#define attr xstr

#define h1(...) _vartag(h1, "", __VA_ARGS__) 
#define h2(...) _vartag(h2, "", __VA_ARGS__) 
#define h3(...) _vartag(h3, "", __VA_ARGS__) 
#define h4(...) _vartag(h4, "", __VA_ARGS__) 

#define img(f, ...)								\
	printf("<img src=\"%s\" %s />\n", #f, # __VA_ARGS__) \

#define br printf("<br />\n")

#define div(a, ...)   _vartag(div, attr(a), __VA_ARGS__)
#define span(a, ...)  _vartag(span, a, ## __VA_ARGS__)
#define center(...) _vartag(center, "", __VA_ARGS__)

/* table */
#define table(a, ...) _vartag(table, attr(a), ## __VA_ARGS__)
#define tr(...) _vartag(tr, "", ## __VA_ARGS__)
#define td(...) _vartag(td, "", ## __VA_ARGS__)

/* form */
#define form(m, s, a, ...) \
	_vartag(form, "method=\"" xstr(m) "\" action=\"" s "\" "  attr(a), ## __VA_ARGS__)

#define button(t, ...) _vartag(button, __VA_ARGS__, echo(t))
//#define label(t, a, ...)  _vartag(label, a, echo(t), ## __VA_ARGS__)
#define label(t, ...)  _vartag(label, attr(__VA_ARGS__), echo(t))
#define input(...)     single(input, __VA_ARGS__)
#define submit(...)    input(type="submit" __VA_ARGS__)
#define text(...)      input(type="text" __VA_ARGS__)
#define hidden(n, v)   printf("<input type=\"hidden\" name=\"%s\" value=\"%s\" />\n", xstr(n), xstr(v))
/* TODO */
#define radio(...) input(type="radio" __VA_ARGS__)
#define check(...) input(type="checkbox" __VA_ARGS__)


#endif /* _HTML_H_ */
