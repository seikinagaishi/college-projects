<html>
    <head>
        <meta charset="utf-8"/>
        <title>Ashion's Guild - Funcionários</title>
        <link rel="shortcut icon" type="image/x-icon" href="../../img/logo.png"/>
        <link rel="stylesheet" type="text/css" href="../../css/style.css"/>
    </head>

    <body>
        <div id="pagcli">
            <?php
                error_reporting(0);
                SESSION_START();
                if($_SESSION["user"]){
                    include_once '../conexao.php';
                    $teste = mysqli_query($conn, "select login from tbfunc where perfil='Administrador'");
                    while($line = mysqli_fetch_array($teste)){

                        if($_SESSION["user"] == $line["login"]){

                            $consultar = "select *from tbfunc";
                            $executar = mysqli_query($conn,$consultar);
            ?>
                            <div id="nav">
                                <a href="../adm.php"><img class="return" src="../../img/retorno.png"/></a>
                                <h1><img class="ashion" src="../../img/ashion.png"/></h1>
                                <br/><br/><br/><br/>
                                <center>
                                    <a href="cadfunc.php"><img class="botao" src="../../img/cad.png"/></a>
                                </center>
                            </div>

                            <div id="push"></div>
                            
                            <div id="paglist">
                                <br/><br/>
                                <div id="listar">

                                    <?php
                                        include_once '../conexao.php';
                                        $consultar = "select *from tbfunc";
                                        $executar = mysqli_query($conn,$consultar);
                                        while($linha = mysqli_fetch_array($executar))
                                        {
                                    ?> 
                                        <a href="specfunc.php?id=<?php echo $linha["codfunc"];?>">
                                            <fieldset class="noborder">
                                                <br/><h4><?php echo $linha["nome"];?></h4>
                                                <div class="border"></div><br/>
                                                <a href="specfunc.php?id=<?php echo $linha["codfunc"];?>"><img class="pict" src="../../img/func/<?php echo $linha["foto"]; ?>" alt="<?php echo $linha["nome"]; ?>"/></a><br/>
                                                <br/><h4><?php echo $linha["login"];?></h4><br/>
                                                <?php echo $linha["perfil"];?>
                                            </fieldset>
                                        </a>
                                    <?php } ?>
                                </div>
                            </div>
            <?php     
                        }
                    }
                }
                else{
                    echo("<h3 class='alrt'>Atenção: Área Restrita<div class='border'></div></h3>");
            ?>
                    <script language="javascript" type="text/javascript">
                        if(window.location) window.location.href="../login/index.php";
                    </script>
            <?php
                }
            ?>
        </div>
    </body>
</html>