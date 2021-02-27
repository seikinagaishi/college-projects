-- phpMyAdmin SQL Dump
-- version 4.8.5
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1:3306
-- Generation Time: 21-Out-2019 às 14:50
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
-- Database: `bdagenda`
--

-- --------------------------------------------------------

--
-- Estrutura da tabela `tbsites`
--

DROP TABLE IF EXISTS `tbsites`;
CREATE TABLE IF NOT EXISTS `tbsites` (
  `codigo` int(11) NOT NULL AUTO_INCREMENT,
  `nome` varchar(90) NOT NULL,
  `endereco` varchar(450) NOT NULL,
  `descricao` varchar(900) NOT NULL,
  PRIMARY KEY (`codigo`)
) ENGINE=InnoDB AUTO_INCREMENT=15 DEFAULT CHARSET=latin1;

--
-- Extraindo dados da tabela `tbsites`
--

INSERT INTO `tbsites` (`codigo`, `nome`, `endereco`, `descricao`) VALUES
(1, 'Steam', 'https://store.steampowered.com', 'A Steam Ã© uma plataforma digital desenvolvida pela Valve Corporation. Com ela, Ã© possÃ­vel ter a sua biblioteca virtual de jogos e ferramentas, sendo beneficiado com seu banco de dados, diversos sistemas, atualizaÃ§Ãµes automÃ¡ticas e muito mais!'),
(3, 'Baidu', 'index.php', 'Atualmente, Baidu Ã© uma das ferramentas de pesquisa mais utilizadas no mundo, substituindo a Google em paÃ­ses como a RepÃºblica Popular da China.'),
(5, 'IFSP Guarulhos', 'https://portal.ifspguarulhos.edu.br', 'Instituto Federal de SÃ£o Paulo - Campus Guarulhos'),
(6, 'YouTube', 'https://www.youtube.com', 'Aproveite vÃ­deos e mÃºsicas que vocÃª ama, envie conteÃºdo original e compartilhe-o com amigos, parentes e o mundo no YouTube.'),
(11, 'Facebook', 'https://www.facebook.com', 'Uma das redes sociais mais utilizadas no mundo.'),
(12, 'Google', 'https://www.google.com', 'Google LLC Ã© uma empresa multinacional de serviÃ§os online e software dos Estados Unidos. O Google hospeda e desenvolve uma sÃ©rie de serviÃ§os e produtos baseados na internet.'),
(14, 'Projeto DWE', 'https://seikinagaishi.github.io', 'Projeto de Desenvolvimento Web.');
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
