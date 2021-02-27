<html>
    <head>
        <title>Ashion's Guild - Cadastro de Cliente</title>
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

                            echo "<br/><br/><br/>";
                            if($_POST['cxnome'] != ""){

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

                                $sql = "insert into tbcli (nome, contato, end, fone, email, ramo, fotocli) values ('$nome', '$cont', '$end', '$fone', '$email', '$ramo', '$nomefoto')";
                                $query = mysqli_query($conn,$sql);
                                echo "<div id='push'></div><h3 class='alrt'>Cliente cadastrado com sucesso!<div class='border'></div></h3>";
                            }
                            else{
                                echo "<div id='push'></div><h3 class='alrt'>Não foi possível cadastrar o cliente!<div class='border'></div></h3>";
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
            
            <a href="listacli.php"><p><img class='botao' src='../img/voltar.png'/></p></a>
        </div>
    </body>
</html>