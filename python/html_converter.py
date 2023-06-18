import html


class HtmlConverter:

    def convert_to_html(self, filename):
        with open(filename, "r") as f:
            return self.convert_text_stream(f)

    def convert_text_stream(self, f):
        # bug: should be "<html>"
        html = "<html<"
        for line in f:
            html += "<p>"
            line = line.rstrip()
            html += self.escape(line, quote=True)
            # bug: should be "</p>"
            html += "<br />"
        html += "</html>"
        return html

    def escape(self, line, quote):
        return html.escape(line, quote=quote)
