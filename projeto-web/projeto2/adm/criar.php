<html>
    <head>
        <title>Baidu - Site Criado</title>
        <meta charset="utf-8"/>
        <link rel="stylesheet" type="text/css" href="../css/style.css"/>
        <link rel="shortcut icon" type="img/x-icon" href="../img/baidu.png"/>
        <link href="https://fonts.googleapis.com/css?family=Gudea&display=swap" rel="stylesheet">
    </head>
    
    <body>
        <?php
            error_reporting(0);
            SESSION_START();
            if($_SESSION["user"]){

                echo "<br/><br/><br/>";
                if($_POST['cxnome'] != ""){
                    include_once 'conexao.php';

                    $nome = $_POST['cxnome'];
                    $end = $_POST['cxend'];
                    $desc = $_POST['cxdesc'];

                    $sql = "insert into tbsites (nome, endereco, descricao) 
                    values ('$nome', '$end', '$desc')";
                    $query = mysqli_query($conn,$sql);
                    echo "<h3>Site criado com sucesso!<div class='border'></div></h3>";
                }
                else{
                    echo "<h3>Não foi possível criar o site!<div class='border'></div></h3>";
                }
        
            }
            else{
                echo("<h3>Atenção: Área Restrita<div class='border'></div></h3>");
        ?>
        <script language="javascript" type="text/javascript">
            if(window.location) window.location.href="../login/index.php";
        </script>

        <?php
            }
        ?>
        <br/>
        
        <a href="cadastro.php"><p>Voltar</p></a>
    </body>
</html>