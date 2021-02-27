<html>
    <head>
        <meta charset="utf-8">
        <title>Ashion's Guild - Administrador</title>
        <link rel="shortcut icon" type="image/x-icon" href="../img/logo.png"/>
        <link rel="stylesheet" type="text/css" href="../css/style.css"/>
    </head>
    <body>
        <?php
            error_reporting(0);
            SESSION_START();
            if($_SESSION["user"]){
                include_once 'conexao.php';
                $teste = mysqli_query($conn, "select login from tbfunc where perfil='Administrador'");
                while($line = mysqli_fetch_array($teste)){
                    if($_SESSION["user"] == $line["login"]){
        ?>
                        <div id="pagadm">
                            <div id="admicons"></div>
                            <img class="mesa" src="../img/mesa.png"/>
                            <center>
                                <div id="filaicone">
                                    <a href="../cli/listacli.php"><img class="iconeclick" src="../img/clientes.png"/></a>
                                    <a href="../serv/listaserv.php"><img class="iconeclick" src="../img/servicos.png"/></a>
                                    <a href="func/listafunc.php"><img class="iconeclick" src="../img/membros.png"/></a>
                                </div>
                            </center>
                        </div>
                        <div id="nah"><a href="login/fimSession.php"><p>Encerrar Sessão</p></a></div>
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
    </body>
</html>