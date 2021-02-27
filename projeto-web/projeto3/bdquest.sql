-- phpMyAdmin SQL Dump
-- version 4.8.5
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1:3306
-- Generation Time: 03-Dez-2019 às 16:29
-- Versão do servidor: 5.7.26
-- versão do PHP: 7.2.18

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `bdquest`
--

-- --------------------------------------------------------

--
-- Estrutura da tabela `tbcli`
--

DROP TABLE IF EXISTS `tbcli`;
CREATE TABLE IF NOT EXISTS `tbcli` (
  `codcli` int(11) NOT NULL AUTO_INCREMENT,
  `nome` varchar(40) NOT NULL,
  `contato` varchar(30) NOT NULL,
  `end` varchar(50) NOT NULL,
  `fone` int(16) NOT NULL,
  `email` varchar(50) NOT NULL,
  `ramo` varchar(30) NOT NULL,
  `fotocli` varchar(100) NOT NULL,
  PRIMARY KEY (`codcli`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=latin1;

--
-- Extraindo dados da tabela `tbcli`
--

INSERT INTO `tbcli` (`codcli`, `nome`, `contato`, `end`, `fone`, `email`, `ramo`, `fotocli`) VALUES
(2, 'IF', 'Joel', 'Rua Salgado Filho', 190, 'ifspguarulhos@ifsp.edu.br', 'Instituto Federal', 'aabebee0783b2b69ca4cd049f755e171.jpg'),
(3, 'Artesanatos do Bob', 'Bob EspinhaÃ§o', 'Alameda de IkenWald', 321986, 'keiko@rocfrith.ash', 'Artesanato', 'a635e12dfbdb492d931a00a8b8c78c13.jpg'),
(4, 'A Muralha de IkenWald', 'General Tulius', 'IkenWald', 487451, 'jaldabaoth@rocfrith.ash', 'ProteÃ§Ã£o', 'ce2ff59da646d9d89b4af122b39de972.jpg'),
(5, 'Catedral de Mikael', 'Bispo Benedictus', 'Parque Celestial', 878541, 'ansiel@rocfrith.ash', 'ReligiÃ£o', '8921832a6cded00ae359d181ffc489eb.jpg');

-- --------------------------------------------------------

--
-- Estrutura da tabela `tbfunc`
--

DROP TABLE IF EXISTS `tbfunc`;
CREATE TABLE IF NOT EXISTS `tbfunc` (
  `codfunc` int(11) NOT NULL AUTO_INCREMENT,
  `nome` varchar(50) NOT NULL,
  `end` varchar(90) NOT NULL,
  `bairro` varchar(50) NOT NULL,
  `city` varchar(50) NOT NULL,
  `tel` varchar(16) NOT NULL,
  `cel` varchar(16) NOT NULL,
  `email` varchar(90) NOT NULL,
  `exp` varchar(50) NOT NULL,
  `form` varchar(50) NOT NULL,
  `login` varchar(50) NOT NULL,
  `senha` varchar(50) NOT NULL,
  `perfil` varchar(50) NOT NULL,
  `foto` varchar(50) NOT NULL,
  PRIMARY KEY (`codfunc`)
) ENGINE=InnoDB AUTO_INCREMENT=21 DEFAULT CHARSET=latin1;

--
-- Extraindo dados da tabela `tbfunc`
--

INSERT INTO `tbfunc` (`codfunc`, `nome`, `end`, `bairro`, `city`, `tel`, `cel`, `email`, `exp`, `form`, `login`, `senha`, `perfil`, `foto`) VALUES
(11, 'Ryan De\'Thulsa', 'Hyjal', 'Vale de Hyjal', 'IkenWald', '674844', '8565', 'aidan@rocfrith.ash', 'CaÃ§ador de Ciclope', 'Espadachim', 'ryandt', '202cb962ac59075b964b07152d234b70', 'Tecnico', 'b0f182adc9f434cd80d4e657849ead10.jpg'),
(12, 'Ga-Cius', 'Hall de Ashion', 'Cidadela Alva', 'IkenWald', '355197', '6546', 'khalahan@rockfrit.ash', 'GuardiÃ£o de IkenWald', 'Paladino', 'gacius', '202cb962ac59075b964b07152d234b70', 'Tecnico', 'e11b711790d53cb69ffcf1ef68df8d53.jpg'),
(14, 'Thalgor', 'Hall de Ashion', 'Cidadela Alva', 'IkenWald', '654678', '2782', 'torcus@rockfrit.ash', 'Lorde de Ashion', 'Guerreiro', 'admin', '202cb962ac59075b964b07152d234b70', 'Administrador', 'eafccd0ff541a47eeb78b3a5a9e8a101.jpg');

-- --------------------------------------------------------

--
-- Estrutura da tabela `tbserv`
--

DROP TABLE IF EXISTS `tbserv`;
CREATE TABLE IF NOT EXISTS `tbserv` (
  `codserv` int(11) NOT NULL AUTO_INCREMENT,
  `nomecli` int(11) NOT NULL,
  `nometec` int(11) NOT NULL,
  `serv` varchar(90) NOT NULL,
  `data` date NOT NULL,
  `hora` time NOT NULL,
  `status` int(1) NOT NULL,
  `obstec` varchar(5000) NOT NULL,
  PRIMARY KEY (`codserv`),
  KEY `fk1_codfunc` (`nometec`),
  KEY `fk1_codcli` (`nomecli`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=latin1;

--
-- Extraindo dados da tabela `tbserv`
--

INSERT INTO `tbserv` (`codserv`, `nomecli`, `nometec`, `serv`, `data`, `hora`, `status`, `obstec`) VALUES
(6, 3, 11, 'Coletar dedos de Ciclope para o Bob', '2019-12-25', '13:01:00', 1, 'Os ciclopes estavam criando um acampamento muito perto da cidade, devido a isso foi muito fÃ¡cil coletar 20 dedos ao preÃ§o do meu braÃ§o. Venho aqui fazer um pedido de aposentadoria.\r\n_________________\r\n\r\nItens Adquiridos\r\n\r\n20 dedos de ciclope\r\n1 Clava Gigante\r\n1 BraÃ§o Humano');

--
-- Constraints for dumped tables
--

--
-- Limitadores para a tabela `tbserv`
--
ALTER TABLE `tbserv`
  ADD CONSTRAINT `fk1_codcli` FOREIGN KEY (`nomecli`) REFERENCES `tbcli` (`codcli`),
  ADD CONSTRAINT `fk1_codfunc` FOREIGN KEY (`nometec`) REFERENCES `tbfunc` (`codfunc`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
