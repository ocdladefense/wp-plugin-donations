<?php

// Function that formats the array based on the funds' names
function format_donors_array_copy($donorRecords) {

    //var_dump($donorRecords); exit;

    $donorRecords = flatten_array($donorRecords);

    //var_dump($donorRecords); exit;

    $donors = [];
    
    $groupedDonors = [];

    $funds = [
        "Building Fund - Mortgage only",
        "Building Project Fund - Exterior Painting",
        "Building Project Fund - Security Camera System Update",
        "General Support Fund",
        "Legislative Advocacy Fund",
        "Library of Defense Fund",
        "Protester CLE Fund",
        "Scholarship Fund"
    ];

    //var_dump($funds);exit;

    foreach ($donorRecords as $record) {
        
        $fund = $record["Fund"];

        array_splice($record, 0, 1);

        $groupedDonors[$fund][] = $record;

        foreach ($funds as $fund) {
            if ($groupedDonors[$fund] != null) {
                $donors[$fund] = $groupedDonors[$fund];               
            }           
        }
    }

    //var_dump($donors); exit;
    
    return $donors;
}

// Helper function to further flatten an array picking only the necessary fields
function flatten_array($donorRecords) {

    $flatArray = [];

    foreach ($donorRecords as $rec) {

        $entry = [
            "Fund" => $rec["Product2"]["Name"],
            "Org" => $rec["OcdlaOrg__c"],
            "FirstName" => $rec["Contact__r"]["FirstName"],
            "LastName" => $rec["Contact__r"]["LastName"],
            "Date" => $rec["OrderDate__c"],
            "Total" => $rec["TotalPrice"]
        ];

        $flatArray[] = $entry;
    }
   
    //var_dump($flatArray); exit;

    return $flatArray;
}