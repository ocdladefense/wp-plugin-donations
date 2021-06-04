<?php

//require_once(ABSPATH . '/wp-content/plugins/wp-salesforce/wp-salesforce.php');

function get_donors_array($param)
{
    // Calling get_records() function with "donors" param to get OSDLA donors' records
    $donorRecords = get_donor_records($param);
    //var_dump($donorRecords);
    //exit;

    $formattedDonorArray = format_donors_array($donorRecords); // TO BE IMPLEMENTED
    //var_dump($formattedDonorArray); exit;


    // // Sorting in alphabetic order
    // sort($formattedDonorArray);

    // //Testing...
    // //var_dump($formattedDonorArray);
    // //exit;
    // //

    // // Calls function 'sort_members_by_role' to get a sorted array
    // $sortedByDonation = sort_donors_by_donation($formattedDonorArray);

    // return $sortedByDonation;
    return $formattedDonorArray;
}

// LEAVE AS IS FOR NOW
// This function parses an array with 'raw' data containing committee and member information
// It then takes necessary attributes and puts them into a new formatted 'human-friendly' array
function format_donors_array($donorRecords)
{
    // Add code here...
    $donorsArray = [];
    // Arry that will hold donors
    $donors = [];
    foreach ($donorRecords as $rec) {
        
        $record = array(
            "Org" => $rec["OcdlaOrg__c"],
            "FirstName" => $rec["Contact__r"]["FirstName"],
            "LastName" => $rec["Contact__r"]["LastName"],
            "Date" => $rec["OrderDate__c"],
            "Qty" => $rec["Quantity"],
            "UnitPrice" => $rec["UnitPrice"],
            "TotalPrice" => $rec["TotalPrice"],
        );  
        $donors[] = $record;
        //var_dump($donor); exit;
        
    }
    $donorsArray = $donors;
    
    /////////////////////////////
    // TESTING
    //var_dump($donorsArray); exit;
    /////////////////////////////

    return $donorsArray;
}

// This function recreates an array based on member roles and their priorities
function sort_donors_by_donation($donors)
{
    // Sorted array based on roles
    $sortedDonorsArray = [];

    foreach ($donors as $rec) {

        // An array that will hold related records based on role priorities
        $newArray = [
            "Name" => $rec["Name"],
            "members" => []
        ];

        // Define the order of roles
        // Members not assigned a role will not appear on the list
        $roles = [
            "Chair",
            "Co-chair"
        ];

        // The list of members in the order it will be displayed on the page
        $list = [];

        // Will hold members grouped by their respective roles
        $grouped = [];

        // Grouping by roles
        foreach ($rec["members"] as $member) {
            $role = $member["Role"];
            $grouped[$role][] = $member;
        }

        // Filling $list array based on the role order
        foreach ($roles as $role) {
            if ($grouped[$role] != null) {
                $list[$role] = $grouped[$role];
            }
        }

        // Calling a function that returns a flattened version of members based on their roles
        $newArray["members"] = flatten_donors_array($list, $roles);

        $sortedCommitteesArray[] = $newArray;
    }

    //var_dump($sortedCommitteesArray);
    //exit;

    return $sortedCommitteesArray;
}

// Flattening the array containing roles
function flatten_donors_array($list, $roles)
{
    $flatArray = [];
    // comparing roles in the list array against our "master" role values
    for ($i = 0; $i < 16; $i++) { // Eneter a better array length rather than hard-coding
        if ($list[$roles[$i]] != null) {
            foreach ($list[$roles[$i]] as $role) {
                array_push($flatArray, $role);
            }
        }
    }
    return $flatArray;
}