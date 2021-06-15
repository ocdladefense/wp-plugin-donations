<?php

function add_donors_url()
{
    //may not be able to use compound paths as parameters to add_rewrite_endpoint
    add_rewrite_rule('^legislative-donor/?', 'index.php?legislative-donor=legislative-donor', 'top');
    // TODOs: can add more, example => add_rewrite_rule( '^legislative-donor/?', 'index.php?legislative-donor=legislative-donor', 'top' );
    add_rewrite_endpoint('legislative-donor', EP_PERMALINK);
}

function donors_query_vars($vars)
{
    if ($vars['name'] == 'legislative-donor') {
        $vars['legislative-donor'] = true;
    }

    //var_dump($vars); exit;

    return $vars;
}

function setting_donors_template($template)
{
    if (get_query_var('legislative-donor')) {
        //var_dump(get_query_var('legislative-donor')); exit;

        return locate_template('legislative-donor.php', false);
        exit;
    }

    return $template;
}

function flush_rules()
{
    global $wp_rewrite;
    $wp_rewrite->flush_rules();
}