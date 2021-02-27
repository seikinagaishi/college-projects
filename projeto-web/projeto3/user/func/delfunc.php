<html>
    <head>
        <title>Ashion's Guild - Remoção de Funcionário</title>
        <meta charset="utf-8"/>
        <link rel="stylesheet" type="text/css" href="../../css/style.css"/>
        <link rel="shortcut icon" type="img/x-icon" href="../../img/logo.png"/>
    </head>
    
    <body>
        <div id="pagmemb">
            <div id="push"></div>
            <?php
                error_reporting(0);
                SESSION_START();
                if($_SESSION["user"]){
                    include_once '../conexao.php';
                    $teste = mysqli_query($conn, "select login from tbfunc where perfil='Administrador'");
                    while($line = mysqli_fetch_array($teste)){

                        if($_SESSION["user"] == $line["login"]){

                            $id = $_GET['id'];

                            $excluir = "delete from tbfunc where codfunc='$id' ";
                            $executar = mysqli_query($conn,$excluir);
                            echo "<br/><br/><br/>";
                            if($executar){
                                echo "<h3 class='alrt'>Funcionário deletado com sucesso!<div class='border'></div></h3>"."<br>"."<a href='listafunc.php'><p><img class='botao' src='../../img/voltar.png'/></p></a>";
                            }
                            else{
                                echo "<h3 class='alrt'>Erro ao deletar funcionário<br/>Esse Funcionário ainda pode conter Serviços Pendentes!<div class='border'></div></h3>"."<br>"."<a href='listafunc.php'><p><img class='botao' src='../../img/voltar.png'/></p></a>";
                            }
                    
                        }
                    }
                }

            else{
                echo("<h3 class='alrt'>Atenção: Área Restrita<div class='border'></div></h3>");
            ?>

                <script language="javascript" type="text/javascript">
                    if(window.location) window.location.href="../login/index.php";
                </script>

            <?php
                }
            ?>
        </div>
    </body>
</html>