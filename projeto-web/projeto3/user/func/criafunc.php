<html>
    <head>
        <title>Ashion's Guild - Cadastro de Funcionários</title>
        <meta charset="utf-8"/>
        <link rel="stylesheet" type="text/css" href="../../css/style.css"/>
        <link rel="shortcut icon" type="img/x-icon" href="../../img/logo.png"/>
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

                            $search = "select * from tbfunc";
                            $exe = mysqli_query($conn,$search);
                            while($checar = mysqli_fetch_array($exe)){
                                if($checar['login']==$_POST['cxlogin']){
                                    echo "<div id='push'></div><h3 class='alrt'>Login não disponível!<div class='border'></div></h3>";
                                    $verif=1;
                                }
                                if($verif!=1 and $checar['email']==$_POST['cxemail']){
                                    echo "<div id='push'></div><h3 class='alrt'>Email já está em uso!<div class='border'></div></h3>";
                                    $verif=1;
                                }
                            }

                            if($verif!=1){

                                echo "<br/><br/><br/>";
                                if($_POST['cxsenha'] == $_POST['cxconf']){

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

                                    $sql = "insert into tbfunc (nome, end, bairro, city, tel, cel, email, exp, form, login, senha, perfil, foto) 
                                    values ('$nome', '$end', '$bairro', '$city', '$tel', '$cel', '$email', '$exp', '$form', '$login', md5('$senha'), '$perfil', '$nomefoto')";
                                    $query = mysqli_query($conn,$sql);
                                    echo "<div id='push'></div><h3 class='alrt'>Funcionário cadastrado com sucesso!<div class='border'></div></h3>";
                                }
                                else{
                                    echo "<div id='push'></div><h3 class='alrt'>Senhas divergentes!<div class='border'></div></h3>";
                                }
                            }
                        }
                    }
                }
            else{
                echo("<div id='push'></div><h3 class='alrt'>Atenção: Área Restrita<div class='border'></div></h3>");
            ?>

                <script language="javascript" type="text/javascript">
                    if(window.location) window.location.href="../login/index.php";
                </script>

            <?php
                }
            ?>
            <br/>
            <a href="listafunc.php"><p><img class='botao' src='../../img/voltar.png'/></p></a>
        </div>
    </body>
</html>