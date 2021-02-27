<html>
    <head>
        <meta charset="utf-8"/>
        <title>Ashion's Guild - Lobby de Funcionários</title>
        <link rel="shortcut icon" type="image/x-icon" href="../img/logo.png"/>
        <link rel="stylesheet" type="text/css" href="../css/style.css"/>
    </head>

    <body>
        <div id="pagserv">
            <?php      
                error_reporting(0);
                SESSION_START();
                include_once '../user/conexao.php';
                if($_SESSION["user"]){
                    $teste = mysqli_query($conn, "select *from tbfunc where perfil='Tecnico'");
                    while($line = mysqli_fetch_array($teste)){
                        if($_SESSION["user"] == $line["login"]){
            ?>
                            <div id="pagserv">
                                <div id="push"></div>
                                <div id="push"></div>
                                <center>
                                    <a href="../serv/telaserv.php"><img class="botao" src="../img/serv.png"/></a>
                                </center>
                            </div>
                            <a href="../user/login/fimSession.php"><p>Encerrar Sessão</p></a>
            <?php
                        }
                    }
                }
                else{
                    echo("<h3>Atenção: Área Restrita<div class='border'></div></h3>");
            ?>

                    <script language="javascript" type="text/javascript">
                        if(window.location) window.location.href="../user/login/index.php";
                    </script>

            <?php
                }
            ?>     
        </div>
    </body>
</html>