<html>
    <head>
        <meta charset="utf-8"/>
        <link rel="stylesheet" type="text/css" href="../css/style.css"/>
        <link rel="shortcut icon" type="image/x-icon" href="../img/baidu.png"/>
        <link href="https://fonts.googleapis.com/css?family=Gudea&display=swap" rel="stylesheet">
        <title>Baidu - Criação de Site</title>
    </head>

    <body>
        <?php
            error_reporting(0);
            SESSION_START();
            if($_SESSION["user"]){
            ?>
                <br/><br/><br/>
                <form method="POST" action="criar.php">
                
                    <fieldset>
                        <h2>Criação de Site</h2>
                        <div class="border"></div>
                        <br/>
                        
                        <input type="text" name="cxnome" placeholder="Nome" required><br/><br/>
                        <input type="text" name="cxend" placeholder="Endereço" required><br/><br/>
                        <textarea name="cxdesc" placeholder="Descrição" required></textarea><br/><br/>
                        
                        <br/>
                        <input class="bt" type="submit" value="Criar">
                    </fieldset>
                
                </form>
                <br/><br/>
                <a href="../index.php"><p>Baidu (OFICIAL)</p></a><br/>
                <a href="listar.php"><p>Sites Existentes</p></a>    
                <br/><br/>
                <a href="../login/fimSession.php"><p>Logout</p></a>

                <?php
                    }
                    else{
                    echo("<h3>Atenção: Área Restrita<div class='border'></div></h3>");
                ?>

                <script language="javascript" type="text/javascript">
                    if(window.location) window.location.href="../login/index.php";
                </script>

                <?php
                    }
                ?>

    </body>
</html>

