<?php
SESSION_START();
if($_SESSION["user"]){
?>

<h1>Você está no principal. Seja bem vindo </h1>
<a href="fimSession.php">Fim</a>
<?php
}
else{
echo("<strong> Atenção: Área Restrita");
?>
<script language="javascript" type="text/javascript">
    if(window.location) window.location.href="../login/index.php";
</script>
<?php
}
?>
