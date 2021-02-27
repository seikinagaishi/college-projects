<html>
    <head>
        <title>Ashion's Guild - Alteração das Informações do Serviço</title>
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

                            $id = $_POST['codigo'];
                            $cli = $_POST['cxcli'];
                            $tec = $_POST['cxtec'];
                            $serv = $_POST['cxserv'];
                            $data = $_POST['data'];
                            $hora = $_POST['hora'];

                            $alterar = "UPDATE tbserv SET 
                            nomecli = '$cli',
                            nometec = '$tec',
                            serv = '$serv',
                            data = '$data',
                            hora = '$hora'
                            where codserv = '$id'";

                            $executar = mysqli_query($conn,$alterar);
                            echo "<br/><br/><br/>";
                            if($executar)
                            {
                                echo "<div id='push'></div><h3 class='alrt'>Informações do serviço alteradas com sucesso!<div class='border'></div></h3>";
                                echo "<br>";
                                echo "<a href='listaserv.php'><p><img class='botao' src='../img/voltar.png'/></p></a>";
                            }
                            else
                            {
                                echo "<div id='push'></div><h3 class='alrt'>Erro ao tentar alterar informações do serviço!<div class='border'></div></h3>";
                                echo "<br>";
                                echo "<a href='listaserv.php'><p><img class='botao' src='../img/voltar.png'/></p></a>";
                            }

            ?>

            <?php
                    
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