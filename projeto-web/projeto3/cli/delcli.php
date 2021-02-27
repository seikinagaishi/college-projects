<html>
    <head>
        <title>Ashion's Guild - Remoção de Cliente</title>
        <meta charset="utf-8"/>
        <link rel="stylesheet" type="text/css" href="../css/style.css"/>
        <link rel="shortcut icon" type="img/x-icon" href="../img/logo.png"/>
    </head>
    
    <body>
        <div id="pagcli">
            <?php
                error_reporting(0);
                SESSION_START();
                if($_SESSION["user"]){
                    include_once '../user/conexao.php';
                    $teste = mysqli_query($conn, "select login from tbfunc where perfil='Administrador'");
                    while($line = mysqli_fetch_array($teste)){

                        if($_SESSION["user"] == $line["login"]){
                    
                            $id = $_GET['id'];

                            $excluir = "delete from tbcli where codcli='$id' ";
                            $executar = mysqli_query($conn,$excluir);
                            echo "<br/><br/><br/>";

                            if($executar){
                                echo "<div id='push'></div><h3 class='alrt'>Cliente deletado com sucesso!<div class='border'></div></h3>"."<br>"."<a href='listacli.php'><p><img class='botao' src='../img/voltar.png'/></p></a>";
                            }
                            else{
                                echo "<div id='push'></div><h3 class='alrt'>Erro ao deletar Cliente<br/>Esse cliente ainda pode conter Serviços Registrados!<div class='border'></div></h3>"."<br>"."<a href='listacli.php'><p><img class='botao' src='../img/voltar.png'/></p></a>";
                            }
                        }
                    }
                }
                else{
                    echo("<div id='push'></div><h3 class='alrt'>Atenção: Área Restrita<div class='border'></div></h3>");
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