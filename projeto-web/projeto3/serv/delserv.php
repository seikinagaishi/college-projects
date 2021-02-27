<html>
    <head>
        <title>Ashion's Guild - Remoção de Serviço</title>
        <meta charset="utf-8"/>
        <link rel="stylesheet" type="text/css" href="../css/style.css"/>
        <link rel="shortcut icon" type="img/x-icon" href="../img/logo.png"/>
    </head>
    
    <body>
        <div id="pagserv">
            <?php
                error_reporting(0);
                SESSION_START();
                if($_SESSION["user"]){
                    include_once '../user/conexao.php';
                    $teste = mysqli_query($conn, "select login from tbfunc where perfil='Administrador'");
                    while($line = mysqli_fetch_array($teste)){

                        if($_SESSION["user"] == $line["login"]){
                    
                            include_once '../user/conexao.php';
                            $id = $_GET['id'];

                            $excluir = "delete from tbserv where codserv='$id' ";
                            $executar = mysqli_query($conn,$excluir);
                            echo "<br/><br/><br/>";
                            if($executar)
                            {
                                echo "<div id='push'></div><h3 class='alrt'>Serviço deletado com sucesso!<div class='border'></div></h3>"."<br>"."<a href='listaserv.php'><p><img class='botao' src='../img/voltar.png'/></p></a>";
                            }
                            else
                            {
                                echo "<div id='push'></div><h3 class='alrt'>Erro ao deletar serviço!<div class='border'></div></h3>"."<br>"."<a href='listaserv.php'><p><img class='botao' src='../img/voltar.png'/></p></a>";
                            }
                        
                        }
                    }
                }
                
                else{
                    echo("<div id='push'></div><h3 class='alrt'>Atenção: Área Restrita<div class='border'></div></h3>");
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