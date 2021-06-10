<?php

//$donors = get_donor_records(44.00);

function get_legislative_donors($param) {

    $donorRecords = get_donor_records($param);
    // var_dump($donorRecords);
    // exit;

    $sortedArray = [
        "over 2000" => [],
        "1001 to 2000" => [],
        "501 to 1000" => [],
        "251 to 500" => [],
        "101 to 250" => [],
        "26 to 100" => [],
        "0 to 25" => []
    ];

    foreach ($donorRecords as $rec) {

        if ($rec["Total"] > 0 && $rec["Total"] <= 25)
            $sortedArray["0 to 25"][] = $rec;
        elseif ($rec["Total"] > 25 && $rec["Total"] <= 100)
            $sortedArray["26 to 100"][] = $rec;
        elseif ($rec["Total"] > 100 && $rec["Total"] <= 250)
            $sortedArray["101 to 250"][] = $rec;
        elseif ($rec["Total"] > 250 && $rec["Total"] <= 500)
            $sortedArray["251 to 500"][] = $rec;
        elseif ($rec["Total"] > 500 && $rec["Total"] <= 1000)
            $sortedArray["501 to 1000"][] = $rec;
        elseif ($rec["Total"] > 100 && $rec["Total"] <= 2000)
            $sortedArray["1001 to 2000"][] = $rec;
        else {
            $sortedArray["over 2000"][] = $rec;
        }
    }

    //$sortedArray = remove_duplicate_names($sortedArray);

    // TESTING
    //var_dump($sortedArray); exit;

    return $sortedArray;
}

// function format_donors_array($donorRecords)
// {
//     $donorsArray = [];
//     // Arry that will hold donors
//     $donors = [];
//     foreach ($donorRecords as $rec) {
        
//         $record = array( 
//             "FirstName" => $rec["FirstName"],
//             "LastName" => $rec["LastName"],
//             "Contact" => $rec["Contact__c"],
//             "Total" => $rec["Total"]
//             //"Org" => $rec["OcdlaOrg__c"],
//             //"Date" => $rec["OrderDate__c"],
//         );  
//         $donors[] = $record;
//         //var_dump($donor); exit;
        
//     }
//     $donorsArray = $donors;
    
//     /////////////////////////////
//     // TESTING
//     //var_dump($donorsArray); exit;
//     /////////////////////////////

//     return $donorsArray;
// }



// // Helper function that finds and removes duplicate donor names within the same category
// function remove_duplicate_names($sortedArray) {

//     $refactoredArray = [];

//     $categories = [
//         "over 2000",
//         "1001 to 2000",
//         "501 to 1000",
//         "251 to 500",
//         "101 to 250",
//         "26 to 100",
//         "0 to 25"
//     ];

//     $index = 0;

//     foreach ($sortedArray as $category) {
//         //var_dump($sortedArray); exit;
        
//         $baseValues = [];
//         $newCategory = [];       
        
//         for ($i = 0; $i < count($category); $i++)
//         {
//             if (in_array($category[$i]["LastName"], $baseValues) == true) {
//                 //$baseValues[] = $category[$i]["LastName"];
//                 array_splice($category, $i, 1);
//             } else {
//                 $baseValues[] = $category[$i]["LastName"];
//                 array_push($newCategory, $category[$i]);
//             }      
//         }
//         //var_dump($baseValues); exit;

//         $refactoredArray[$categories[$index]] = $newCategory;
//         //var_dump($refactoredArray);exit;

//         $index++;
//     }

//     //var_dump($refactoredArray);

//     return $refactoredArray;
// }