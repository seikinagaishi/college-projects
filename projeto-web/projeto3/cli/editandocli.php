<html>
    <head>
        <title>Ashion's Guild - Alterando Informações do Cliente</title>
        <meta charset="utf-8"/>
        <link rel="shortcut icon" type="image/x-icon" href="../img/logo.png"/>
        <link rel="stylesheet" type="text/css" href="../css/style.css"/>
    </head>

    <body>
        <div id="pagcli">
            <br/><br/><br/><br/> 
            <?php
                error_reporting(0);
                SESSION_START();
                if($_SESSION["user"]){
                    include_once '../user/conexao.php';
                    $teste = mysqli_query($conn, "select login from tbfunc where perfil='Administrador'");
                    while($line = mysqli_fetch_array($teste)){

                        if($_SESSION["user"] == $line["login"]){

                            $id = $_GET['id'];

                            $consulta = "select *from tbcli where codcli = '$id'";
                            $executar = mysqli_query($conn,$consulta);
            ?>
            <?php
                                while($exibir = mysqli_fetch_array($executar))
                                {
            ?>
                                        <img class="book" src="../img/livro_solo.png"/>
                                        <form id="listarlivro" method="POST" action="editcli.php" enctype="multipart/form-data">
                                            <fieldset class="livro">
                                                <br/>
                                                <input type="hidden" name="codigo" value="<?php echo $exibir['codcli'];?>">

                                                <h2><input type="text" name="cxnome" value="<?php echo $exibir["nome"];?>"></h2>
                                                <br/>

                                                <img class="clipic" src="../img/cli/<?php echo $exibir["fotocli"]; ?>"/>

                                                <br/><br/>
                                                <input class="editbt" type="submit" value="">
                                            </fieldset>

                                            <fieldset class="livro">
                                                <table>
                                                    <tr>
                                                        <td><p>Ramo<br/><input type="text" name="cxramo" value="<?php echo $exibir["ramo"];?>"></p></td>
                                                    </tr>

                                                    <tr>
                                                        <td><p>Contato<br/><input type="text" name="cxcont" value="<?php echo $exibir["contato"];?>"></p></td>
                                                    </tr>

                                                    <tr>
                                                        <td><p>Endereço<br/><input type="text" name="cxend" value="<?php echo $exibir["end"];?>"></p></td>
                                                    </tr>

                                                    <tr>
                                                        <td><p>Telefone<br/><input type="number" name="cxfone" value="<?php echo $exibir["fone"];?>"></p></td>
                                                        
                                                    </tr>

                                                    <tr>
                                                        <td><p>E-Mail<br/><input type="text" name="cxemail" value="<?php echo $exibir["email"];?>"></p></td>
                                                    </tr>

                                                    <tr>
                                                        <td><br/><p>Alterar Foto<br/><input type="file" name="fotocli" accept="image/x-png, image/jpeg"><p></td>
                                                    </tr>
                                                </table>
                                            </fieldset>    
                                    </form>
                                <a href="listacli.php"><p><img class="botao3" src="../img/retorno.png"/></p></a>
                        <?php } ?>
                        
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