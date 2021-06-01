String internal_html_page(String temperature, String humidity, String brightness, int temp_led, int hum_led, int brigh_led){
  String img_temp = "";
  String img_hum = "";
  String img_brigh = "";
  
  switch (temp_led){
    case 1:
        img_temp = "Led_Red.png?raw=true";
        break;
    case 2:
        img_temp = "LED_Green.png?raw=true";
        break;
    case 3:
        img_temp = "Led_Blue.png?raw=true";
        break;
  }

  switch (hum_led){
    case 1:
        img_hum = "LED_Green.png?raw=true";
        break;
    case 2:
        img_hum = "Led_Red.png?raw=true";
        break;
  }
  switch (brigh_led){
    case 1:
        img_brigh = "LED_Green.png?raw=true";
        break;
    case 2:
        img_brigh = "Led_Red.png?raw=true";
        break;
  }
    

  return R"==(
    <html>
    <head>
		<title>Smart Terrarium</title>
        <meta http-equiv="content-type" content="text/html;charset=UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <meta http-equiv="refresh" content="30"> <!-- refresh automatico della pagina ogni 30 secondi -->
       	<link rel="preconnect" href="https://fonts.gstatic.com">
		<link href="https://fonts.googleapis.com/css2?family=Imbue:wght@350&family=Literata:ital,wght@1,500&display=swap" rel="stylesheet">
        <link rel="shortcut icon" href="https://raw.githubusercontent.com/david-inf/terrarium/main/icona.ico" />
		<style>
			* {
				font-family: 'Literata', serif;
				
			}
			html {
				margin: 0px;
				padding: 0px;
			}
			body{
				background-image: url('https://raw.githubusercontent.com/david-inf/terrarium/main/sfondo.jpg');
				height: 100%;
            	background-attachment: fixed;
            	background-repeat: no-repeat;
            	background-position: center;
            	background-size: cover;
            	margin: 0px;
            	padding: 0px;
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
				color: #000000;
				text-align:center;
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
			footer{
				background-color: #0a3409;
				position: fixed;
				width: 100%;
				height: 60px;
				bottom: 0;
				font-family: 'Poppins', sans-serif;
			}
			section{ 
				margin-right: 0px;
				padding-right: 0px;
			}
			
			#logo{
				float: left;
                margin-right: -10px;
                height: 200px;
                margin-top: -1.5%;
							
			}
			
			#logo2 {
				float: right;
				margin-right: -10px;
				height: 200px;
				margin-top: -1.5%;
            }
			nav{
				margin-right: 0px;
				padding-right: 0px;
			}
			
			ul {
				list-style-type: none;
				margin:0;
				padding: 0;
				overflow: hidden;
				position:absolute;
				top:130px;
				width:100%;
			}

			li {
                background-color: #90e70d;
				float:left;
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
                border:solid 1.5px #0A3409; 
                
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

			.article2{
				width: 50%;
				position: absolute;
                margin-top: 50px;
                margin-left: 100px;
                padding: 10px; 
			}
			
			#container-box{
				text-align:center;

			}
			.box{
				border: solid 1px #0A3409;
				border-radius: 0px 0px 0px 0px;
				width:25%;
				text-align:center;
				display: inline-block;
				margin:10px;
			}

			.box2{
				width:25%;
				text-align:center;
				display: inline-block;
				margin:10px;
			}

			
			
			h3{
                font-family: 'Verdana',sans-serif;
                color: #000000;
                font-size:20px;
				margin: 0px;
				padding:0px;
			}
			.text-box{
				text-align:center;
				font-size:35px;
				margin:0px;
				padding:0px;
			}

			#terrarium {
				float: right;
				margin-top: 100px;
				margin-right: 30px;
				width: 300px;
				height: 300px;
        }

		#ledRB {
				z-index:1;
				position: absolute;
				top:100px;
				right:30px;
			}
		#ledRB img{
				height:100px;
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
				<div id="terrarium">
					<img src="https://github.com/david-inf/terrarium/blob/main/Terrarium1.png?raw=true">
				</div>
			</aside>
			<nav>
				<ul>
					<li><a href="home.html">Home</a></li>
					<li><a class="active" href="internal_conditions.html">Internal Conditions</a></li>
					<li><a href="changes.html">Modify Thresholds</a></li>
					<li><a href="summary.html">Summary</a></li>
				</ul>
			</nav>
			<article>
				<h2>Internal Conditions</h2>
				<p>To grow, small reptiles need to live in a favorable environment for them.
                     Make sure they always have available water  and shelter to rest. 
                     Remember to take care of it. Here you can check the current situation of the Terrarium.
				Is your gecko okay right now? </p>
				<div id="container-box">
					<div class="box">
						<h3>Temperature</h3>
						<p class="text-box">)==" + temperature + R"==(&#8451</p>
					</div>
					<div class="box">
						<h3>Humidity</h3>
						<p class="text-box">)==" + humidity + R"==( %</p>
					</div>
					<div class="box">
						<h3>Brightness</h3>
						<p class="text-box">)==" + brightness + R"==(%</p>
					</div>
				<div id="container-box">
					<div id="container-box">
						<div class="box2">
							<img src="https://github.com/david-inf/terrarium/blob/main/)==" + img_temp + R"==(" height="150px" >
						</div>
						<div class="box2">
              <img src="https://github.com/david-inf/terrarium/blob/main/)==" + img_hum + R"==(" height="150px" >					</div>
						<div class="box2">
              <img src="https://github.com/david-inf/terrarium/blob/main/)==" + img_brigh + R"==(" height="150px" >						</div>
					<div id="container-box">
			</article>
			
		</section>
		
		
		<footer>
            <h5>Copyright &copy;&reg; 2021, Mirco Hu, Viviana Hyskaj, Caterina Mugnai, David Nardi</h5>
        </footer>
    </body>
    
</html>
    )==";
}
