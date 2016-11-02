<?php

// Config
require("../includes/config.php");

// User reaching via GET

if ($_SERVER["REQUEST_METHOD"] == "GET")
{
    render("quote_form.php", ["title" => "Get Quote"]);
    
}

// User reaching via POST
else if ($_SERVER["REQUEST_METHOD"] == "POST")
{
    $stock = lookup($_POST["symbol"]);
    
    if ($stock !== false)
    {
        // render stock info
        render("quote_form.php", ["title" => "Get Quote", "stock" => $stock]);
    }
    
    // Render error
    else
    {
        render("quote_form.php", ["title" => "Get Quote", "error" => "No stock info for this symbol. Please try again"]);
    }
}
