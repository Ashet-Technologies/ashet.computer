

serve:
    .venv/bin/mkdocs serve

build:
    .venv/bin/mkdocs build \
        --site-dir ./render \
        --strict

venv:
    python -m venv .venv
    .venv/bin/pip install -r requirements.txt
