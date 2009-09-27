-- phpMyAdmin SQL Dump
-- version 2.11.0
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Jul 30, 2008 at 11:24 AM
-- Server version: 5.0.45
-- PHP Version: 5.2.5

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";

--
-- Database: `time_management`
--

-- --------------------------------------------------------

--
-- Table structure for table `contracts`
--

DROP TABLE IF EXISTS `contracts`;
CREATE TABLE IF NOT EXISTS `contracts` (
  `id` int(11) NOT NULL auto_increment,
  `week_starts` int(11) NOT NULL,
  `day_limit` float NOT NULL,
  `week_limit` float NOT NULL,
  `multiplier` float NOT NULL,
  `default` tinyint(1) NOT NULL default '0',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=2 ;

--
-- Dumping data for table `contracts`
--

INSERT INTO `contracts` (`id`, `week_starts`, `day_limit`, `week_limit`, `multiplier`, `default`) VALUES
(1, 0, 12, 40, 1.5, 1);

-- --------------------------------------------------------

--
-- Table structure for table `employees`
--

DROP TABLE IF EXISTS `employees`;
CREATE TABLE IF NOT EXISTS `employees` (
  `emp_id` int(11) NOT NULL auto_increment,
  `emp_name` text character set utf8 collate utf8_unicode_ci NOT NULL,
  `emp_ssn` text character set utf8 collate utf8_unicode_ci NOT NULL,
  `contract_id` int(11) NOT NULL default '0',
  `emp_comment` text character set utf8 collate utf8_unicode_ci NOT NULL,
  `photo` longblob NOT NULL,
  PRIMARY KEY  (`emp_id`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

--
-- Dumping data for table `employees`
--


-- --------------------------------------------------------

--
-- Table structure for table `emp_jobs`
--

DROP TABLE IF EXISTS `emp_jobs`;
CREATE TABLE IF NOT EXISTS `emp_jobs` (
  `id` int(11) NOT NULL auto_increment,
  `emp_id` int(11) NOT NULL,
  `job_id` int(11) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

--
-- Dumping data for table `emp_jobs`
--


-- --------------------------------------------------------

--
-- Table structure for table `jobs`
--

DROP TABLE IF EXISTS `jobs`;
CREATE TABLE IF NOT EXISTS `jobs` (
  `job_id` int(11) NOT NULL auto_increment,
  `job_title` text character set utf8 collate utf8_unicode_ci NOT NULL,
  `job_wage` double NOT NULL,
  `job_description` text character set utf8 collate utf8_unicode_ci NOT NULL,
  PRIMARY KEY  (`job_id`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

--
-- Dumping data for table `jobs`
--


-- --------------------------------------------------------

--
-- Table structure for table `time`
--

DROP TABLE IF EXISTS `time`;
CREATE TABLE IF NOT EXISTS `time` (
  `time_id` int(11) NOT NULL auto_increment,
  `time_emp_id` int(11) NOT NULL,
  `time_time` datetime NOT NULL,
  `time_job_id` int(11) NOT NULL,
  `time_edited` tinyint(1) NOT NULL default '0',
  PRIMARY KEY  (`time_id`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

--
-- Dumping data for table `time`
--