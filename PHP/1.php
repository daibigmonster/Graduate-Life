<?php
    $one = 100;
    $two = 200;
    function demo()
    {
        global $one,$two;
        echo "运算结果:".($one + $two)."<br>";
    }
    demo();
    $arr = array(3,1,2,6,3,2,6);
    print_r($arr);
    echo "<br>";
    sort($arr);
    print_r($arr);