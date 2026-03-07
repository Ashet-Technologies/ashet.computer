



assets:
    kicad-cli sch export svg --drawing-sheet --exclude-drawing-sheet --no-background-color --output assets/img/docs/ assets-src/design-drawings/backplane.kicad_sch 
    kicad-cli sch export svg --drawing-sheet --exclude-drawing-sheet --no-background-color --output assets/img/docs/ assets-src/design-drawings/architecture.kicad_sch 
    kicad-cli sch export svg --drawing-sheet --exclude-drawing-sheet --no-background-color --output assets/img/docs/ assets-src/design-drawings/mainboard.kicad_sch 
    kicad-cli sch export svg --drawing-sheet --exclude-drawing-sheet --no-background-color --output assets/img/docs/ assets-src/design-drawings/expansion.kicad_sch 
    
    svgo --multipass --recursive assets/img/docs/

[working-directory: 'content/gallery/img']
thumbnails:
    for file in *.jpg *.png; do \
        magick convert -resize 300x "$file" "${file%.*}.webp"; \
    done

[working-directory: 'assets-src']
devlog-images:
    for file in $(find -name "*.jpg" -or -name "*.png"); do \
        mkdir -p "../content/${file%/*}" ; \
        echo "processing ${file}..." ; \
        magick "${file}" -resize "720x720>" "../assets/${file%.*}.webp"; \
    done

[working-directory: 'assets-src']
devlog-videos:
    for file in $(find -name "*.mp4"); do \
        mkdir -p "../content/${file%/*}" ; \
        echo "processing ${file}..." ; \
        ffmpeg -i "${file}" -vf "scale='min(720,iw)':'min(720,ih)':force_original_aspect_ratio=decrease" -c:v libvpx-vp9 -b:v 0 -crf 32 -c:a libopus "../assets/${file%.*}.webm"; \
    done
