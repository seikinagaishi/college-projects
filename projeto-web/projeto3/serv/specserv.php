<html>
    <head>
        <meta charset="utf-8"/>
        <title>Ashion's Guild - Serviço</title>
        <link rel="shortcut icon" type="image/x-icon" href="../img/logo.png"/>
        <link rel="stylesheet" type="text/css" href="../css/style.css"/>
    </head>

    <body>
        <div id="pagservlivro">
            <?php
            
                error_reporting(0);
                SESSION_START();
                if($_SESSION["user"]){
                    include_once '../user/conexao.php';
                    $teste = mysqli_query($conn, "select login from tbfunc where perfil='Administrador'");
                    while($line = mysqli_fetch_array($teste)){

                        if($_SESSION["user"] == $line["login"]){
                        
                            $id=$_GET['id'];

                            $consultar = "select *from tbserv where codserv=$id";
                            $executar = mysqli_query($conn,$consultar);
            ?>

                                <br/><br/>
                                <div id="listarlivro">
                                    <?php
                                        while($linha = mysqli_fetch_array($executar))
                                        {
                                    ?>
                                        <img class="book" src="../img/livro_solo.png"/>
                                        <fieldset class="livro">
                                            <?php
                                                $test = mysqli_query($conn, "select *from tbcli where codcli='".$linha['nomecli']."'");
                                                $linu = mysqli_fetch_array($test);
                                            ?>
                                            Cliente<br/><input type="text" value="<?php echo $linu["nome"];?>" readonly ><br/><br/>
                                            <?php
                                                $test = mysqli_query($conn, "select *from tbfunc where codfunc='".$linha['nometec']."'");
                                                $linu = mysqli_fetch_array($test);
                                            ?>
                                            Técnico<br/><input type="text" value="<?php echo $linu["nome"];?>" readonly><br/><br/>


                                            Serviço<br/><input type="text" value="<?php echo $linha["serv"];?>" readonly><br/><br/>
                                            Data<br/><input type="date" value="<?php echo $linha["data"];?>" readonly><br/><br/>
                                            Hora<br/><input type="time" value="<?php echo $linha["hora"];?>" readonly><br/><br/>

                                            Status<br/>
                                            <input type="text" value="<?php
                                                if($linha["status"]==0)
                                                    echo "Em Aberto";
                                                else
                                                    echo "Concluído";
                                            ?>" readonly><br/><br/>

                                            <a href="editandoserv.php?id=<?php echo $linha["codserv"];?>"><img class="botao2" src="../img/edit.png"></a>
                                            <a href="delserv.php?id=<?php echo $linha["codserv"];?>"><img class="botao2" src="../img/remover.png"></a>
                                        </fieldset>
                                        <fieldset class="livro">
                                            <br/><br/>
                                            <?php
                                                if($linha["status"]==1){
                                            ?>
                                                    OBS<br/>
                                                    <textarea class="serv" readonly><?php echo $linha["obstec"] ?></textarea>
                                            <?php } ?>
                                        </fieldset>
                                    <br/>
                                    <?php } ?>
                                </div>
                            
                                            
                            <br/>

                            <a href="listaserv.php"><p><img class="botao3" src="../img/retorno.png"></p></a>
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