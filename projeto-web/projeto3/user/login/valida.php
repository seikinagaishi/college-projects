<html>
    <head>
        <meta charset="utf-8"/>
        <title>Ashion's Guild - Login</title>
        <link rel="stylesheet" type="text/css" href="../../css/style.css"/>
        <link rel="shortcut icon" type="image/x-icon" href="../../img/logo.png"/>
    </head>

    <body>
        <?php
            SESSION_START();
            $login=isset($_POST["usuario"])?strtolower($_POST["usuario"]):"";
            $senha=isset($_POST["senha"])?md5($_POST["senha"]):"";

            include_once("../conexao.php");

            $log=mysqli_query($conn, "select * from tbfunc where login='$login' and senha='$senha'")or die(mysqli_error());

            $linha=mysqli_fetch_array($log);

            if($login=="" || $senha=="")die("<div id='push'></div><h3>Acesso restrito, efetue LOGIN<div class='border'></div></h3> <br><a href=\"javascript:history.go(-1)\"><p><img class='botao' src='../../img/voltar.png'></p></a>");

            if($login!=$linha["login"]||$senha!=$linha["senha"])die ("<div id='push'></div><h3>Login ou Senha Incorreta!<div class='border'></div></h3><br><a href=\"javascript:history.go(-1)\"><p><img class='botao' src='../../img/voltar.png'></p></a>");

            if($login==$linha["login"] && $senha==$linha["senha"]) {
                $_SESSION["user"]=$linha["login"];
                if($linha['perfil']=="Administrador"){
        ?>
                    <script language="javascript" type="text/javascript">
                        document.url="../adm.php";
                        window.location.href="../adm.php";
                    </script>
        <?php   }
                if($linha['perfil']=="Tecnico"){
        ?>
                    <script language="javascript" type="text/javascript">
                        document.url="../tec.php";
                        window.location.href="../tec.php";
                    </script>
        <?php
                }
            }
        ?>              
    </body>
</html>