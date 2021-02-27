<html>
    <head>
        <title>Baidu - Site Editado</title>
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
            
                include_once 'conexao.php';

                $id = $_POST['codigo'];
                $nome = $_POST['cxnome'];
                $end = $_POST['cxend'];
                $desc = $_POST['cxdesc'];

                $alterar = "UPDATE tbsites SET 
                nome = '$nome', 
                endereco = '$end',
                descricao = '$desc'
                where codigo = '$id'";

                $executar = mysqli_query($conn,$alterar);
                echo "<br/><br/><br/>";
                if($executar)
                {
                    echo "<h3>Site editado com sucesso!<div class='border'></div></h3>";
                    echo "<br>";
                    echo "<a href='listar.php'><p>Voltar</p></a>";
                }
                else
                {
                    echo "<h3>Erro ao tentar editar site!<div class='border'></div></h3>";
                }

        ?>

        <?php
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

    </body>
</html>