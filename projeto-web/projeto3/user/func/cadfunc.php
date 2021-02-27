<html>
    <head>
        <meta charset="utf-8"/>
        <link rel="stylesheet" type="text/css" href="../../css/style.css"/>
        <link rel="shortcut icon" type="image/x-icon" href="../../img/logo.png"/>
        <title>Ashion's Guild - Cadastro de Funcionários</title>
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
                            <div id="minipush"></div>
                            <form method="POST" action="criafunc.php" enctype="multipart/form-data">
                                <fieldset class="card">
                                    <table>
                                        <tr>
                                            <th><input type="text" placeholder="Nome" name="cxnome""></th>
                                        </tr>
                                        
                                        <tr>
                                            <th><br/><br/><input class="edt" type="text" placeholder="Endereço" name="cxend"></th>
                                        </tr>

                                        <tr>
                                            <th><input class="edt" type="text" placeholder="Bairro" name="cxbairro"></th>
                                        </tr>

                                        <tr>
                                            <th><input class="edt" type="text" placeholder="Cidade" name="cxcity"></th>
                                        </tr>

                                        <tr>
                                            <th><input class="edt" type="number" placeholder="Telefone" name="cxtel"></th>
                                        </tr>

                                        <tr>
                                            <th><input class="edt" type="number" placeholder="Celular" name="cxcel"></th>
                                        </tr>

                                        <tr>
                                            <th><input class="edt" type="text" placeholder="Email" name="cxemail"></th>
                                        </tr>

                                        <tr>
                                            <th><input class="edt" type="text" placeholder="Experiência" name="cxexp"></th>
                                        </tr>

                                        <tr>
                                            <th><input class="edt" type="text" placeholder="Formação" name="cxform"></th>
                                        </tr>
                                        
                                        <tr>
                                            <th><input class="edt" type="text" placeholder="Login" name="cxlogin"></th>
                                        </tr>

                                        <tr><td></td></tr><tr><td></td></tr>

                                        <tr>
                                            <th><input type="password" placeholder="Nova Senha"  name="cxsenha"></th>
                                        </tr>
                                        
                                        <tr>
                                            <th><input type="password" placeholder="Confirmar Senha"  name="cxconf"></th>
                                        </tr>

                                        <tr>
                                            <th><br/><p>Foto</p><input type="file" name="foto" accept="image/png, image/jpeg"></th>
                                        </tr>

                                        <tr>
                                            <th colspan="3">
                                                <select name="perfil">
                                                    <option>Tecnico</option>
                                                    <option>Administrador</option>
                                                </select>
                                            </th>
                                        </tr>
                                    </table>
                                    
                                    <input class="cadbt" type="submit" value="">
                                </fieldset>
                            </form>     
                            <a href="listafunc.php"><p><img class="botao" src="../../img/cancel.png"/></p></a>

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

