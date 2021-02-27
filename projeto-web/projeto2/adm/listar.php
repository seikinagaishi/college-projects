<html>
    <head>
        <meta charset="utf-8"/>
        <title>Baidu - Sites</title>
        <link rel="shortcut icon" type="image/x-icon" href="../img/baidu.png"/>
        <link rel="stylesheet" type="text/css" href="../css/style.css"/>
        <link href="https://fonts.googleapis.com/css?family=Gudea&display=swap" rel="stylesheet">
    </head>

    <body>
        <?php
            error_reporting(0);
            SESSION_START();
            if($_SESSION["user"]){
            
                include_once 'conexao.php';
                $consultar = "select *from tbsites";
                $executar = mysqli_query($conn,$consultar);
        ?>
                <br/>
                <aside>
                    <div id="volta">
                        <form action="cadastro.php">
                            <button type="submit" class="ret">↩ Voltar</button>
                        </form>
                    </div>
                    
                    <div id="listar">
        <?php
                        while($linha = mysqli_fetch_array($executar))
                        {
        ?>
                        <fieldset>
                            <h2><?php echo $linha["nome"]?></h2>
                            <div class="border"></div>
                            <br/>
                            Nome<br/><input type="text" value="<?php echo $linha["nome"];?>" readonly ><br/><br/>
                            Endereco<br/><input type="text" value="<?php echo $linha["endereco"];?>" readonly><br/><br/>
                            Descrição<br/><textarea readonly><?php echo $linha["descricao"];?></textarea><br/><br/>

                            <a href="editando.php?id=<?php echo $linha["codigo"];?>">Editar</a> |
                            <a href="del.php?id=<?php echo $linha["codigo"];?>">Deletar</a>
                        </fieldset>
                        <br/>
                <?php } ?>
                     </div>
                 </aside>

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