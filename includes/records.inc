<?php

function get_donor_records($param)
{
    $api = load_api();

    // Quering for Donor information
    // $resp = $api->query("SELECT  Product2.Name,  sum(TotalPrice) FROM OrderItem WHERE Product2Id IN (SELECT Id FROM Product2 WHERE Family = 'Donation Fund') GROUP BY Product2.Name");

    // $resp = $api->query("SELECT  Product2.Name, OcdlaOrg__c, Contact__r.FirstName, Contact__r.LastName, OrderDate__c, TotalPrice FROM OrderItem WHERE Product2Id IN (SELECT Id FROM Product2 WHERE Family = 'Donation Fund') ORDER BY OrderDate__c DESC");

    // $queryString = "SELECT  Product2.Name, OcdlaOrg__c, Contact__r.FirstName, Contact__r.LastName, OrderDate__c, TotalPrice FROM OrderItem WHERE Product2Id IN (SELECT Id FROM Product2 WHERE Ocdla_Product_Serial_Number__c = 44.00) ORDER BY OrderDate__c DESC";

    $queryString = "SELECT  Product2.Name, OcdlaOrg__c, Contact__r.FirstName, Contact__r.LastName, OrderDate__c, TotalPrice FROM OrderItem WHERE Product2Id IN (SELECT Id FROM Product2 WHERE Ocdla_Product_Serial_Number__c = " . $param . ") ORDER BY OrderDate__c DESC";

    $resp = $api->query($queryString);

    if (!$resp->isSuccess()) {

        var_dump($resp);
        exit;
    }

    $records = $resp->getRecords();
    // TESTING:
    //var_dump($records);
    //exit;
    ////////////////////

    return $records;
}