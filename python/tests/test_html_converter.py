import io

from html_converter import HtmlConverter


def test_convert():
    fake_file = io.StringIO("""foobar\n '' \n " """)
    converter = HtmlConverter()
    result = converter.convert_text_stream(fake_file)
    assert result == "<html><p>foobar<p/><p> &#x27;&#x27;<p/><p> &quot;<p/></html>"
