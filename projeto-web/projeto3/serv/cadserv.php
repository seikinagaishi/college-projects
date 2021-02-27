<html>
    <head>
        <meta charset="utf-8"/>
        <link rel="stylesheet" type="text/css" href="../css/style.css"/>
        <link rel="shortcut icon" type="image/x-icon" href="../img/logo.png"/>
        <title>Ashion's Guild - Cadastro de Serviços</title>
    </head>

    <body>
        <div id="pagserv">
            <?php
                error_reporting(0);
                SESSION_START();
                if($_SESSION["user"]){
                    include_once '../user/conexao.php';
                    $teste = mysqli_query($conn, "select login from tbfunc where perfil='Administrador'");
                    while($line = mysqli_fetch_array($teste)){
            
                        if($_SESSION["user"] == $line["login"]){

                            $consultar = "select *from tbcli";
                            $executar = mysqli_query($conn,$consultar);
            ?>
                            
                            <br/><br/><br/>
                            
                            <form method="POST" action="criaserv.php">
                            
                                <fieldset class="sheet">
                                    <br/>
                                    <h2>Cadastro de Serviços</h2>
                                    <div class="border"></div>
                                    <br/>
                                    
                                    
                                    Cliente<br/>
                                    <select name="cxcli">
                                        <?php while($linha = mysqli_fetch_array($executar)){ ?>
                                            <option value="<?php echo $linha["codcli"] ?>"> <?php echo $linha["nome"] ?> </option>
                                        <?php } ?>
                                    </select>
                                    
                                    <br/><br/>
                                    <?php 
                                        $consultar = "select *from tbfunc";
                                        $executar = mysqli_query($conn,$consultar);
                                    ?>
                                    
                                    Técnico<br/>
                                    <select name="cxtec">
                                        <?php while($linha = mysqli_fetch_array($executar)){ ?>
                                            <option value="<?php echo $linha["codfunc"] ?>"> <?php echo $linha["nome"] ?> </option>
                                        <?php } ?>
                                    </select>
                                    <br/><br/>
                                    
                                    <input type="text" name="cxserv" placeholder="Serviço" required><br/><br/>
                                    <input type="date" name="data" required><br/><br/>
                                    <input type="time" name="hora" required><br/><br/>
                                    
                                    
                                    <br/>
                                    <input class="cadbt" type="submit" value="">
                                    <br/><br/>
                                    
                                </fieldset>
                            
                            </form>

                            <br/><br/>
                            
                            <a href="listaserv.php"><p><img class="botao" src="../img/cancel.png"/></p></a>

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