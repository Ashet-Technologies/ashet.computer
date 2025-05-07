
serve:
    .venv/bin/mkdocs serve

serve-public:
    .venv/bin/mkdocs serve -a 0.0.0.0:8080

build: assets
    .venv/bin/mkdocs build \
        --site-dir ./render \
        --strict

assets: \
    (render-drawio-to-svg "assets/block_diagrams/architecture.drawio" "docs/assets/architecture.svg") \
    (render-drawio-to-svg "assets/block_diagrams/backplane.drawio" "docs/assets/backplane.svg") \
    (render-drawio-to-svg "assets/block_diagrams/expansion.drawio" "docs/assets/expansion.svg") \
    (render-drawio-to-svg "assets/block_diagrams/mainboard.drawio" "docs/assets/mainboard.svg")
    

render-drawio-to-svg input output:
    .bin/drawio-x86_64-26.0.9.AppImage --export --format svg --border 10 --svg-theme light --output {{output}} {{input}}


venv:
    python -m venv .venv
    .venv/bin/pip install -r requirements.txt

install-drawio:
    mkdir -p .bin
    curl -L -o .bin/drawio-x86_64-26.0.9.AppImage https://github.com/jgraph/drawio-desktop/releases/download/v26.0.9/drawio-x86_64-26.0.9.AppImage
    echo '98cb793925fced59ae6b8d3290060f683455bd89e50e18c5d4da1ce7a2b3354c  .bin/drawio-x86_64-26.0.9.AppImage' | sha256sum --check
    chmod +x .bin/drawio-x86_64-26.0.9.AppImage
