#!/usr/bin/env python

import re 
from urllib.parse import urlparse
from pathlib import Path
from argparse import ArgumentParser

parser = ArgumentParser()
parser.add_argument("--url", type=str, required=True)
parser.add_argument("--ziggy-file", type=Path, required=True )

args = parser.parse_args()

url: str = args.url
ziggy_path: Path = args.ziggy_file

print(f"url = {url!r}")
print(f"ziggy_path = {str(ziggy_path)!r}")

urlobj = urlparse(url)
print(f"urlobj = {urlobj}")

host_url = urlobj._replace(path="", params="", query="", fragment="").geturl()
print(f"host_url = {host_url!r}")

url_path_prefix = urlobj.path.removeprefix("/").removesuffix("/")

print(f"url_path_prefix = {url_path_prefix!r}")

ziggy_text = ziggy_path.read_text('utf-8')

ziggy_text = re.sub(r'\.host_url = "[^"\r\n]*"', f'.host_url = "{host_url}"', ziggy_text)
ziggy_text = re.sub(r'\.url_path_prefix = "[^"\r\n]*"', f'.url_path_prefix = "{url_path_prefix}"', ziggy_text)

ziggy_path.write_text( ziggy_text,'utf-8')