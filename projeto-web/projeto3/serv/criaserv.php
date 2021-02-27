<html>
    <head>
        <title>Ashion's Guild - Cadastro de Serviço</title>
        <meta charset="utf-8"/>
        <link rel="stylesheet" type="text/css" href="../css/style.css"/>
        <link rel="shortcut icon" type="img/x-icon" href="../img/logo.png">
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

                            echo "<br/><br/><br/>";
                            if($_POST['cxcli'] != ""){

                                $cli = $_POST['cxcli'];
                                $tec = $_POST['cxtec'];
                                $serv = $_POST['cxserv'];
                                $data = $_POST['data'];
                                $hora = $_POST['hora'];

                                $sql = "insert into tbserv (nomecli, nometec, serv, data, hora, status, obstec) 
                                values ('$cli', '$tec', '$serv', '$data', '$hora', 0, ' ')";
                                $query = mysqli_query($conn,$sql);
                                echo "<div id='push'></div><h3 class='alrt'>Serviço cadastrado com sucesso!<div class='border'></div></h3>";

                            }
                            else{
                                echo "<div id='push'></div><h3 class='alrt'>Não foi possível cadastrar o serviço!<div class='border'></div></h3>";
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
            <br/>
            
            <a href="listaserv.php"><p><img class='botao' src='../img/voltar.png'/></p></a>
        </div>
    </body>
</html>