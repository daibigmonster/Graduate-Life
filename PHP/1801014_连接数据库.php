<?php
    $host = 'localhost';
    $user = '****';//上传要记得注释用户名密码！！
    $passwd = '*****';
    $conn = mysqli_connect($host, $user, $passwd) or die('数据库连接失败');
    echo '连接成功';
    mysqli_close($conn);
?>