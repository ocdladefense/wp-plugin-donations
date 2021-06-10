<?php

function get_donor_records($param, $startDate = "2017-01-01", $endDate = "2021-06-30")
{
    $api = load_api();

    // Quering for Donor information

    // $queryString = "SELECT  Product2.Name, OcdlaOrg__c, Contact__r.FirstName, Contact__r.LastName, OrderDate__c, TotalPrice FROM OrderItem WHERE Product2Id IN (SELECT Id FROM Product2 WHERE Ocdla_Product_Serial_Number__c = 44.00) ORDER BY OrderDate__c DESC";

    // $queryString = "SELECT  Product2.Name, OcdlaOrg__c, Contact__r.FirstName, Contact__r.LastName, OrderDate__c, TotalPrice FROM OrderItem WHERE Product2Id IN (SELECT Id FROM Product2 WHERE Ocdla_Product_Serial_Number__c = " . $param . ") ORDER BY OrderDate__c DESC";

    $queryString = "SELECT SUM(TotalPrice) Total, Contact__c, Contact__r.FirstName, Contact__r.LastName FROM OrderItem WHERE Product2Id IN (SELECT Id FROM Product2 WHERE Ocdla_Product_Serial_Number__c = $param) AND Order.EffectiveDate >= $startDate AND Order.EffectiveDate <= $endDate GROUP BY Contact__r.FirstName, Contact__r.LastName, Contact__c ORDER BY SUM(TotalPrice) DESC";

    $resp = $api->query($queryString);

    if (!$resp->isSuccess()) {

        var_dump($resp);
        exit;
    }

    return $resp->getRecords();
}