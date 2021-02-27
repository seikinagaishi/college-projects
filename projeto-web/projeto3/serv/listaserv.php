<html>
    <head>
        <meta charset="utf-8"/>
        <title>Ashion's Guild - Serviços</title>
        <link rel="shortcut icon" type="image/x-icon" href="../img/logo.png"/>
        <link rel="stylesheet" type="text/css" href="../css/style.css"/>
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
                        
                            $consultar = "select *from tbserv";
                            $executar = mysqli_query($conn,$consultar);
            ?>
                            <div id="nav">
                                <a href="../user/adm.php"><img class="return" src="../img/retorno.png"/></a>
                                <h1><img class="ashion" src="../img/ashion.png"/></h1>
                                <br/><br/><br/><br/>
                                <center>
                                    <a href="cadserv.php"><img class="botao" src="../img/cad.png"/></a>
                                </center>
                            </div>

                            <div id="pushserv"></div>
                            
                            <!--<div id="pagservnav">-->
                                <br/><br/>
                                <div id="listar">
                                    <?php
                                        while($linha = mysqli_fetch_array($executar))
                                        {
                                    ?>
                                        <fieldset class="quests">
                                            <br/>
                                            <a href="specserv.php?id=<?php echo $linha["codserv"]; ?>"><?php echo $linha["serv"];?></a>
                                            <br/>
                                            <div class="border"></div>
                                            <br/>
                                            <?php
                                                if($linha["status"]==0)
                                                    echo "Em Aberto";
                                                else
                                                    echo "Concluído";
                                            ?>

                                            <?php
                                                if($linha["status"]==1){
                                            ?>
                                            <?php } ?>
                                            
                                            <br/><br/>
                                        </fieldset>
                                    <br/>
                                    <?php } ?>
                                </div>
                            <!--</div>-->
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
        </div>  
    </body>
</html>