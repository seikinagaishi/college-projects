<html>
    <head>
        <title>Ashion's Guild - Alterando Informações do Cliente</title>
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

                            $id = $_POST['codigo'];
                            $nome = $_POST['cxnome'];
                            $cont = $_POST['cxcont'];
                            $end = $_POST['cxend'];
                            $fone = $_POST['cxfone'];
                            $email = $_POST['cxemail'];
                            $ramo = $_POST['cxramo'];

                            if(isset($_FILES['fotocli'])){
                                $ext = strtolower(substr($_FILES['fotocli']['name'], -4));
                                $nomefoto=md5(time()).$ext;
                                $dir="../img/cli/";

                                move_uploaded_file($_FILES['fotocli']['tmp_name'], $dir.$nomefoto);
                            }

                            $alterar = "UPDATE tbcli SET 
                            nome = '$nome',
                            contato = '$cont',
                            end = '$end',
                            fone = '$fone',
                            email = '$email',
                            ramo = '$ramo',
                            fotocli='$nomefoto'
                            where codcli = '$id'";

                            $executar = mysqli_query($conn,$alterar);
                            echo "<br/><br/><br/>";
                            if($executar)
                            {
                                echo "<div id='push'></div><h3 class='alrt'>Informações do cliente alteradas com sucesso!<div class='border'></div></h3>";
                                echo "<br>";
                                echo "<a href='listacli.php'><p><img class='botao' src='../img/voltar.png'/></p></a>";
                            }
                            else
                            {
                                echo "<div id='push'></div><h3 class='alrt'>Erro ao tentar alterar informações do cliente!<div class='border'></div></h3>";
                                echo "<br>";
                                echo "<a href='listacli.php'><p><img class='botao' src='../img/voltar.png'/></p></a>";
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