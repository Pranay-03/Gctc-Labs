const fileList = document.getElementById("fileList");

fetch('.')
  .then(response => response.text())
  .then(text => {
    const parser = new DOMParser();
    const html = parser.parseFromString(text, 'text/html');
    const links = html.querySelectorAll('a');

    links.forEach(link => {
      const href = link.href;
      const fileType = href.split('.').pop();
      if (!['html', 'css', 'js'].includes(fileType)) {
        const li = document.createElement('li');
        const a = document.createElement('a');
        a.href = href;
        a.target = "_blank"; // opens the link in a new tab
        a.innerText = href.split('/').filter(s => s !== '').pop(); // removes empty segments and gets the last non-empty segment
        li.appendChild(a);
        fileList.appendChild(li);
      }
    });
  });
