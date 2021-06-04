<?php

require_once(ABSPATH . 'wp-content/plugins/wp-donors/includes/donors-test.inc');

function get_legislative_fund($param) {
    // do something...
    $funds = get_donors_test_array($param);
    //var_dump($funds);exit;

    $sortedArray = [
        "0 to 25" => [],
        "26 to 100" => [],
        "101 to 250" => [],
        "251 to 500" => [],
        "501 to 1000" => [],
        "1001 to 2000" => [],
        "over 2000" => []
    ];

    $legislative = $funds["Legislative Advocacy Fund"];
    //var_dump($legislative); exit;

    foreach ($legislative as $rec) {

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

    $sortedArray = remove_duplicate_names($sortedArray);

    // TESTING
    //var_dump($sortedArray); exit;

    return $sortedArray;
}

// Helper function that finds and removes duplicate donor names within the same category
function remove_duplicate_names($sortedArray) {

    $refactoredArray = [];

    $categories = [
        "0 to 25",
        "26 to 100",
        "101 to 250",
        "251 to 500",
        "501 to 1000",
        "1001 to 2000",
        "over 2000"
    ];

    $index = 0;

    foreach ($sortedArray as $category) {
        //var_dump($sortedArray); exit;
        
        $baseValues = [];
        $newCategory = [];       
        
        for ($i = 0; $i < count($category); $i++)
        {
            if (in_array($category[$i]["LastName"], $baseValues) == true) {
                //$baseValues[] = $category[$i]["LastName"];
                array_splice($category, $i, 1);
            } else {
                $baseValues[] = $category[$i]["LastName"];
                array_push($newCategory, $category[$i]);
            }      
        }
        //var_dump($baseValues); exit;

        $refactoredArray[$categories[$index]] = $newCategory;
        //var_dump($refactoredArray);exit;

        $index++;
    }

    //var_dump($refactoredArray);

    return $refactoredArray;
}