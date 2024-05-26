



window.addEventListener('DOMContentLoaded', () => {
  initializeGalleries();
});

let gallery_globals

function openGallery(gallery, index) {
  gallery_globals.panel.style.display = 'block';
  gallery_globals.close.onclick = () => {
    gallery_globals.video.pause();
    gallery_globals.video.src = '';
    gallery_globals.img.src = '';
    gallery_globals.panel.style.display = 'none';
  };

  let current = gallery.items[index];
  gallery_globals.title.innerText = current.title;

  gallery_globals.prev.style.display = (index > 0) ? 'block' : 'none';
  gallery_globals.next.style.display =
      (index < gallery.items.length - 1) ? 'block' : 'none';

  gallery_globals.prev.onclick = () => {
    openGallery(gallery, index - 1);
  };
  gallery_globals.next.onclick = () => {
    openGallery(gallery, index + 1);
  };

  gallery_globals.video.src = '';
  gallery_globals.img.src = '';

  if (current.full_href.endsWith('.mp4')) {
    gallery_globals.video.src = current.full_href;
    gallery_globals.video.style.display = 'block';
    gallery_globals.img.style.display = 'none';

    gallery_globals.video.play();
  } else {
    gallery_globals.img.src = current.full_href;
    gallery_globals.video.style.display = 'none';
    gallery_globals.img.style.display = 'block';
  }
}

function initializeGalleries() {
  gallery_globals = {
    panel: document.getElementById('gallery-core-panel'),
    img: document.getElementById('gallery-core-img'),
    video: document.getElementById('gallery-core-video'),
    prev: document.getElementById('gallery-core-prev'),
    next: document.getElementById('gallery-core-next'),
    title: document.getElementById('gallery-core-title'),
    close: document.getElementById('gallery-core-close'),
  };

  let gallery_nodes = Array.from(document.querySelectorAll('ashet-gallery'));
  for (let gallery_node of gallery_nodes) {
    let gallery = {
      root: gallery_node,
      items: [],
    };

    let item_nodes =
        Array.from(gallery_node.querySelectorAll('ashet-gallery-item'));

    for (let item_index = 0; item_index < item_nodes.length; item_index++) {
      let item_node = item_nodes[item_index];
      let item = {
        node: item_node,
        title: undefined,
        thumb_href: undefined,
        full_href: undefined,
      };

      item.link_node = item_node.querySelector('a[href]');
      item.thumb_node = item_node.querySelector('img[src]');
      item.title_node = item_node.querySelector('span');

      item.full_href = item.link_node.href;
      item.thumb_href = item.thumb_node.src;
      item.title = item.title_node.innerText;

      item.link_node.href = 'javascript:void(0)';
      item.link_node.removeAttribute('target');
      item.link_node.addEventListener('click', () => {
        openGallery(gallery, item_index);
      });

      gallery.items.push(item);
    }

    console.log(gallery);
  }
}
