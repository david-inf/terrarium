String summary_html_page(String temperature, String humidity, String brightness, int sun_moon, String color_led_temp,
  String L_T_T_D, String H_T_T_D,String L_T_T_N, String H_T_T_N,String L_H_T,String H_H_T, String L_T ){
  String img_sunmoon ="";
  
  switch (sun_moon){
    case 1: 
        img_sunmoon = "day.png?raw=true";
        break;
    case 2:
        img_sunmoon = "night.png?raw=true";
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
      <link href="https://fonts.googleapis.com/css2?family=Imbue:wght@350&family=Literata:ital,wght@1,500&display=swap"
          rel="stylesheet">
      <link rel="shortcut icon" href="https://raw.githubusercontent.com/david-inf/terrarium/main/icona.ico"/>
      <style>
          * {
              font-family: 'Literata', serif;
  
          }
  
          html {
              margin: 0px;
              padding: 0px;
          }
  
          body {
              background-image: url('https://github.com/david-inf/terrarium/blob/main/sfondo.jpg?raw=true');
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
              margin-top: 0%;
  				
  		}
  			
  		h2 {
  			font-family: 'Julius says one', sans-serif;
              text-align: center;
  			letter-spacing: 1px;
  			font-size: 50px;
  			color: #082b08;
  	
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
              border: solid 1.5px #0A3409;
  
  
          }
  
          aside {
              width: 40%;
              position: absolute;
              top: 85px;
              right: 0px;
          }
  
          article {
              width: 60%;
              position: absolute;
              top: 250px;
              margin-left: 100px;
              padding: 10px;            
              background-color: #e5ff0032;
  		    border: solid 3px #1a4104;
          }
  
          #container-box {
              text-align: center;
          }
  
          .box {
              border: solid 1px #0A3409;
  			border-radius: 0px 0px 0px 0px;
              width: 30%;
              text-align: center;
              display:inline-block;
              margin: 10px;
          }
  
          h3{
              font-family: 'Verdana',sans-serif;
              color: #000000;
              font-size:20px;
  			margin: 0px;
  			padding:0px;
          }
          .text-box {
              text-align: center;
              font-size: 35px;
              margin: 0px;
              padding: 0px;
          }
  
          #Moon1{				
              z-index:1;
  		    position: absolute;
  			top:100px;
  			right:30px;
  
          }
          #Moon {
              float: right;
              height: 100px;
              margin-top: 150px;
              margin-right: 50px;
          }
      </style>
  
  <body>
      <header>
          <img id="logo" src="https://github.com/david-inf/terrarium/blob/main/logo1.png?raw=true">
          <img id="logo2" src="https://github.com/david-inf/terrarium/blob/main/logo1.png?raw=true">
          <h1> Smart Terrarium </h1>  
      </header>
  
      <section>
  
      <aside>
          <div id="Moon">
              <img src="https://github.com/david-inf/terrarium/blob/main/)==" + img_sunmoon + R"==(">
      </aside>
          <nav>
              <ul>
                  <li><a href="home.html">Home</a></li>
                  <li><a href="internal_conditions.html">Internal Conditions</a></li>
                  <li><a href="changes.html">Modify Threshold</a></li>
                  <li><a class="active" href="summary.html">Summary</a></li>
              </ul>
          </nav>
          <article>
              <h2>Summary</h2>
              <p> The obtained results  are summarized on this page. </p>
              <div id="container-box">
                  <div class="box">
                      <h3>Temperature</h3>
                      <p class="text-box">)==" + temperature + R"==( &#8451</p>
                  </div>
                  <div class="box">
                      <h3>Humidity</h3>
                      <p class="text-box">)==" + humidity + R"==(%</p>
                  </div>
                  <div class="box">
                      <h3>Brightness</h3>
                      <p class="text-box">)==" + brightness + R"==(%</p>
                  </div>
                  <div id="container-box">
                      <div id="container-box">
                          <div class="box">
                              <h3>Day Threshold T°</h3>
                              <p class="text-box">)==" + L_T_T_D + "-" + H_T_T_D + R"==(&#8451</p>
                          </div>
                          <div class="box">
                              <h3>Threshold H</h3>
                              <p class="text-box">)==" + L_H_T + "-" + H_H_T + R"==(%</p>
                          </div>
                          <div class="box">
                              <h3>Threshold B</h3>
                              <p class="text-box">)==" + L_T + R"==(%</p>
                          </div>
                          <div id="container-box">
                              <div id="container-box">
                                  <div class="box">
                                      <h3>Night Threshold T°</h3>
                                      <p class="text-box">)==" + L_T_T_N + "-" + H_T_T_N + R"==(&#8451</p>
                                  </div>
                                  <div class="box">
                                      <h3>Next control</h3>
                                      <p class="text-box"> In 2 hours</p>
                                  </div>
                                  <div class="box">
                                      <h3>Temperature Led</h3>
                                      <p class="text-box"> )==" + color_led_temp + R"==( </p>
                                  </div>
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
