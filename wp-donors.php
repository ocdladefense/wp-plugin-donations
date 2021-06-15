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

define('DONATION_START_DATE', '2020-01-01');
define('DONATION_END_DATE', '2021-06-14');

// var_dump(DONATION_START_DATE);
// exit;

// Referencing donors.php to return a formatted array
require_once(DONORS_PLUGIN_DIR . '/includes/donors-test.inc');
require_once(DONORS_PLUGIN_DIR . 'includes/custom/legislative.inc');
require_once(DONORS_PLUGIN_DIR . '/includes/records.inc');
require_once(DONORS_PLUGIN_DIR . '/includes/redirect.inc');

add_action('init', "add_donors_url");

add_filter('request', "donors_query_vars");

add_filter('template_include', "setting_donors_template");

add_filter('init', 'flush_rules');


// TESTING
//var_dump($donors);
//exit;
///////////////////