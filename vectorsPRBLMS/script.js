const APILINK = '';
const IMG_PATH = '';
const SEARCHAPI = '';

const main = document.getElementById("section");
const form = document.getElementById("form");
const search = document.getElementById("query");

function returnMovies(url) {
    fetch(url)
        .then(res => res.json())
        .then(function (data) {  // <-- The opening curly brace here should be after "function(data)"
            console.log(data.results);
            data.results.forEach(element => {
                const div_card = document.createElement('div');
                div_card.setAttribute('class', 'card');
                const div_row = document.createElement('div');
                div_row.setAttribute('class', 'row');
                const div_column = document.createElement('div');
                div_column.setAttribute('class', 'column');

                const image = document.createElement('img');
                image.setAttribute('class', 'thumbnail');
                image.setAttribute('class', 'image');

                const title = document.createElement('h3');
                title.setAttribute('id', 'title');
                const center = document.createElement('center');

                title.innerHTML = `${element.title}`;
                image.src = IMG_PATH + element.poster_path;
                center.appendChild(image);
                div_card.appendChild(center);
                div_card.appendChild(title);
                div_column.appendChild(div_card);
                div_row.appendChild(div_column);

                main.appendChild(div_row);
            });
        });  // <-- Don't forget to close the outermost curly brace for the "then" block
}
form.addEventListener("submit", (e) => {
    e.preventDefault();
    main.innerHTML = '';

    const searchItem = search.value;
    if (searchItem) {
        returnMovies(SEARCHAPI + searchItem);
        search.value = '';
    }
})
