String changes_html_page() {
  return R"==( // aggiornare

<!DOCTYPE html>
<html lang="en">

<head>
    <title>Smart Terrarium</title>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <link rel="preconnect" href="https://fonts.gstatic.com">
    <link href="https://fonts.googleapis.com/css2?family=Imbue:wght@350&family=Literata:ital,wght@1,500&display=swap"
        rel="stylesheet"> <!--togliere visto non s'è usata-->
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="refresh" content="60">
    <link rel="shortcut icon" href="https://raw.githubusercontent.com/david-inf/terrarium/main/icona.ico">

    <style>
        * {
            font-family: 'Literata', serif;
        }

        html {
            margin: 0px;
            padding: 0px;
        }

        body {
            background-image: url('https://raw.githubusercontent.com/david-inf/terrarium/main/sfondo.jpg');
            <!--height: 100%;-->
            width: 100%;
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
            color: #0A3409;
        }

        p {
            font-family: 'Verdana', sans-serif;
            color: #000000;
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

        #input {
            font-family: inherit;
            font-size: inherit;
            position: relative;
            height: 100%;
            width: 90%;
            background-color: rgb(196, 221, 201);
            margin-bottom: 5px;
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

        .yoursThres {
            width: 50%;
            position: absolute;
            top: 130px;
            margin-right: 20px;
            padding: 10px;
            text-align: center;
        }

        article {
            width: 50%;
            position: absolute;
            top: 250px;
            margin-left: 100px;
            padding: 10px;
            background-color: #e5ff0032;
			border: solid 3px #1a4104;
            text-align: center;
        }

        #container-box {
            text-align: center;
        }

        .box {
            border: solid 1px #0A3409;
            border-radius: 0px 0px 0px 0px;
            width: 25%;
            text-align: center;
            display: inline-block;
            margin: 10px;
        }

        h3 {
            font-family: 'Verdana', sans-serif;
            color: #000000;
            font-size: 20px;
            margin: 0px;
            padding: 0px;
        }

        .text-box {
            text-align: center;
            font-size: 35px;
            margin: 0px;
            padding: 0px;
        }

        #ingra {
            float: right;
            margin-right: -10px;
            padding-right: 0px;
            height: 400px;
            margin-top: 150px;
        }
        
    </style>
</head>

<body>
    <header>
        <img id="logo" src="https://github.com/david-inf/terrarium/blob/main/logo1.png?raw=true">
        <img id="logo2" src="https://github.com/david-inf/terrarium/blob/main/logo1.png?raw=true">
        <h1>Smart Terrarium</h1>
    </header>

    <div>
        <nav>
            <ul>
                <li><a href="home.html">Home</a></li>
                <li><a href="internal_conditions.html">Internal Conditions</a></li>
                <li><a class="active" href="changes.html">Modify Threshold</a></li>
                <li><a href="summary.html">Summary</a></li>
            </ul>
        </nav>
    </div>

    <article>
        <h2>Changeable Thresholds</h2>
        <p>
            Here you can change the default thresholds set in the terrarium. You can only reduce the intervals, for the reptile's safety. The current thresholds are set in the margin values for the life conditions.
        </p>

        <div id="container-box">
            <div class="box">
                <h3>Day Temperature</h3>
                <br>
                <label for="name">Maximum Value:</label>
                <input type="text" id="input" minlength="2" maxlength="2" max="32" min="28">
            </div>
            <div class="box">
                <h3>Day Temperature</h3>
                <br>
                <label for="name">Minimum Value:</label>
                <input type="text" id="input" minlength="2" maxlength="2" max="32" min="28">
            </div>
        </div>
        <div>
            <div class="box">
                <h3>Night Temperature</h3>
                <br>
                <label for="name">Maximum Value:</label>
                <input type="text" id="input" minlength="2" maxlength="2">
            </div>
            <div class="box">
                <h3>Night Temperature</h3>
                <br>
                <label for="name">Minimum Value:</label>
                <input type="text" id="input" minlength="2" maxlength="2">
            </div>
        </div>
        <br>
        <div class="container-box">
            <div class="box">
                <h3>Humidity</h3>
                <br>
                <label for="name">Maximum Value:</label>
                <input type="text" id="input" minlength="2" maxlength="2">
            </div>
            <div class="box">
                <h3>Humidity</h3>
                <br>
                <label for="name">Minimum Value:</label>
                <input type="number" step="any" id="input" minlength="2" maxlength="2" name="min_hum"> <!--con step rende un float-->
            </div>
        </div>
        <br>
        <div class="box">
            <h3>Brightness</h3>
            <br>
            <label for="name">Exact Value:</label>
            <input type="text" id="input">
        </div>

        <p style="margin-top: 100px;"></p>
    </article>

    <aside>
        <img id="ingra" src="https://github.com/david-inf/terrarium/blob/main/changes1.png?raw=true">
    </aside>


    <footer>
        <h5>Copyright &copy;&reg; 2021, Mirco Hu, Viviana Hyskaj, Caterina Mugnai, David Nardi</h5>
    </footer>
</body>

</html>
  )==";
}
