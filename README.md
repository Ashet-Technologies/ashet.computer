# ashet.computer Website

This repository hosts the website at <https://ashet.computer>.

## Building

### Requirements

- Python > 3.11

### Build Steps

```sh-session
[user@host ashet.computer]$ python -m venv .venv
[user@host ashet.computer]$ . .venv/bin/activate
(.venv) [user@host ashet.computer]$ pip install -r requirements.txt
Collecting mkdocs (from -r requirements.txt (line 1))
  Downloading mkdocs-1.6.1-py3-none-any.whl.metadata (6.0 kB)
…
Installing collected packages: …, mkdocs
Successfully installed … mkdocs-1.6.1 …
(.venv) [user@host ashet.computer]$ mkdocs serve
INFO    -  Building documentation...
INFO    -  Cleaning site directory
INFO    -  Documentation built in 0.03 seconds
INFO    -  [19:38:24] Watching paths for changes: 'docs', 'mkdocs.yml'
INFO    -  [19:38:24] Serving on http://127.0.0.1:8000/
```
