<?php
    $host = 'localhost';
    $user = '***';//上传要记得注释用户名密码！！
    $passwd = '***';
    $conn = mysqli_connect($host, $user, $passwd) or die('数据库连接失败');
    echo '连接成功';
    $sql = "CREATE TABLE runoob_tbl(".
    "runoob_id INT NOT NULL AUTO_INCREMENT,".
    "runoob_title VARCHAR(100) NOT NULL,".
    "runoob_author VARCHAR(40) NOT NULL,".
    "submission_data DATE,".
    "PRIMARY KEY ( runoob_id))ENGINE=InnoDB DEFAULT CHARSET=utf8; "; 
    mysqli_select_db($conn, 'test' ) or die('数据库选择失败'.mysqli_error($conn));
    $query = mysqli_query($conn,$sql) or die('数据表创建失败: ' . mysqli_error($conn));
    echo "数据表创建成功\n";
    mysqli_close($conn);
?>