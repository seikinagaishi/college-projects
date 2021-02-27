<html>
    <head>
        <meta charset="utf-8"/>
        <title>Ashion's Guild - Login</title>
        <link rel="stylesheet" type="text/css" href="../../css/style.css"/>
        <link rel="shortcut icon" type="image/x-icon" href="../../img/logo.png"/>
        
    </head>

    <body>
        <div id="paglog">
            <?php
                
                error_reporting(0);
                SESSION_START();
                include_once("../conexao.php");
                if($_SESSION["user"]){
                    $teste = mysqli_query($conn, "select login from tbfunc where perfil='Administrador'");
                    while($line = mysqli_fetch_array($teste)){

                        if($_SESSION["user"] == $line["login"]){
            ?>
                            <script language="javascript" type="text/javascript">
                                if(window.location) window.location.href="../adm.php";
                            </script>
            <?php
                        }
                    }
                    $teste = mysqli_query($conn, "select *from tbfunc where perfil='Tecnico'");
                    while($line = mysqli_fetch_array($teste)){
                        if($_SESSION["user"] == $line["login"]){
            ?>
                            <script language="javascript" type="text/javascript">
                                if(window.location) window.location.href="../tec.php";
                            </script>
            <?php
                        }
                    }
                }
                else{
            ?>
                <br/><br/><br/><br/><br/><br/><br/>
                <form action="valida.php" method="post">
                    <fieldset class="loginsession">
                        <br/>
                        <h2 class="alrt">Entre na sua conta</h2>
                        <div class="border"></div>
                        <br/>
                        <input type="text" name="usuario" placeholder="Login"/>
                        <br/><br/>
                        <input type="password" name="senha" placeholder="Senha"/>
                        <br/><br/>

                        <input class="entrebt" type="submit" value=""/>
                        <br/>
                        <a href="../../"><img class='botao' src='../../img/voltar.png'></a>
                        <br/>
                        
                    </fieldset>
                </form>
            <?php } ?>
        </div>
    </body>
</html>
