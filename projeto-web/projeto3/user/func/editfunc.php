<html>
    <head>
        <title>Ashion's Guild - Alteração das Informações do Funcionário</title>
        <meta charset="utf-8"/>
        <link rel="stylesheet" type="text/css" href="../../css/style.css"/>
        <link rel="shortcut icon" type="img/x-icon" href="../../img/logo.png"/>
    </head>
    
    <body>
        <div id="pagmemb">
            <div id="push"></div>
                <?php
                    error_reporting(0);
                    SESSION_START();
                    if($_SESSION["user"]){
                        include_once '../conexao.php';
                        $teste = mysqli_query($conn, "select login from tbfunc where perfil='Administrador'");
                        while($line = mysqli_fetch_array($teste)){

                            if($_SESSION["user"] == $line["login"]){

                                $search = "select * from tbfunc where codfunc !='".$_POST['codigo']."'";
                                $exe = mysqli_query($conn,$search);
                                while($checar = mysqli_fetch_array($exe)){
                                    if($checar['login']==$_POST['cxlogin']){
                                        echo "<h3 class='alrt'>Login não disponível!<div class='border'></div></h3>";
                                        echo "<br>";
                                        echo "<a href='listafunc.php'><p><img class='botao' src='../../img/voltar.png'/></p></a>";
                                        $verif=1;
                                    }
                                    if($verif!=1 and $checar['email']==$_POST['cxemail']){
                                        echo "<h3 class='alrt'>Email já está em uso!<div class='border'></div></h3>";
                                        echo "<br>";
                                        echo "<a href='listafunc.php'><p><img class='botao' src='../../img/voltar.png'/></p></a>";
                                        $verif=1;
                                    }
                                }

                                if($verif!=1){

                                    if($_POST['cxsenha'] == $_POST['cxconf']){
                                        $id = $_POST['codigo'];
                                        $nome = $_POST['cxnome'];
                                        $end = $_POST['cxend'];
                                        $bairro = $_POST['cxbairro'];
                                        $city = $_POST['cxcity'];
                                        $tel = $_POST['cxtel'];
                                        $cel = $_POST['cxcel'];
                                        $email = $_POST['cxemail'];
                                        $exp = $_POST['cxexp'];
                                        $form = $_POST['cxform'];

                                        $login = $_POST['cxlogin'];
                                        $senha = $_POST['cxsenha'];

                                        $perfil = $_POST['perfil'];

                                        if(isset($_FILES['foto'])){
                                            $ext = strtolower(substr($_FILES['foto']['name'], -4));
                                            $nomefoto=md5(time()).$ext;
                                            $dir="../../img/func/";

                                            move_uploaded_file($_FILES['foto']['tmp_name'], $dir.$nomefoto);
                                        }

                                        $alterar = "UPDATE tbfunc SET 
                                        nome = '$nome', 
                                        end = '$end',
                                        bairro = '$bairro',
                                        city = '$city',
                                        tel = '$tel',
                                        cel = '$cel',
                                        email = '$email',
                                        exp = '$exp',
                                        form = '$form',
                                        
                                        login = '$login',
                                        senha = md5('$senha'),
                                        
                                        perfil = '$perfil',
                                        foto= '$nomefoto'
                                        
                                        where codfunc = '$id'";

                                        $executar = mysqli_query($conn,$alterar);
                                        echo "<br/><br/><br/>";
                                        if($executar)
                                        {
                                            echo "<h3 class='alrt'>Informações do funcionário alteradas com sucesso!<div class='border'></div></h3>";
                                            echo "<br>";
                                            echo "<a href='listafunc.php'><p><img class='botao' src='../../img/voltar.png'/></p></a>";
                                        }
                                        else
                                        {
                                            echo "<h3 class='alrt'>Erro ao tentar alterar informações do funcionário!<div class='border'></h3>";
                                            echo "<br>";
                                            echo "<a href='listafunc.php'><p><img class='botao' src='../../img/voltar.png'/></p></a>";
                                        }
                                    
                                    } else{
                                        echo "<h3 class='alrt'>Senhas divergentes!<div class='border'></div></h3>";
                                        echo "<br>";
                                        echo "<a href='listafunc.php'><p><img class='botao' src='../../img/voltar.png'/></p></a>";
                                    }
                                }

                ?>

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