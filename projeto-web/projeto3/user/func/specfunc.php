<html>
    <head>
        <title>Ashion's Guild - Funcionário</title>
        <meta charset="utf-8"/>
        <link rel="stylesheet" type="text/css" href="../../css/style.css"/>
        <link rel="shortcut icon" type="image/x-icon" href="../../img/logo.png"/>
    </head>

    <body>
        <div id="pagmemb">
            <?php
                error_reporting(0);
                SESSION_START();
                if($_SESSION["user"]){
                    include_once '../conexao.php';
                    $teste = mysqli_query($conn, "select login from tbfunc where perfil='Administrador'");
                    while($line = mysqli_fetch_array($teste)){

                        if($_SESSION["user"] == $line["login"]){
            ?>
                            <div id="push"></div>
                                <div id="listar">
                                <?php
                                    include_once '../conexao.php';
                                    $id = $_GET['id'];
                                    $consultar = "select *from tbfunc where codfunc='$id'";
                                    $executar = mysqli_query($conn,$consultar);
                                    while($linha = mysqli_fetch_array($executar)){
                                ?> 
                                    <fieldset class="card">
                                        <table class="pscard">
                                            <tr>
                                                <th class="titulo" colspan="3"><?php echo $linha["nome"];?></th>
                                            </tr>

                                            <tr>
                                                <th class="titulo" colspan="3"><?php echo $linha["perfil"];?></th>
                                            </tr>

                                            <tr>
                                                <td>Login:</td>
                                                <th><?php echo $linha["login"];?></th>
                                                <th rowspan="9"><img class="pict2" src="../../img/func/<?php echo $linha["foto"]; ?>"/><br/></th>

                                            </tr>

                                            <tr>
                                                <td>Experiência:</td>
                                                <th><?php echo $linha["exp"];?></th>
                                            </tr>

                                            <tr>
                                                <td>Formação:</td>
                                                <th><?php echo $linha["form"];?></th>
                                            </tr>

                                            <tr>
                                                <td>Endereço:</td>
                                                <th><?php echo $linha["end"];?></th>
                                            </tr>

                                            <tr>
                                                <td>Bairro:</td>
                                                <th><?php echo $linha["bairro"];?></th>
                                            </tr>

                                            <tr>
                                                <td>Cidade:</td>
                                                <th><?php echo $linha["city"];?></th>
                                            </tr>

                                            <tr>
                                                <td>Email:</td>
                                                <th><?php echo $linha["email"];?></th>
                                            </tr>
                                            
                                            <tr>
                                                <td>Telefone:</td>
                                                <th><?php echo $linha["tel"];?></th>
                                            </tr>

                                            <tr>
                                                <td>Celular:</td>
                                                <th><?php echo $linha["cel"];?></th>
                                            </tr>
                                        </table>
                                        <br/>
                                        <a href="editandofunc.php?id=<?php echo $linha["codfunc"];?>"><img class="botao2" src="../../img/edit.png"></a>
                                        <?php if($linha['login']!=$line['login']){ ?>
                                            <a href="delfunc.php?id=<?php echo $linha["codfunc"];?>"><img class="botao2" src="../../img/remover.png"></a>
                                        <?php } ?>
                                    </fieldset>
                                    <br/><br/>
                <?php 
                                    } 
                            echo "</div>";
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
            <br/>
            <a href="listafunc.php"><p><img class="botao" src="../../img/voltar.png"></p></a>
        </div>
    </body>
</html>
