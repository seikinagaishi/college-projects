<html>
    <head>
        <meta charset="utf-8"/>
        <link rel="stylesheet" type="text/css" href="../css/style.css"/>
        <link rel="shortcut icon" type="image/x-icon" href="../img/logo.png"/>
        <title>Ashion's Guild - Cadastro de Cliente</title>
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
            ?> 
                            <div id="minipush"></div>
                            <form method="POST" action="criacli.php" enctype="multipart/form-data">
                                <fieldset class="sheet">
                                    <h2>Cadastro de Cliente</h2>
                                    <div class="border"></div>
                                    <br/>
                                    
                                    <input type="text" name="cxnome" placeholder="Nome" required><br/><br/>
                                    <input type="text" name="cxcont" placeholder="Contato" required><br/><br/>
                                    <input type="text" name="cxend" placeholder="Endereço" required><br/><br/>
                                    <input type="number" name="cxfone" placeholder="Fone" required><br/><br/>
                                    <input type="text" name="cxemail" placeholder="E-Mail" required><br/><br/>
                                    <input type="text" name="cxramo" placeholder="Ramo" required><br/><br/>
                                    Foto<br/><br/>
                                    <input type="file" name="fotocli" accept="image/x-png, image/jpeg"><br/><br/>
                                    
                                    <input class="cadbt" type="submit" value="">
                                </fieldset>
                            
                            </form>

                            <a href="listacli.php"><p><img class="botao" src="../img/cancel.png"/></p></a>  

                    <?php
                        }
                    }
                }
                        else{
                            echo("<div id='push'></div><h3 class='alrt'>Atenção: Área Restrita<div class='border'></div></h3>");
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

