<html>
    <head>
        <meta charset="utf-8"/>
        <link rel="shortcut icon" type="image/x-icon" href="img/baidu.png"/>
        <link rel="stylesheet" type="text/css" href="css/style.css"/>
        <link href="https://fonts.googleapis.com/css?family=Gudea&display=swap" rel="stylesheet">
        <title>Baidu</title>
    </head>

    <body>
        <?php
            include_once 'adm/conexao.php';
        
            $nome = $_POST["busca"] ;   
        
            /*$consultar = "select *from tbsites where nome LIKE '%$nome%' ";*/
        
            /*OBS SQL: 
            use bdagenda;
            ALTER TABLE tbsite ADD FULLTEXT(nome, descricao);
            */
            $consultar = "SELECT *FROM tbsites WHERE MATCH(nome,descricao) AGAINST('$nome') or nome LIKE '%$nome%' or descricao LIKE '%$nome%'"; 

            $executar = mysqli_query($conn,$consultar);
            
            $resultado = mysqli_num_rows($executar);
            /*
            if($resultado!=0){
                echo"<script>
                    alert('$resultado pesquisas encontradas!');
                </script>";
            }
            else{
                echo "<script>
                    alert('Nenhum site encontrado!');
                    window.location.href='index.php';
                </script>";
                

            }
            */
        ?>
        
        <br/>
        
        <form method="POST" action="pesquisa.php">
            <div class="caixao2">
                <a href="index.php"><img class="baidusearch" src="img/baidusrc.png" title="Baidu Search" alt="Baidu Search"/></a>
                <div class="cx12">
                    <p class="lupicon">✎</p>
                    <input class="cxbusca" name="busca" type="text"/>
                </div>
                <div class="cx22">
                    <button type="submit" class="btn-buscar">➤</button>
                </div>
            </div>
        </form>
        
        
        <br/><br/><br/><br/><br/>
        <hr/>
        <div id="pesq">
        <?php
            if($resultado>1)
                echo "<span class='wsdesc'>".$resultado." resultados</span>";
            else if($resultado==1)
                echo "<span class='wsdesc'>".$resultado." resultado</span>";
            else
                echo "<br/><br/>
                        Sua pesquisa - <strong>".$nome."</strong> - não encontrou nenhum documento correspondente.
                        <br/><br/>
                        Sugestões:
                        <br/><br/>
                        • Certifique-se de que todas as palavras estejam escritas corretamente.<br/>
                        • Tente palavras-chave diferentes.<br/>
                        • Tente palavras-chave mais genéricas.";
        ?>
        
        <br/><br/><br/>
        
            <?php
                while($linha = mysqli_fetch_array($executar)){
                    echo "<a href='".$linha['endereco']."'><span class='wsnome'>".$linha['nome']."</span></a><br/>"."<span class='wsad'>".$linha['endereco']."</span><br/>"."<span class='wsdesc'>".$linha['descricao']."</span><br/><br/><br/>";
                } 
            ?>
        </div>
    </body>
</html>