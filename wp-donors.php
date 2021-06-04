<?php

/**
 * @package DonorsPlugin
 */
/*
Plugin Name: Donors Plugin
Plugin URI: 
Description: This is a plugin that retrieves and displays information about OCDLA donors and their donations.
Version: 1.0.0
Author: Ruslan Kalashnikov
Author URI: https://www.ocdla.org/
License: GPLv2 or later
Text Domain: wp-donors-plugin
*/

// If this file is accessed directly, abort.
defined('ABSPATH') or die('You shall not pass!');

// Setting a CONSTANT for the plugin dir path
define('MY_PLUGIN_DIR', plugin_dir_path(__FILE__));

// Referencing donors.php to return a formatted array
//require_once(ABSPATH . 'wp-content/plugins/wp-donors/includes/donors-array.inc');
require_once(ABSPATH . 'wp-content/plugins/wp-donors/includes/donors-test.inc');
require_once(ABSPATH . 'wp-content/plugins/wp-donors/includes/records.inc');

// TESTING
require_once(ABSPATH . 'wp-content/plugins/wp-donors/includes/custom/legislative.inc');
/////////////////

//require_once(MY_PLUGIN_DIR . '/includes/donors-array.inc');
//require_once(MY_PLUGIN_DIR . '/includes/records.inc');
require_once(ABSPATH . 'wp-content/plugins/wp-salesforce/wp-salesforce.php');

$donors = get_legislative_fund(44.00); //get_donors_test_array(); //get_donors_array();

// TESTING
//var_dump($donors);
//exit;
///////////////////