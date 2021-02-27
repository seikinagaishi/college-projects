<html>
    <head>
        <title>Baidu - Site Deletado</title>
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
                $id = $_GET['id'];

                $excluir = "delete from tbsites where codigo='$id' ";
                $executar = mysqli_query($conn,$excluir);
                echo "<br/><br/><br/>";
                if($executar)
                {
                    echo "<h3>Site deletado com sucesso!<div class='border'></div></h3>"."<br>"."<a href='listar.php'><p>Voltar</p></a>";
                }
                else
                {
                    echo "<h3>Erro ao deletar site!<div class='border'></div></h3>";
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
    </body>
</html>