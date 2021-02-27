<html>
    <head>
        <title>Ashion's Guild - Alteração das Informações do Funcionário</title>
        <link rel="shortcut icon" type="image/x-icon" href="../../img/logo.png"/>
        <link rel="stylesheet" type="text/css" href="../../css/style.css"/>
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

                            $id = $_GET['id'];

                            $consulta = "select *from tbfunc where codfunc = '$id'";
                            $executar = mysqli_query($conn,$consulta);

                                while($exibir = mysqli_fetch_array($executar))
                                {
            ?>
                                    <br/>
                                    <form method="POST" action="editfunc.php" enctype="multipart/form-data">
                                        <fieldset class="card">
                                            <input type="hidden" name="codigo" value="<?php echo $exibir['codfunc'];?>">
                                            <table>
                                                <tr>
                                                    <th colspan="3"><input type="text" placeholder="Nome" name="cxnome" value="<?php echo $exibir['nome'];?>"></th>
                                                </tr>

                                                <tr>
                                                    <th colspan="3">
                                                        <select name="perfil">
                                                            <option>Tecnico</option>
                                                            <option>Administrador</option>
                                                        </select>
                                                    </th>
                                                </tr>
                                                
                                                <tr>
                                                    <td>Experiência:</td>
                                                    <th><input class="edt" type="text" placeholder="Experiência" name="cxexp" value="<?php echo $exibir['exp'];?>"></th>
                                                    <td rowspan="13"><img class="profpic" src="../../img/func/<?php echo $exibir["foto"]; ?>"/><br/></td>
                                                </tr>

                                                <tr>
                                                    <td>Formação:</td>
                                                    <th><input class="edt" type="text" placeholder="Formação" name="cxform" value="<?php echo $exibir['form'];?>"></th>
                                                </tr>

                                                <tr>
                                                    <td>Endereço:</td>
                                                    <th><input class="edt" type="text" placeholder="Endereço" name="cxend" value="<?php echo $exibir['end'];?>"></th>
                                                </tr>

                                                <tr>
                                                    <td>Bairro:</td>
                                                    <th><input class="edt" type="text" placeholder="Bairro" name="cxbairro" value="<?php echo $exibir['bairro'];?>"></th>
                                                </tr>

                                                <tr>
                                                    <td>Cidade:</td>
                                                    <th><input class="edt" type="text" placeholder="Cidade" name="cxcity" value="<?php echo $exibir['city'];?>"></th>
                                                </tr>

                                                <tr>
                                                    <td>Telefone:</td>
                                                    <th><input class="edt" type="number" placeholder="Telefone" name="cxtel" value="<?php echo $exibir['tel'];?>"></th>
                                                </tr>

                                                <tr>
                                                    <td>Celular:</td>
                                                    <th><input class="edt" type="number" placeholder="Celular" name="cxcel" value="<?php echo $exibir['cel'];?>"></th>
                                                </tr>
                                                
                                                <tr>
                                                    <td>Login:</td>
                                                    <th><input class="edt" type="text" placeholder="Login" name="cxlogin" value="<?php echo $exibir['login'];?>" <?php if($exibir['login']==$line['login']){ echo "readonly";} ?>></th>
                                                </tr>

                                                <tr>
                                                    <td>Email:</td>
                                                    <th><input class="edt" type="text" placeholder="Email" name="cxemail" value="<?php echo $exibir['email'];?>"></th>
                                                </tr>

                                                <tr>
                                                    <td>Alterar Foto</td>
                                                    <th><br/><input type="file" name="foto" accept="image/png, image/jpeg"></th>
                                                </tr>

                                                <tr><td></td></tr><tr><td></td></tr>

                                                <tr>
                                                    <td>Nova Senha:</td>
                                                    <th><input type="password" placeholder="Nova Senha"  name="cxsenha" value="<?php echo $exibir['senha'];?>"></th>
                                                </tr>
                                                
                                                <tr>
                                                    <td>Confirmar Senha:</td>
                                                    <th><input type="password" placeholder="Confirmar Senha"  name="cxconf" value="<?php echo $exibir['senha'];?>"></th>
                                                </tr>
                                            </table>

                                            <br/>
                                            <input class="editbt" type="submit" value="">
                                        </fieldset>
                                    </form>

                                    <a href="listafunc.php"><p><img class="botao" src="../../img/cancel.png"/></p></a>

                        <?php } ?>
                    
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