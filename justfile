



assets:
    kicad-cli sch export svg --drawing-sheet --exclude-drawing-sheet --no-background-color --output assets/img/docs/ assets-src/design-drawings/backplane.kicad_sch 
    kicad-cli sch export svg --drawing-sheet --exclude-drawing-sheet --no-background-color --output assets/img/docs/ assets-src/design-drawings/architecture.kicad_sch 
    kicad-cli sch export svg --drawing-sheet --exclude-drawing-sheet --no-background-color --output assets/img/docs/ assets-src/design-drawings/mainboard.kicad_sch 
    kicad-cli sch export svg --drawing-sheet --exclude-drawing-sheet --no-background-color --output assets/img/docs/ assets-src/design-drawings/expansion.kicad_sch 
    
    svgo --multipass --recursive assets/img/docs/

[working-directory: 'content/gallery/img']
thumbnails:
    for file in *.jpg *.png; do \
        magick convert -resize 300x $file ${file%%.*}.webp; \
    done
