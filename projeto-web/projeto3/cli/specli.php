<html>
    <head>
        <meta charset="utf-8"/>
        <title>Ashion's Guild - Cliente</title>
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
                            
                            $id=$_GET['id'];

                            $consultar = "select *from tbcli where codcli=$id";
                            $executar = mysqli_query($conn,$consultar);
            ?>
                            <br/><br/><br/><br/>       
                            <aside>
                                <div id="listarlivro">
                                    <?php
                                        while($linha = mysqli_fetch_array($executar))
                                        {
                                    ?>
                                            <img class="book" src="../img/livro_solo.png"/>
                                            <fieldset  class="livro">
                                                <h2><?php echo $linha["nome"]?></h2>
                                                <div class="border"></div>
                                                <br/>
                                                <img class="clipic" src="../img/cli/<?php echo $linha["fotocli"]; ?>"/>
                                                <br/><br/>
                                                <a href="editandocli.php?id=<?php echo $linha["codcli"];?>"><img class="botao2" src="../img/edit.png"></a>
                                                <a href="delcli.php?id=<?php echo $linha["codcli"];?>"><img class="botao2" src="../img/remover.png"></a>
                                            </fieldset>

                                            <fieldset class="livro">
                                                <table>
                                                    <tr>
                                                        <td><p>Ramo<br/><input type="text" value="<?php echo $linha["ramo"];?>" readonly ></p></td>
                                                    </tr>
                                                    
                                                    <tr><td></td></tr>
                                                    <tr>
                                                        <td><p>Contato<br/><input type="text" value="<?php echo $linha["contato"];?>" readonly ></p></td>
                                                    </tr>

                                                    <tr>
                                                        <td><p>Endereço<br/><input type="text" value="<?php echo $linha["end"];?>" readonly></p></td>
                                                    </tr>

                                                    <tr>
                                                        <td><p>Telefone<br/><input type="number" value="<?php echo $linha["fone"];?>" readonly ></p></td>
                                                        
                                                    </tr>

                                                    <tr>
                                                        <td><p>E-Mail<br/><input type="text" value="<?php echo $linha["email"];?>" readonly ></p></td>
                                                    </tr>
                                                </table>
                                            </fieldset>
                                            <br/>
                                <?php } ?>
                                </div>
                            </aside>
                                
                            <br/>
                            
                            <a href="listacli.php"><p><img class="botao3" src="../img/retorno.png"></p></a>

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