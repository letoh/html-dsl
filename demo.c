#include <stdio.h>

#include "html.h"

int main(int argc, char *argv[])
{
	html(
		head(
			title("Site Title"),
			script("http://test.com/test.js"),
			css("css/test.css"),
			js(
<script type="text/javascript">
function foo()
{
	alert("abc");
}
</script>
				)),
		body(
			img(banner.jpg, id="banner"),
			img(line.jpg),
			h1(raw(chapter 1)),
			raw(
<form method="post" action="test.cgi">
	<input type="submit" value="go">
</form>
				)
			));

	return 0;
}

