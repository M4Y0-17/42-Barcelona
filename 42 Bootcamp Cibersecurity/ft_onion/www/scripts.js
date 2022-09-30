
const clave = 'api_key=31ebd5b4de6fc022eb4af253c029ad2f'

const urlBasica = 'https://api.themoviedb.org/3/'

const urlPopularidad = 'discover/movie?sort_by=popularity.desc'

const url = `${urlBasica}${urlPopularidad}&${clave}`

const urlPoster = 'https://image.tmdb.org/t/p/w500'
const urlBuscar = `${urlBasica}search/movie?${clave}`

const contenedor = document.querySelector('.contenedor')
const formulario = document.querySelector('.form')
const buscar = document.querySelector('.buscar')

verPelis(url)
function verPelis(url){
	fetch(url)
	.then(respuesta => respuesta.json())
	.then(datos => {
		console.log(datos.results)
		imprimirPelis(datos.results)
	})
	.catch(error => console.log(error))
}

function imprimirPelis(datos){
	contenedor.innerHTML = ''

	datos.forEach(peli => {
		const {title, poster_path, vote_average, overview} = peli
		const elemPeli = document.createElement('div')
		elemPeli.classList.add('peli')
		elemPeli.innerHTML = `<img src="${urlPoster + poster_path}">
		<div class="infoPeli">
			<h2 class="titulo">${title}</h2>
			<span class="${cambiarColor(vote_average)}">${vote_average}</span>
		</div>

		<div class="resena">
			${overview}
		</div>`

		contenedor.appendChild(elemPeli)
	})
}

function cambiarColor(vote){
	if(vote >= 8){
		return 'ratingVerde'
	}else if(vote >=5){
		return 'ratingNaranja'
	}else
		return 'ratingRojo'
}

formulario.addEventListener('submit', (loquebusco =>{
	loquebusco.preventDefault()
	const busqueda = buscar.value
	if(busqueda){
		verPelis(`${urlBuscar}&query=${busqueda}`)
	}
}))