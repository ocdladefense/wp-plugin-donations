<style type="text/css">
.table-headers {
    display: none;
}

#intro {
    font-size: 18px;
}

h1 {
    padding-left: 12px;
    text-transform: uppercase;
    letter-spacing: 0.14em;
    font-size: 1.0em;
}

h3 {
    color: #bf9500;
}

#email {
    color: rgba(0, 0, 139, 0.8);
    font-weight: bold;
}

#name {
    color: grey;
}

#city {
    color: #53638c;
    font-weight: 600;
}

p {
    word-wrap: break-word;
}

@media screen and (min-width: 800px) {
    .table-headers {
        display: table-row;
    }
}
</style>

<?php //var_dump($donors);
//exit; 
?>
<h1 class="text-center text-muted mb-5">Donors</h1>
<div class="container">
    <table class="table table-striped mb-5">
        <thead>
            <tr class="text-muted">
                <th>Donor</th>
                <th>Name</th>
                <th>Date</th>
                <th>Quantity</th>
                <th>Unit Price</th>
                <th>Total Price</th>
            </tr>
        </thead>
        <tbody>
            <?php foreach ($donors as $donor) : ?>

            <tr>
                <td style='color: #bf9500; font-weight: bold;'>
                    <?php $donor["Org"] == null ? print "Private Party" : print $donor["Org"]; ?></td>
                <td style="color: #53638c; font-weight: bold;">
                    <?php ($donor["FirstName"] != NULL and $donor["LastName"] != NULL) ? print $donor["FirstName"] . " " . $donor["LastName"] : print "No names provided"; ?>
                </td>
                <td style="color: green; font-weight: bold;"><?php print $donor["Date"]; ?></td>
                <td style="font-weight: bold; text-align: center;"><?php print $donor["Qty"]; ?></td>
                <td style="font-weight: bold; color: darkorchid; text-align: center;">
                    <?php print "$ " . $donor["UnitPrice"]; ?></td>
                <td style="font-weight: bold; color: blue; text-align: center;">
                    <?php print "$ " .  $donor["TotalPrice"]; ?>
                </td>

            </tr>
            <?php endforeach; ?>
        </tbody>
    </table>
</div>