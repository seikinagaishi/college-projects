<html>
    <head>
        <title>Ashion's Guild - Concluir Serviço</title>
        <link rel="shortcut icon" type="image/x-icon" href="../img/logo.png"/>
        <link rel="stylesheet" type="text/css" href="../css/style.css"/>
        <meta charset="utf-8"/>
    </head>

    <body>
        <div id="pagserv">
            <br/><br/><br/>
            <?php
                error_reporting(0);
                SESSION_START();
                include_once '../user/conexao.php';
                if($_SESSION["user"]){
                    $teste = mysqli_query($conn, "select *from tbfunc where perfil='Tecnico'");
                    while($line = mysqli_fetch_array($teste)){
                        if($_SESSION["user"] == $line["login"]){
                            $id = $_GET['id'];

                            $consulta = "select *from tbserv where codserv = '$id'";
                            $executar = mysqli_query($conn,$consulta);

                            echo "<div id='listar'>";
                            while($linha = mysqli_fetch_array($executar))
                            {
            ?>
                                <form method="POST" action="termserv.php">
                                    <fieldset class="client">
                                        <input type="hidden" name="codigo" value="<?php echo $linha['codserv'];?>">
                                        
                                        <?php
                                            $test = mysqli_query($conn, "select *from tbcli where codcli='".$linha['nomecli']."'");
                                            $linu = mysqli_fetch_array($test);
                                        ?>
                                        Cliente<br/><input type="text" value="<?php echo $linu["nome"];?>" readonly ><br/><br/>
                                        
                                        Serviço<br/><input type="text" value="<?php echo $linha["serv"];?>" readonly><br/><br/>
                                        Data<br/><input type="date" value="<?php echo $linha["data"];?>" readonly><br/><br/>
                                        Hora<br/><input type="time" value="<?php echo $linha["hora"];?>" readonly><br/><br/>

                                        <textarea name="cxobstec" placeholder="Observações"></textarea>
                                        <br/><br/>

                                        <input class="envbt" type="submit" value="">
                                    </fieldset>
                                    
                                    
                                </form>

                                <br/><br/>

                                

            <?php 
                            }
                                echo "</div>";
                                echo "<a href='telaserv.php'><p><img class='botao' src='../img/cancel.png'/></p></a>";
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