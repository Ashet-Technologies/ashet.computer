



assets:
    kicad-cli sch export svg --drawing-sheet --exclude-drawing-sheet --no-background-color --output assets/img/docs/ assets-src/design-drawings/backplane.kicad_sch 
    kicad-cli sch export svg --drawing-sheet --exclude-drawing-sheet --no-background-color --output assets/img/docs/ assets-src/design-drawings/architecture.kicad_sch 
    kicad-cli sch export svg --drawing-sheet --exclude-drawing-sheet --no-background-color --output assets/img/docs/ assets-src/design-drawings/mainboard.kicad_sch 
    kicad-cli sch export svg --drawing-sheet --exclude-drawing-sheet --no-background-color --output assets/img/docs/ assets-src/design-drawings/expansion.kicad_sch 