<html>
    <head>
        <title>Ashion's Guild - Alteração das Informações do Serviço</title>
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
                if($_SESSION["user"]){
                    include_once '../user/conexao.php';
                    $test = mysqli_query($conn, "select login from tbfunc where perfil='Administrador'");
                    while($linu = mysqli_fetch_array($test)){

                        if($_SESSION["user"] == $linu["login"]){

                            $id = $_GET['id'];

                            $consulta = "select *from tbserv where codserv = '$id'";
                            $executar = mysqli_query($conn,$consulta);

                            while($exibir = mysqli_fetch_array($executar))
                            {
            ?>
                                <form method="POST" action="editserv.php">
                                    <fieldset class="sheet">

                                        <input type="hidden" name="codigo" value="<?php echo $exibir['codserv'];?>">
                                        
                                        <?php
                                            $consul = "select *from tbcli";
                                            $execute = mysqli_query($conn,$consul);
                                        ?>       
                                        
                                        <br/><br/>
                                        
                                        Cliente<br/>
                                        <select name="cxcli">

                                            <?php 
                                                while($line = mysqli_fetch_array($execute)){ 
                                            ?>
                                                    <option value=" <?php echo $line["codcli"] ?> "> <?php echo $line["nome"] ?> </option>
                                            <?php } ?>

                                        </select>
                                        
                                        <br/><br/>
                                        
                                        <?php
                                            $consul = "select *from tbfunc";
                                            $execute = mysqli_query($conn,$consul);
                                        ?> 
                                        
                                        Técnico<br/>
                                        <select name="cxtec">
                                            <?php 
                                                while($line = mysqli_fetch_array($execute)){ 
                                            ?>
                                                    <option value=" <?php echo $line["codfunc"] ?> "> <?php echo $line["nome"] ?> </option>
                                            <?php } ?>
                                        </select>

                                        <br/><br/>

                                        Serviço<br/><input type="text" name="cxserv" value="<?php echo $exibir['serv'];?>"><br/><br/>
                                        Data<br/><input type="date" name="data" value="<?php echo $exibir['data'];?>"><br/><br/>
                                        Hora<br/><input type="time" name="hora" value="<?php echo $exibir['hora'];?>"><br/><br/>

                                        <input class="editbt" type="submit" value="">
                                    </fieldset>
                                </form>
                                <a href="listaserv.php"><p><img class="botao" src="../img/cancel.png"/></p></a>
            <?php 
                            }
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