<html>
    <head>
        <title>Baidu - Editando Site</title>
        <link rel="shortcut icon" type="image/x-icon" href="../img/baidu.png"/>
        <link rel="stylesheet" type="text/css" href="../css/style.css"/>
        <link href="https://fonts.googleapis.com/css?family=Gudea&display=swap" rel="stylesheet">
    </head>

    <body>
        <br/><br/><br/>
        <?php
            error_reporting(0);
            SESSION_START();
            if($_SESSION["user"]){
            
                include_once 'conexao.php';

                $id = $_GET['id'];

                $consulta = "select *from tbsites where codigo = '$id'";
                $executar = mysqli_query($conn,$consulta);

                    while($exibir = mysqli_fetch_array($executar))
                    {
        ?>
                        <form method="POST" action="editar.php">
                            <fieldset>
                                <h2><?php echo $exibir['nome']?></h2>
                                <div class="border"></div>
                                <br/>
                                <input type="hidden" name="codigo" value="<?php echo $exibir['codigo'];?>">
                                Nome<br/><input type="text" name="cxnome" value="<?php echo $exibir['nome'];?>"><br/><br/>
                                Endereço<br/><input type="text" name="cxend" value="<?php echo $exibir['endereco'];?>"><br/><br/>
                                Descrição<br/><textarea name="cxdesc"><?php echo $exibir['descricao'];?></textarea><br/><br/>

                                <input class="bt" type="submit" value="Editar">
                            </fieldset>
                        </form>

             <?php } ?>
            
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