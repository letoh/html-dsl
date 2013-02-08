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

#define html(...) _vartag(html, attr(xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en"), __VA_ARGS__)
#define head(...) _vartag(head, "", __VA_ARGS__) 
#define body(...) _vartag(body, "", __VA_ARGS__) 

#define title(s, ...)								\
	_t("title");								\
	printf(s, ## __VA_ARGS__);									\
	_t("/title")

#define meta(...) single(meta, __VA_ARGS__)

#define css(f)									\
	printf("<link rel=\"stylesheet\" type=\"text/css\" href=\"%s\" />\n", f)

//#define script(f)													\
//	printf("<script type=\"text/javascript\" src=\"%s\" />\n", f)
#define script(f)								\
	printf("<script type=\"text/javascript\" src=\"%s\"></script>\n", f)

#define echo(r, ...) printf(r, ## __VA_ARGS__)
#define raw(r) echo(#r)
#define js(...)									\
	raw(<script type="text/javascript">);		\
	raw(__VA_ARGS__);								\
	raw(</script>)

#define attr xstr

#define h1(...) _vartag(h1, "", __VA_ARGS__) 
#define h2(...) _vartag(h2, "", __VA_ARGS__) 
#define h3(...) _vartag(h3, "", __VA_ARGS__) 
#define h4(...) _vartag(h4, "", __VA_ARGS__) 

#define img(f, ...)								\
	printf("<img src=\"%s\" %s />\n", f, # __VA_ARGS__) \

#define br printf("<br />\n")

#define div(a, ...)   _vartag(div, attr(a), __VA_ARGS__)
#define span(a, ...)  _vartag(span, attr(a), __VA_ARGS__)
#define center(...) _vartag(center, "", __VA_ARGS__)

/* table */
#define table(a, ...) _vartag(table, attr(a), ## __VA_ARGS__)
#define th(...) _vartag(th, "", ## __VA_ARGS__)
#define tr(...) _vartag(tr, "", ## __VA_ARGS__)
#define td(...) _vartag(td, "", ## __VA_ARGS__)

/** form
 *
 * form(GET, "/abc", "", ""
 *     [, <form input elements>]
 *     );
 *
 */
#define form(m, s, n, a, ...)											\
	_vartag(form, attr(method=#m action=s name=n id=n a), ## __VA_ARGS__)

#define button(t, ...) _vartag(button, attr(__VA_ARGS__), echo(t))
#define label(t, ...)  _vartag(label, attr(__VA_ARGS__), echo(t))
#define input(...)     single(input, __VA_ARGS__)
#define submit(...)    input(type="submit" __VA_ARGS__)
#define text(n, ...)  input(type="text" name=n id=n __VA_ARGS__)
#define pass(n, ...)      input(type="password" name=n id=n __VA_ARGS__)
#define img2(s, ...)      input(type="image" src=s __VA_ARGS__)
#define hidden(n, v, ...)  input(type="hidden" name=n id=n value=v __VA_ARGS__)
#define radio(l, g, v, ...) label(l), input(type="radio" name=g value=v __VA_ARGS__)
#define check(l, g, v, ...) label(l), input(type="checkbox" name=g value=v __VA_ARGS__)

#define hr(...) single(hr, __VA_ARGS__)
#define url(t, src, ...)  _vartag(a, attr(href=src __VA_ARGS__), echo(t))

#endif /* _HTML_H_ */
