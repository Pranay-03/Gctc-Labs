const fileList = document.getElementById("fileList");

fetch('.')
  .then(response => response.text())
  .then(text => {
    const parser = new DOMParser();
    const html = parser.parseFromString(text, 'text/html');
    const links = html.querySelectorAll('a');

    links.forEach(link => {
      if (! link.href.endsWith('.html') || ! link.href.endsWith('.css') || ! link.href.endsWith('.js')) {
        const li = document.createElement('li');
        const a = document.createElement('a');
        a.href = link.href;
        a.innerText = link.href.split('/').pop();
        li.appendChild(a);
        fileList.appendChild(li);
      }
    });
  });
