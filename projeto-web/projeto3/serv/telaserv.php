<html>
    <head>
        <meta charset="utf-8"/>
        <title>Ashion's Guild - Meus Serviços</title>
        <link rel="shortcut icon" type="image/x-icon" href="../img/logo.png"/>
        <link rel="stylesheet" type="text/css" href="../css/style.css"/>
    </head>

    <body>
            <?php      
                error_reporting(0);
                SESSION_START();
                include_once '../user/conexao.php';
                if($_SESSION["user"]){
                    $teste = mysqli_query($conn, "select *from tbfunc where perfil='Tecnico'");
                    while($line = mysqli_fetch_array($teste)){
                        if($_SESSION["user"] == $line["login"]){
                            $consultar = "select *from tbserv where nometec='".$line['codfunc']."' and status=0";
                            $executar = mysqli_query($conn,$consultar);
            ?>
                            <div id="nav">
                                <a href="../user/tec.php"><img class="return" src="../img/retorno.png"/></a>
                                <br/><br/>
                                <h1><img class="ashion" src="../img/ashion.png"/></h1>
                            </div>
                            
                            <aside>
                                <div id="pushserv"></div>

                                <div id="pagservnav">
                                    <div id="listar">
                                        <?php
                                            while($linha = mysqli_fetch_array($executar))
                                            {
                                        ?>
                                                <fieldset class="client">
                                                    <br/><br/>
                                                    <?php
                                                        $test = mysqli_query($conn, "select *from tbcli where codcli='".$linha['nomecli']."'");
                                                        $linu = mysqli_fetch_array($test);
                                                    ?>
                                                    Cliente<br/><input type="text" value="<?php echo $linu["nome"];?>" readonly ><br/><br/>
                                                    Serviço<br/><input type="text" value="<?php echo $linha["serv"];?>" readonly><br/><br/>
                                                    Data<br/><input type="date" value="<?php echo $linha["data"];?>" readonly><br/><br/>
                                                    Hora<br/><input type="time" value="<?php echo $linha["hora"];?>" readonly><br/><br/>

                                                    <a href="terminandoserv.php?id=<?php echo $linha["codserv"];?>"><img class="botao2" src="../img/concluir.png"/></a>
                                                </fieldset>
                                                <br/>
                                        <?php } ?>
                                    </div>
                                </div>
                            </aside>

            <?php
                        }
                    }
                }
                else{
                    echo("<h3 class='alrt'>Atenção: Área Restrita<div class='border'></div></h3>");
            ?>

                    <script language="javascript" type="text/javascript">
                        if(window.location) window.location.href="../user/login/index.php";
                    </script>
            
            <?php
                }
            ?>    
    </body>
</html>