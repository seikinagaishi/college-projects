<html>
    <head>
        <meta charset="utf-8"/>
        <title>Login</title>
        <link rel="stylesheet" type="text/css" href="../css/style.css"/>
        <link rel="shortcut icon" type="image/x-icon" href="img/baidu.png"/>
        <link href="https://fonts.googleapis.com/css?family=Gudea&display=swap" rel="stylesheet">
    </head>

    <body>
        <?php
            error_reporting(0);
            SESSION_START();
            if($_SESSION["user"]){
        ?>

        <script language="javascript" type="text/javascript">
            if(window.location) window.location.href="../adm/cadastro.php";
        </script>
        
        <?php
            }
        ?>

        <br/><br/><br/><br/><br/><br/><br/>
        <form action="valida.php" method="post">
            <fieldset>
            <br/>
            <h2>Entre na sua conta</h2>
            <div class="border"></div>
            <br/>
            <input type="text" name="usuario" placeholder="Login"/>
            <br/><br/>
            <input type="password" name="senha" placeholder="Senha"/>
            <br/><br/>

            <input class="bt" type="submit" value="Entrar">
            <br/><br/><br/>
            <a href="../index.php"><p>Baidu (OFICIAL)</p></a><br/>
            </fieldset>
        
        </form>
    </body>
</html>
