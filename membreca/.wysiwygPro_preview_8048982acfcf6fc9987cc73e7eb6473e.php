<?php
if ($_GET['randomId'] != "cKnH8M_DAKW1yg_TzLi8rrjj4Lzexd_RN2_vqohAxVLWdkU7wqmYq8HnQ_7HduPP") {
    echo "Access Denied";
    exit();
}

// display the HTML code:
echo stripslashes($_POST['wproPreviewHTML']);

?>  
