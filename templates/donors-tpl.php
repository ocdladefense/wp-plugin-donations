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

<?php $donors = get_donors(44.00); ?>
<h1 class="text-center text-muted mb-5">Legislative Advocacy</h1>
<div class="container">

    <?php
    // var_dump($donors);
    // exit;
    ?>

    <?php $keys = array_keys($donors);
    ?>

    <?php for ($i = 0; $i < count($keys); $i++) : ?>
    <table class="table table-striped mb-5">
        <tbody>

            <h3 class="mb-5"><?php print $keys[$i] ?></h3>

            <?php foreach ($donors[$keys[$i]] as $rec) : ?>

            <tr>
                <td style='color: #bf9500; font-weight: bold;'>
                    <?php //$rec["Org"] == null ? print "Private Party" : print $rec["Org"]; 
                            ?></td>
                <td style="color: #53638c; font-weight: bold;">
                    <?php ($rec["FirstName"] != NULL and $rec["LastName"] != NULL) ? print $rec["FirstName"] . " " . $rec["LastName"] : print "No names provided"; ?>
                </td>
                <td style="color: green; font-weight: bold;"><?php //print $rec["Date"]; 
                                                                        ?></td>
                <td style="font-weight: bold; color: darkorchid; text-align: center;">
                    <?php print "$ " . $rec["Total"]; ?></td>
            </tr>

            <?php //var_dump($keys);
                    //exit;
                    ?>

            <?php endforeach; ?>

        </tbody>
    </table>
    <?php endfor; ?>
</div>