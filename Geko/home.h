String home_html_page() {
  return R"==(
<html>

<head>
	<title>Smart Terrarium</title>
	<meta http-equiv="content-type" content="text/html;charset=UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<meta http-equiv="refresh" content="30"> <!-- refresh automatico della pagina ogni 30 secondi -->
	<link rel="preconnect" href="https://fonts.gstatic.com">
	<link href="https://fonts.googleapis.com/css2?family=Imbue:wght@350&family=Literata:ital,wght@1,500&display=swap"
		rel="stylesheet">
	<link rel="shortcut icon" href="https://raw.githubusercontent.com/david-inf/terrarium/main/icona.ico" />
	<style>
		* {
			font-family: 'Literata', serif;
		}

		html {
			margin: 0px;
			padding: 0px;
		}

		body {
			margin: 0px;
			padding: 0px;
			height: 100%;
			background-image: url('https://raw.githubusercontent.com/david-inf/terrarium/main/sfondo.jpg');
			background-attachment: fixed;
			background-repeat: no-repeat;
			background-position: center;
			background-size: cover;
		}

		h1 {
			font-family: 'Julius says one', sans-serif;
			text-align: center;
			letter-spacing: 6px;
			font-size: 70px;
			color: #ffffff;
			padding: 30px;

		}

		h2 {
			font-family: 'Julius says one', sans-serif;
			text-align: center;
			letter-spacing: 1px;
			font-size: 50px;
			color: #0A3409;

		}

		p {
			font-family: 'Verdana', sans-serif;
			color: #0A3409;
			text-align: center;
		}

		h5 {
			text-align: center;
			color: #ffffff;
			padding: -10px;
		}

		header {
			background-color: #0a3409;
			height: 140px;

		}

		footer {
			background-color: #0a3409;
			position: fixed;
			width: 100%;
			height: 60px;
			bottom: 0;
			font-family: 'Poppins', sans-serif;
		}

		section {
			margin-right: 0px;
			padding-right: 0px;
		}

		#logo {
			float: left;
			margin-left: -10px;
			height: 200px;
			margin-top: -1.5%;
		}

		#logo2 {
			float: right;
			margin-right: -10px;
			height: 200px;
			margin-top: -1.5%;
		}

		nav {
			margin-right: 0px;
			padding-right: 0px;
		}

		ul {
			list-style-type: none;
			margin: 0;
			padding: 0;
			overflow: hidden;
			position: absolute;
			top: 130px;
			width: 100%;
		}

		li {
			background-color: #90e70d;
			float: left;
			width: 25%;
		}

		li a {
			display: block;
			color: #000000;
			text-align: center;
			font-family: 'Poppins', sans-serif;
			font-size: 20px;
			padding: 15px 15px;
			text-decoration: none;
		}

		li a:hover:not(.active) {

			color: #ffffff;
		}

		.active {
			background-color: #90e70d;
			border-radius: 0px 0px 0px 0px;
			border: solid 1.5px #0A3409;

		}


		section {
			position: section;
		}

		article {
			width: 50%;
			position: absolute;
			top: 250px;
			margin-left: 100px;
			padding: 10px;
			background-color: #e5ff0032;
			border: solid 3px #1a4104;

		}

		h3 {
			font-family: 'Lato', sans-serif;
			color: #000000;
			font-size: 15px;
			margin: 0px;
			padding: 0px;
		}

		#gecko {
            float: right;
            margin-top: 100px;
            margin-right: 30px;
            width: 350px;
            height: 450px;
			border: solid 5px #1a4104;

        }
	</style>

<body>


	<header>

		<img id="logo" src="https://raw.githubusercontent.com/david-inf/terrarium/main/logo1.png">
		<img id="logo2" src="https://raw.githubusercontent.com/david-inf/terrarium/main/logo1.png">
		<h1> Smart Terrarium </h1>
	</header>

	<section>
		<aside>
			<img id="gecko" src="https://raw.githubusercontent.com/david-inf/terrarium/main/home3_1.jpg">
			
		</aside>
		<nav>
			<ul>
				<li><a class="active" href="home.html">Home</a></li>
				<li><a href="internal_conditions.html">Internal Conditions</a></li>
				<li><a href="changes.html">Modify Thresholdes</a></li>
				<li><a href="summary.html">Summary</a></li>
			</ul>
		</nav>
		<article>
			<h2>Introduction</h2>
			<p> The following website allows to monitor and potentially modify the parameters related to the internal
				condition of a
				terrarium containing a gecko.
				<br><br>
				Geckos are usually small to medium sized lizards that are native to the warmer parts of the world. There
				are over 1,600 different species of geckos but not all of them are commonly kept as pets. However
				because of
				their small size and long lifespan, geckos have become very popular pets.
				<br><br>
				Having the right internal conditions is extremely important in order to keep your gecko healthy and
				relaxed.
				The ideal temperature range for most geckos is between 23°C and 29°C during the day and between 18°C and
				25°C during the night.
				Humidity in a gecko's cage should be kept between 30 and 50 percent.
				Also brightness is fundamental element in a gecko's life: that's the reason why we decided to use
				different tools, like the DHT11 sensor for temperature and humidity, a brightness sensor and some LEDS,
				to keep track of the terrarium's condition.
				<br>More specifically, coloured LEDS are used to inform the owner of the pet if the mentioned parameters
				are
				okay or not.

		</article>

	</section>



	<footer>
		<h5>Copyright &copy;&reg; 2021, Mirco Hu, Viviana Hyskaj, Caterina Mugnai, David Nardi</h5>
	</footer>
</body>

</html>
 )==";
}
