<?php
    function table($tableName,$rown,$coln)
    {
        $str_table = "";
        $str_table .= "<table align='center' border='1' width='800'>";
        $str_table .= "<caption><h1> $tableName </h1></caption>";

        for($out=0;$out < $rown;$out++)
        {
            $bgcolor = $out % 2 == 0 ? "#FFFFFF" : "#DDDDDD";
            $str_table  .= "<tr bgcolor = ".$bgcolor.">";

            for($in=0;$in < $coln;$in++)
            {
                $str_table .= "<td>".($out*10 + $in)."</td>";
            }
            $str_table .= "</tr>";
        }
        $str_table .= "</table>";
        return $str_table;
    }
    $str = table("第一个3行4列的表",3,4);
    echo $str;    
    echo table("第二个2行10列的表",2,10);
?>
