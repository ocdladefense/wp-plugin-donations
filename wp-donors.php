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
define('DONORS_PLUGIN_DIR', plugin_dir_path(__FILE__));

// Referencing donors.php to return a formatted array
require_once(DONORS_PLUGIN_DIR . '/includes/donors-test.inc');
require_once(DONORS_PLUGIN_DIR . 'includes/custom/legislative.inc');
require_once(DONORS_PLUGIN_DIR . '/includes/records.inc');


// TESTING
//var_dump($donors);
//exit;
///////////////////