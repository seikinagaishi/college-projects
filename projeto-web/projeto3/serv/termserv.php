<html>
    <head>
        <title>Ashion's Guild - Concluir Serviço</title>
        <meta charset="utf-8"/>
        <link rel="stylesheet" type="text/css" href="../css/style.css"/>
        <link rel="shortcut icon" type="img/x-icon" href="../img/logo.png"/>
    </head>
    
    <body>
        <div id="pagserv">
            <?php
            
                error_reporting(0);
                SESSION_START();
                include_once '../user/conexao.php';
                if($_SESSION["user"]){
                    $teste = mysqli_query($conn, "select *from tbfunc where perfil='Tecnico'");
                    while($line = mysqli_fetch_array($teste)){
                        if($_SESSION["user"] == $line["login"]){

                            $id = $_POST['codigo'];
                            $obs = $_POST['cxobstec'];

                            echo $id;

                            $alterar = "UPDATE tbserv SET 
                            status = 1,
                            obstec = '$obs'
                            where codserv = '$id'";

                            $executar = mysqli_query($conn,$alterar);
                            echo "<br/><br/><br/>";
                            if($executar)
                            {
                                echo "<div id='push'></div><h3 class='alrt'>Serviço Finalizado com sucesso!<div class='border'></div></h3>";
                                echo "<br>";
                                echo "<a href='telaserv.php'><p><img class='botao' src='../img/voltar.png'/></p></a>";
                            }
                            else
                            {
                                echo "<div id='push'></div><h3 class='alrt'>Erro ao tentar finalizar o serviço<div class='border'></div></h3>";
                                echo "<br>";
                                echo "<a href='telaserv.php'><p><img class='botao' src='../img/voltar.png'/></p></a>";
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
                        if(window.location) window.location.href="telaserv.php";
                    </script>

            <?php
                }
            ?>
        </div>
    </body>
</html>